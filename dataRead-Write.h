#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include "Array.h"
#define DATAMAX 1024*1024
#define HARD SEEK_SET
#define END SEEK_END









struct Arraylist * filer(char * na,int typesize,int top,int index){//na:文件名，typesize: 类型多少字节，top从那index开始，index:结束

int r_id=open(na,O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
if(r_id==-1)
   return 0;

struct Arraylist *obj=inif();
int r = 0;
void* l=malloc(typesize*index);
struct list* od= obj->obj;
/*
while(read(r_id,l,sizeof(struct lias)*100)>0){
struct lias sl=l;
add(obj,&sl);
r++;
}*/


int c=lseek(r_id,typesize*top,SEEK_SET);
     printf("--> %d\n",c);

r=read(r_id,l,typesize*index);
printf("%d  %d %d \n",r/typesize,r,typesize);
addALL(obj,l,DATAMAX,r/typesize);

   if(r==-1){
    printf("clsee--> %s\n",na);
    close(r_id);
    return 0;
    }

    if(close(r_id)==-1){
     printf("clsee--> %s\n",na);
     }

 return obj;

}




void filew2(char * na,struct Arraylist *obj){
 int r_id=open(na,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
  int r=0;
 for(int i=0;i<obj->length;i++)
  r = write(r_id,getarray(obj,i),obj->typesize);
      printf("--> %d %d\n",r,obj->typesize);
    if(close(r_id)==-1){
     printf("clsee--> %s\n",na);
     }
}




void filew(char * na,struct Arraylist * obj){
int r_id=open(na,O_RDWR|O_APPEND,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);//读写和创建和尾部写, rw-rw-rw前线
   if(r_id==-1){
    filew2(na,obj);
   puts("------");
   return;
   }

  if(lseek(r_id,0,SEEK_END)==-1)
   {

    if(close(r_id)==-1){
     printf("--> %s\n",na);
     }

    return;
    }
      int r =0;
   for(int i=0;i<obj->length;i++)
   r = write(r_id,getarray(obj,i),obj->typesize);

     printf("-->%d %d %d\n",r,obj->typesize,obj->length);

    if(close(r_id)==-1){
     printf("clsee--> %s\n",na);
     }

}

