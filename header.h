#ifndef HEADER_H
#define HEADER_H


typedef enum
{
   SUCCESS ,
   FAILURE
}Status;

typedef struct node
{
	char str[50];
	struct node *link;
}slist_t;


Status read_validation(int argc ,char *argv[],slist_t **head);
Status insert_last(slist_t **,char *);

#endif
