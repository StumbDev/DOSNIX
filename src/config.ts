import type { Site, SocialObjects } from "./types";

export const SITE: Site = {
  website: "https://stumbdev.github.io/dosnix", // replace this with your deployed domain
  author: "StumbDev",
  profile: "https://stumbdev.github.io",
  desc: "DOSNIX is a Unix-like operating system running on top of DOS, developed in C. It aims to provide a familiar Unix environment with basic commands and functionalities, all within the constraints of a DOS system.",
  title: "DOSNIX",
  ogImage: "astropaper-og.jpg",
  lightAndDarkMode: true,
  postPerIndex: 4,
  postPerPage: 3,
  scheduledPostMargin: 15 * 60 * 1000, // 15 minutes
};

export const LOCALE = {
  lang: "en", // html lang code. Set this empty and default will be "en"
  langTag: ["en-EN"], // BCP 47 Language Tags. Set this empty [] to use the environment default
} as const;

export const LOGO_IMAGE = {
  enable: false,
  svg: true,
  width: 216,
  height: 46,
};

export const SOCIALS: SocialObjects = [
  {
    name: "Github",
    href: "https://github.com/stumbdev/dosnix",
    linkTitle: ` ${SITE.title} on Github`,
    active: true,
  },
];
