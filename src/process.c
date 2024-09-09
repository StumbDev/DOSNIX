#include "process.h"

#define MAX_TASKS 10

typedef struct {
    void (*task_function)();
    int active;
} Task;

Task task_list[MAX_TASKS];
int current_task = 0;

void add_task(void (*task_function)()) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (!task_list[i].active) {
            task_list[i].task_function = task_function;
            task_list[i].active = 1;
            break;
        }
    }
}

void task_yield() {
    current_task = (current_task + 1) % MAX_TASKS;
    while (!task_list[current_task].active) {
        current_task = (current_task + 1) % MAX_TASKS;
    }
    task_list[current_task].task_function();
}

void task_terminate() {
    task_list[current_task].active = 0;
    task_yield();
}

void scheduler() {
    while (1) {
        task_list[current_task].task_function();
        task_yield();
    }
}
