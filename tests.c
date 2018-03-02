#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#define TYPES 50
#include "dataRead-Write.h"
typedef struct one{
  int id;
}oneTo;

typedef struct two{
  int id;
char name[TYPES];
char card[TYPES];
}twos;

void showOneData(struct Arraylist * re);
void showTwoData(struct Arraylist * re);
void close_free(struct Arraylist * obj);
int main(){
 char * filename="testd.txt";
  //char array[512];
struct Arraylist * obj=inif();
oneTo a={1},a1={2},a2={3},a3={4},a4={5},a5={6};
add(obj,&a); 
add(obj,&a1); 
add(obj,&a2); 
add(obj,&a3); 
add(obj,&a4); 
add(obj,&a5); 
obj->typesize=sizeof(oneTo);
//filew("one.table",obj); //writen

struct Arraylist * re=filer("one.table",sizeof(oneTo),2,6); //read 分页 2- 6数据
showOneData(re);

printf("pid==%d\n",getpid());
twos t1={101,"admin","哈"},t2={102,"admsin","是"},t3={103,"oud","撒"},t4={104,"kshs","ksn"},t5={105,"adn","怕"},t6={106,"admd","哦"},t7={107,"isbhs","及技术"},t8={108,"kshs","ksn"}, t9={109,"admin","哈"},t10={110,"admsin","是"},t11={111,"oud","撒"};
struct Arraylist * obj2=inif();
add(obj2,&t1); 
add(obj2,&t2); 
add(obj2,&t3); 
add(obj2,&t4); 
add(obj2,&t5); 
add(obj2,&t6); 
add(obj2,&t7); 
add(obj2,&t8); 
add(obj2,&t9); 
add(obj2,&t10); 
add(obj2,&t11); 
obj2->typesize=sizeof(twos);
//filew("two.table",obj2);

printf("%d \n",(int)sizeof(twos));
struct Arraylist * re2=filer("two.table",sizeof(twos),5,11);  
showTwoData(re2);


close_free(re);
close_free(obj);
close_free(re2);
close_free(obj2);





return 0;
}


void showOneData(struct Arraylist * re){
puts("-----one---");
oneTo * objs= getObj(re);
for(int i=0;i<re->length;i++){
  printf("one 类型id =%d\n",objs[i].id);
}

}


void showTwoData(struct Arraylist * re){
puts("-----showTwoData---");
printf("%d \n",re->length);
twos * objs= getObj(re);
for(int i=0;i<re->length;i++){
  printf("two类型id =%d--name=%s ---card=%s\n",objs[i].id,objs[i].name,objs[i].card);
}

}

void close_free(struct Arraylist * obj){

free(obj->obj);
free(obj);
}



