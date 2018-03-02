#include <stdio.h>
#include <stdlib.h>


void * init(int size){
void * str= malloc(sizeof(size));
 if(!str){
   exit(0);
  }
return  str;
} 
