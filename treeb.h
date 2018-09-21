#include <stdio.h>
#include <stdlib.h>



// VS±àÒë   ËÑË÷Ê÷ ¾ÍÅÅĞòÊ÷£¬  

typedef struct  btree
{
	int data;
	struct	btree * ltr;
	struct	btree * rtr;
}* treem,treesd;



treem insert_seach(treem root,int data){
	treem p,q=NULL;
	p=root;
	int booleas=0;
	int  i=0;
	while (p&&(!booleas)){
		q=p;
		if(p->data==data)
			booleas=1;
		if(p->data<data){
			p=p->rtr;
		}else{
			p=p->ltr;
		}
		i++;
	}

    printf("===%d\n",i);

	if(root){
		p=(treem)malloc(sizeof( struct  btree));
		p->data=data;
		p->ltr=NULL;
		p->rtr=NULL;
		if(q->data>data){
			q->ltr=p;
			puts("int --l");
		}else{
			q->rtr=p;
		puts("int --r");

		}
		return NULL;

	}else{	  

		root=(treem)malloc(sizeof( struct  btree));
     	root->data=data;
		root->ltr=NULL;
		root->rtr=NULL;

		return  root;
	
	}	

}




void print_tree(treem root){

    	treem p=root;
		if(!p)
			return;

			print_tree(p->ltr);
			printf("--- %d \n",p->data);
			print_tree(p->rtr);
}

treem  seach_tree(treem root,int data){

	treem  p=root,q=NULL;
	int  i=0;
	while (p){
		if(p->data==data){
			printf(" ==%d \n ",i);
		return p;
		}
		if(p->data>data)
			p=p->ltr;
		else
			p=p->rtr;
		i++;
	}
	return NULL;

}





treem deletes(treem ltee,treem rtee);

//É¾³ı 

void detele(treem root,int data){
	treem p=root,q=NULL,rm=NULL;
	if(!root)
     return ;
	
	int boos=0;
	 
	while (p)
	{

		if(p->data==data){
			rm=p;
			if(q){
				treem m=deletes(p->ltr,p->rtr);

				if(q->ltr==rm)
					q->ltr=m;
				else
					q->rtr=m;

				rm->ltr=NULL;
				rm->rtr=NULL;
				//free(rm);
			//	reurn 

			}else{
				free(rm);
				return ;
				
			}

		}
		if(p->data>data){
			q=p;
			p=p->ltr;
		}else{
	     	q=p;
			p=p->rtr;
		}

	}
	free(rm);
	rm=NULL;

}


treem deletes(treem ltee,treem rtee){
	
	if(ltee){
		treem p=ltee,q=NULL;
		while (p)
		{
			 q=p;
			if(p->data>rtee->data){
				p=p->ltr;
			}else
				p=p->rtr;
		}

	 
		if(q->data>rtee->data)
			q->ltr=rtee;
		else
			q->rtr=rtee;

		return ltee;
	}else{

		return rtee;

	}



}
int   tree_depths(treem root ,int index);


int   tree_depth(treem root){


	 if(!root)
		 return 0;

	return tree_depths(root,0);

}

int   tree_depths(treem root ,int index){

	if(!root)
		return index;
	int  l=tree_depths(root->ltr,index+1);
	int  r=tree_depths(root->rtr,index+1);


	return l<=r?r:l;
}