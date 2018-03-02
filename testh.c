#include "ArrayManageHaep.h"
#include "string.h"


typedef struct user{
 int  id;
 char name[50];

}use;

extern char **environ;
int main(int argc,char *argv[]) //测试内存管理
{
 //char * c  = getenv("TEST");
   //  int r=putenv("TESTS=/c/text/tests");
  //setenv("TESTS","TESTS=/home/c/text/tests",1);
//printf("%s \n",c);
//printf("%d \n",r);

 puts("------testhaep----");

  
 Managehaep * manage=initArrayHaep();
  if(!manage)
    exit(0);


 int * id =gethaep(manage,sizeof(int));//new 
 *id=1001;
 printf("id=%d\n",*id);

 char * name=gethaep(manage,sizeof(char)*10);
 name="hello";
 printf("name=%s\n",name);	

 
 use* u=gethaep(manage,sizeof(use));
 u->id=1001;
 strcpy(u->name,"小马");
  printf("use --%d ---%s\n",(*u).id,(*u).name);
  
ManageHaep(manage); //管理回收 	


 return 0;

}

