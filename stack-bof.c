#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[0x10];

void win(){
  system("/bin/sh");
}

void vuln(){
  char pass[0x10];
  printf("password :\n");
  fflush(stdin);
  gets(pass);
  if (strncmp(pass, password, 0x10) == 0){
    printf("ACCESS GRANTED\n");
    win();
  } else{
    printf("password does not match\n");
  }
}

void init(){
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  int fd = open("/dev/urandom");
  if (fd < 0){
    printf("Aborting\n");
    exit(0);
  } else {
    read(fd, password, 0x10);
  }
}

int main() {
  init();
  vuln();
  return 0;
}
