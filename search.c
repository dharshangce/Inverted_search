#include <stdio.h>
#include "header.h"
#include <ctype.h>
#include <string.h>


Status search(Hash_t *hash,Main_t *main,Sub_t *sub,char *str,int size)
{
    
   int pos=toupper(str[0])%65;
   if(pos>26)
   {
	   return FAILURE;
   }
   if(hash[pos].link==NULL)
   {
	   return FAILURE;
   }
   else
   {
	   Main_t *temp_main=hash[pos].link;
	   while(temp_main)
	   {
		   if(strcmp(temp_main->word,str)==0)
		   {
			   printf("Info : word %s is present in %d file/s\n",str,temp_main->file_count);
			   Sub_t *temp_sub=temp_main->sub_link;
			   while(temp_sub)
			   {
				   printf("Info : In file : %s %d time/s \n",temp_sub->file_name,temp_sub->word_count);
				   temp_sub=temp_sub->link;
			   }
			   return SUCCESS;

		   }
		   temp_main=temp_main->main_link;
	   }
   }
	
  return FAILURE;
}

