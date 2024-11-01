#include "util.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void maiusculo(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    str[i] = toupper((unsigned char)str[i]);
  }
}