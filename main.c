#include <stdio.h>
#include "header.h"

/*NAME  : DHARSHANRAJ.V
  USERNAME:23026_470
  DESCRIPTION : INVERTED SEARCH
  DATE : 27/02/2024
*/


int main(int argc,char *argv[])
{
	slist_t *head=NULL;
	slist_t *up_head=NULL;

	Hash_t hash[27];
	Main_t *main;
	Sub_t *sub;
	if(argc>1)
	{
		if(read_validation(argc,argv,&head)==SUCCESS)
		{
            slist_t *temp=head;
			if(head==NULL)
			{
				printf("Info : List is empty\n");
			}
			else
			{
				while(temp)
				{
					printf("%s -> ",temp->str);
					temp=temp->link;
				}
				printf("Null\n");
			}

			printf("Info : Read and validation Success\n");
		}
		else
		{
			printf("Error : Read and validation Failure\n");
			return FAILURE;
		}
	}
	else
	{
		printf("Info : Please Pass Command Line arguments\n");
		return FAILURE;
	}
	char choice = 'y';
	int op;
    if(create_hashtable(hash,27)==FAILURE)
	{
		printf("Error : Hashtable Creation failure\n");
		return FAILURE;
	}
	while(choice == 'y' || choice == 'Y')
	{
        printf("Select your choice among following options : \n");
		printf("1.Create DATABASE\n2.Display DATABASE\n3.Update DATABASE\n4.Search\n5.Save DATABASE\n6.Exit\n");
		printf("Enter your choice \n");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
		{
			if(create_database(hash,&main,&sub,head,up_head)==SUCCESS)
			{
				printf("Info : Data base creation Successfully\n");
			}
			else
			{
				printf("Error : Data base creation failure\n");
			}
			break;
		}
	    case 2:
		{
			display(hash,27,main,sub);
			break;
		}
		case 3:
		{
			char filename[20];
			printf("Enter the filename : ");
			scanf("%s",filename);
			if(update(hash,&main,&sub,&up_head,filename,27)==SUCCESS)
			{

            slist_t *temp=up_head;
			if(up_head==NULL)
			{
				printf("Info : List is empty\n");
			}
			else
			{
				while(temp)
				{
					printf("%s -> ",temp->str);
					temp=temp->link;
				}
				printf("Null\n");
			}
				printf("Info : Database is updated\n");
			}
			else
			{
				printf("Error : Database updation Failure\n");
			}
			break;	

		}
		case 4:
		{
			char str[32];
			printf("Enter the word you want to search : ");
			scanf("%s",str);
			if(search(hash,main,sub,str,27)==FAILURE)
			{
				printf("Info : Search Word is not Present\n");
			}
			break;
		}
		case 5:
		{
			char file[20];
			printf("Enter the filename : ");
			scanf("%s",file);
			if(save_database(file,hash,27,main,sub)==SUCCESS)
			{
				printf("Info : Save the DATABASE Successfully\n");
			}
			else
			{
				printf("Error : Save DATABASE Failure\n");
			}
			break;
		}
		case 6:
		  return 0;
		
	  }
		printf("Do you want to continue ?\n");
		printf("Enter y/Y to continue and n/N to discontinue\n");
		scanf(" %c",&choice);
	}	
  return 0;
}
Status create_hashtable(Hash_t *hash,int size)
{
	for(int i=0;i<size;i++)
	{
		hash[i].index=i;
		hash[i].link=NULL;
	}
	return SUCCESS;
}
