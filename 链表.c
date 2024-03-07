/*
 ============================================================================
 Name        : 2.c
 Author      : zsx
 Version     :
 Copyright   : 2024
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//char *s_gets(char *st,int n);
struct student{
		char name[20];
		int id;
		struct student *next;
	};
typedef struct student stu;


int main (void)
{
	int i;
	const int n =3;

	//定义一个头结点，尾结点，移动节点。
	stu *p,*head,*tail,*q;
	//stu *q;
	//为p分配内存
	p =(struct student *)malloc(sizeof(struct student));
	q =(struct student *)malloc(sizeof(struct student));
	//将p都指向尾结点和头结点
	head = p;
	tail = p;
	head->next =NULL;  //此时头结点的next 为空。

	//q->name =(char)malloc(strlen(na) + 1);

	strcpy(q->name,"sdf");
	q->id = 23;
	q->next =NULL;

	//elispe中scanf 优先级高于prntf，需要此函数设置缓冲区为0.
	setvbuf(stdout,NULL,_IONBF,0);
	for(i=0;i<n;i++)
	{
		p =(struct student *)malloc(sizeof(struct student));
		//setvbuf(stdout,NULL,_IONBF,0);
		printf("请输入学生信息：");
		//fflush(stdout);
		scanf ("%s",p->name);
		printf("请输入学号：");
		//fflush(stdout);
		scanf("%d",&p->id);
 //将p的地址赋予尾结点的next
		tail->next =p;
//此时将p指向当前的尾结点
		tail = p;
//当前尾结点的next为空
		tail->next =NULL;
	}
	//遍历链表，将p指向头结点的next
	p=head->next;
	while (p!=NULL)
	{
		printf("学生姓名：%s 学生学号：%d\n",p->name,p->id);
		//fflush(stdout);
		//将下一个节点的next赋予p
		p= p->next;
	}
	//插入链表
	p =head;
	while(p!=NULL)
	{
		if(p->next->name == q->name)
		{
			q->next =p->next;
			p->next = q;
			break;
		}
		p=p->next;
	}
	//删除一个链表
	p =head;
		while(p!=NULL)
		{
			if(p->next->name == q->name)
			{
			  stu *t;
			  t= p->next;
			  p->next=p->next->next;
			  free(t);
			  break;
			}
			p=p->next;
		}
	//释放内存
    p= head->next;
    while(p!=NULL){
    	p=p->next;
    	free(p);
    }
    return 0;
}

char * s_gets(char * st,int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find =strchr(st,'\n');

		if(find)

			*find ='\0';

		else
			while(getchar()!= '\n')
				continue;

	}
	return ret_val;
}


