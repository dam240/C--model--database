#include <stdio.h>
#include <stdlib.h>
#include "init.h"


#define MAX 20
typedef struct haepfor{
   void * value; //malloc 的 ， 
   int status; //如果没有申请堆内存，状态为0，如果申请堆内存状态为：1  
   int req_size;//申请length
   void * end; //为尾部 =value+req_size-1;
   int  use;
}Haep;




typedef struct arrayhaep{
 int len;
 int size;
 Haep * top;
  int  typesize;
}Managehaep; 




Managehaep *  initArrayHaep(){
Managehaep * array=init(sizeof(Managehaep));
array->typesize=sizeof(Haep);
array->top=NULL;
array->size=0;
array->len=0;
return array;
}




Haep * inihaep(int size,int tyep){ //防止编译不初始没赋值的int 为0
 Haep* p=malloc(size*tyep);
 if(!p)
    exit(0);

for(int i=0;i<size;i++){
 p[i].status=0;
 p[i].req_size=0;
 p[i].value=NULL;
 p[i].end=NULL;
//printf("%p --%d ---%d\n",&p[i],p[i].status,p[i].req_size);

}
 return p;
}

void free_haep(void *p){//为了区别
free(p);
}


void ManageHaep(Managehaep * q){//释放内存array

 Haep* p= q->top;
 for(int j=0;j<q->len;j++){
       if(p[j].status!=0&&p[j].req_size!=0&&p[j].use==1){
        free(p[j].value);
        p[j].end =p[j].value=NULL;
         printf("--%d--%d\n",j,p[j].req_size);
       } 
  }
  free_haep(p);
  p=NULL;
  q->top=NULL;
  free(q);
  q=NULL;
 puts("---free_haepvalue---");
}


void * gethaep(Managehaep * array,int size){
  if(!array)
      return NULL;

  if(array->size==0||array->top==NULL){
 array->top= inihaep(MAX,array->typesize);
  array->size=MAX;
  array->len=0;
   }
     
 
   if(array->len==array->size){
        array->top=realloc(array->top,array->typesize*(MAX+array->size));
        if(!array->top){
           free(array);
           array=NULL;
           exit(0);
          }
      array->size+=MAX;
      Haep *q =array->top;
      for(int  i=array->len;i<array->size;i++){
        q[i].status=1;
        q[i].req_size=0;
        q[i].value=NULL;
        q[i].end=NULL;
        printf("%p --%d ---%d\n",&q[i],q[i].status,q[i].req_size);
       }
       q=NULL;
   }
   Haep *p =array->top;
   void * obj=NULL;
   
    if(p[array->len].use==0&&p[array->len].req_size==0){
       p[array->len].value=init(size);
       if(!p[array->len].value)
          return NULL;
       
       p[array->len].req_size=size;
       p[array->len].status=1;
       p[array->len].use=1;
         }
       obj=p[array->len].value;
        array->len++;
   return  obj;
}


