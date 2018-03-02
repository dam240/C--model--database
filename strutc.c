#include "Array.h"
struct str{
  int id;
  char name[20];
   void (*js)(int);
 };
int main(){

struct Arraylist * list=inif();
int i1=1,i2=2,i3=3,i4=4,i5=5,i6=6,i7=7,i8=8,i9=9,i11=11,i10=10,i12=12,i13=13,i14=14,i15=15,i16=16,i17=17,i18=18,i19=19,i20=20,i21=21;
add(list,&i1);
add(list,&i2);
add(list,&i3);
add(list,&i4);
add(list,&i5);
add(list,&i6);
add(list,&i7);
add(list,&i8);
add(list,&i9);
add(list,&i10);
add(list,&i11);
add(list,&i12);
add(list,&i13);
add(list,&i14);
add(list,&i15);
add(list,&i16);
add(list,&i17);
add(list,&i18);
add(list,&i19);
add(list,&i20);
add(list,&i21);
printf("--->int\n");
for(int i=0;i<list->length;i++){
int * ic= get(list,i);
 printf("%d \n",*ic);
}

struct Arraylist * list2=inif();
add(list2,"aaa");
add(list2,"bbb");
add(list2,"ccc");
add(list2,"dd");
add(list2,"fff");
printf("--->string\n");
for(int i=0;i<list2->length;i++){
char * ic= get(list2,i);
 printf("%s\n",ic);

}

struct Arraylist * list1=inif();
struct str s1={1001,"bbbb"},s2={1002,"cccc"},s3={1003,"ddddd"},s4={1004,"uuuuu"},s5={1005,"yyyyy"},s6={1006,"44ad"},s7={1007,"kshs"},s8={1008,"kshdhs"},s9={1009,"sss"},s10={1005,"yyyyy"},s11={1021,"bbbb"},s12={10012,"cccc"},s13={1013,"ddddd"},s14={1014,"uuuuu"},s15={1015,"yyyyy"},s16={1016,"44ad"},s17={1017,"kshs"},s18={1018,"kshdhs"},s19={1019,"sss"},s20={1025,"yyyyy"},s21={1021,"tttt"},s22={1022,"ggfgsdg"},s23={1023,"cccc"},s24={1024,"iiiii"},s25={1004,"ttwtw"},s26={1005,"yyyyy"},s27={1027,"44ad"},s28={1001,"bbbb"},s29={1002,"cccc"},s30={1003,"ddddd"},s31={1031,"uuuuu"},s32={1032,"yyyyy"},s33={1033,"44ad"};
add(list1,&s1);
add(list1,&s2);
add(list1,&s3);
add(list1,&s4);
add(list1,&s5);
add(list1,&s6);
add(list1,&s7);
add(list1,&s8);
add(list1,&s9);
add(list1,&s10);
add(list1,&s11);
add(list1,&s12);
add(list1,&s13);
add(list1,&s14);
add(list1,&s15);
add(list1,&s16);
add(list1,&s17);
add(list1,&s18);
add(list1,&s19);
add(list1,&s20);
add(list1,&s21);
add(list1,&s22);
add(list1,&s23);
add(list1,&s24);
add(list1,&s25);
add(list1,&s26);
add(list1,&s27);
add(list1,&s28);
add(list1,&s29);
add(list1,&s30);
add(list1,&s31);
add(list1,&s32);
add(list1,&s33);
printf("--->str\n");
for(int i=0;i<list1->length;i++){
struct str * ic= get(list1,i);
 printf("%d %s\n",ic->id,ic->name);

}






free(list->obj);
free(list);
free(list1->obj);
free(list1);
free(list2->obj);
free(list2);


return  0;
}






