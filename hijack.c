#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

int opendir(const char* path) {
  char* show;
  char* home = getenv("HOME");

  int (*new_opendir)(const char *path);
  new_opendir = dlsym(RTLD_NEXT, "opendir");
  if (!strcmp(path, ".")) {

    char cwd[64];
    getcwd(cwd, sizeof(cwd));
    show = strstr(cwd, home);

    if (!show) {
      exit(0);
    }

    return new_opendir(path);
  } 

  show = strstr(path, home);

  if (!show) {
    exit(0);
  }

  return new_opendir(path);
}
