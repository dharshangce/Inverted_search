#include <stdio.h>
#include "header.h"

int main(int argc,char *argv[])
{
	slist_t *head=NULL;
	if(argc>1)
	{
		if(read_validation(argc,argv,&head)==SUCCESS)
		{
			if(head==NULL)
			{
				printf("Info : List is empty\n");
			}
			else
			{
				while(head)
				{
					printf("%s -> ",head->str);
					head=head->link;
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
   

	
  return 0;
}

