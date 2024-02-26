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

typedef struct hashtable
{
	int index;
	struct main_node *link;
}Hash_t;


typedef struct main_node
{
	int file_count;
	char word[20];
	struct sub_node *sub_link;
	struct main_node *main_link;
}Main_t;


typedef struct sub_node
{
	int word_count;
	char file_name[20];
	struct sub_node * link;
}Sub_t;


Status read_validation(int argc ,char *argv[],slist_t **head);
Status insert_last(slist_t **,char *);
Status create_hashtable(Hash_t *,int );
Status create_database(Hash_t *,Main_t **,Sub_t **,slist_t *,slist_t *);
Status display(Hash_t *,int,Main_t *,Sub_t *);
Status search(Hash_t *,Main_t *,Sub_t * ,char *,int);
Status save_database(char *,Hash_t *,int ,Main_t *,Sub_t *);

Status update(Hash_t *,Main_t **,Sub_t **,slist_t **,char *,int size);

#endif
