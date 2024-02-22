#include <stdio.h>
#include "header.h"

Status display(Hash_t *hash,int size,Main_t *main,Sub_t *sub)
{

  printf("Index   Word           Filecount    Filename       Wordcount\n");
  for(int i=0;i<size;i++)
  {
       if(hash[i].link!=NULL)
	   {
		   main=hash[i].link;
           while(main)
		   {

		       printf("[%2.2d]",i);
			   printf("    %-15s",main->word);
			   printf("%-9d",main->file_count);
			   sub=main->sub_link;
			   int c=0;
			   while(sub)
			   {
				   
				   if(c==0)
				   {
				      printf("    %-15s",sub->file_name);
				      printf("%-8d\n",sub->word_count);
				   } 
				   else
				   {
					   printf("\t\t\t\t    %-15s",sub->file_name);
					   printf("%-8d\n",sub->word_count);
				   }
				   sub=sub->link;
				   c++;
			   }
			   main=main->main_link;
			   printf("\n");
		   }

	   }
  }
	
  return SUCCESS;
}

