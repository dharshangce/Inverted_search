#include <stdio.h>
#include "header.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

Status update(Hash_t *hash,Main_t **main,Sub_t **sub,slist_t **up_head,char *filename,int size)
{

	FILE *fp;
	char ch,c;
	char str[50];
	int index;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		return FAILURE;
	}
	ch=getc(fp);
	fseek(fp,-2,SEEK_END);
    c=getc(fp);
	if(*up_head!=NULL)
	{ 
		printf("Warning : Database is already Updated\n ");
		return FAILURE;
	}
	if(ch=='#' && c=='#')
	{
		fseek(fp,0,SEEK_SET);
		while(fscanf(fp,"%s",str)==1)
		{
          index=atoi(strtok(&str[1],";"));
	      if(hash[index].link==NULL)
		  {
			  Main_t *new_main=malloc(sizeof(Main_t));
			  *main=new_main;
			  hash[index].link=new_main;
			  if(new_main==NULL)
			  {
				  return FAILURE;
			  }
			  strcpy(new_main->word,strtok(NULL,";"));
			  new_main->file_count=atoi(strtok(NULL,";"));
			  new_main->sub_link=NULL;
			  new_main->main_link=NULL;
			  for(int i=0;i<new_main->file_count;i++)
			  {
				  Sub_t *new_sub=malloc(sizeof(Sub_t));
				  if(new_sub==NULL)
				  {
					  return FAILURE;
				  }
				  if(new_main->sub_link==NULL)
				  {
					  new_main->sub_link=new_sub;
					  *sub=new_sub;
				  }
				  else
				  {
					  (*sub)->link=new_sub;
					  *sub=new_sub;
				  }
				  strcpy(new_sub->file_name,strtok(NULL,";"));
				  new_sub->word_count=atoi(strtok(NULL,";"));
				  new_sub->link=NULL;
				  
              }
		  }
		   else if(hash[index].link!=NULL)
		   {
			   Main_t *temp_main=hash[index].link;
			   Main_t *prev_main=hash[index].link;
			   while(temp_main!=NULL)
			   {
				   prev_main=temp_main;
				   temp_main=temp_main->main_link;
			   }
			    Main_t *new_main=malloc(sizeof(Main_t));
				if(new_main==NULL)
				{
					return FAILURE;
				}
				prev_main->main_link=new_main;
				strcpy(new_main->word,strtok(NULL,";"));
				new_main->file_count=atoi(strtok(NULL,";"));
				new_main->sub_link=NULL;
				new_main->main_link=NULL;
				for(int i=0;i<new_main->file_count;i++)
				{
					Sub_t *new_sub = malloc(sizeof(Sub_t));
					if(new_sub==NULL)
					{
						return FAILURE;
					}
					if(new_main->sub_link==NULL)
					{
						new_main->sub_link=new_sub;
						*sub=new_sub;
					}
					else
					{
						(*sub)->link=new_sub;
						*sub=new_sub;
					}
					strcpy(new_sub->file_name,strtok(NULL,";"));
					new_sub->word_count=atoi(strtok(NULL,";"));
					new_sub->link=NULL;

				}
		   }
		}
		fclose(fp);
    for(int i=0;i<size;i++)
	{
		
		if(hash[i].link!=NULL)
		{
		   Main_t *main=hash[i].link;
			while(main)
			{
				Sub_t *sub=main->sub_link;
				while(sub)
				{
					insert_last(up_head,sub->file_name);
					sub=sub->link;
				}
				main=main->main_link;
			}

		}

	}



		return SUCCESS;
	}
	else
	{
         printf("Info : %s file is not a Backup file\n",filename);
		return FAILURE;
	}
}
	


