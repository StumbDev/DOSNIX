#ifndef PROCESS_H
#define PROCESS_H

void add_task(void (*task_function)());
void task_yield();
void task_terminate();
void scheduler();

#endif // PROCESS_H
