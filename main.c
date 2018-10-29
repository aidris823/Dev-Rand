#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int randfile = open("/dev/random",O_RDONLY);
  
  int rand_no[10];
  int second_rand_no[10];
  //No mistakes.
  if (randfile == -1){
    return -1;
  }
  read(randfile,rand_no,10*sizeof(int));
  close(randfile);
  //Another file it'll make called "falmer"
  int second_randfile = open("falmer",O_WRONLY | O_CREAT, 0744);
  write(second_randfile,second_rand_no,10*sizeof(int));
  
  for (int i = 0; i < 10; i++){
    printf("Array 1 no. %d: %d \n",i,rand_no[i]);
    printf("Array 2 no. %d: %d \n",i,second_rand_no[i]);
  }
  return 0;
}
