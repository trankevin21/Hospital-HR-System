

#include "prj.h"
#include "prjstud.h"
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void print_main_menu();





int main()
{
     char X='Q';
	int list_size;
	int ct=0;
	char buffer[100], ch;
	struct   HR_Application * listptr,  *pL;
	int app_to_be_gone, code;
	
	printf("Enter a seed to the random number generator (i.e. an integer >0)\n");
	gets(buffer);

	srand(atoi(buffer));

	
	listptr= makeInitialList(ct);

    while((X!='T') && (listptr!=NULL ))
	{
		
		print_main_menu();
		printf(">>>>> Enter a command ");

	
		gets(buffer);
	

		X=toupper(buffer[0]);
	
		switch(X)
		{
		case 'D':
//		Delete Application from list
			
			printFormatted(listptr);
			printf(">>>>> Choose an Application ID to Delete\n");
			app_to_be_gone= (int) atoi(gets(buffer));
			pL= checkForApp(listptr, app_to_be_gone);
			if(pL!=NULL)
				listptr=deleteApplication(listptr,pL);
			else
				printf("there is no application with application ID=  %d\n",app_to_be_gone);
			break;

		case 'M':
//		Process Plane movement
			listptr=processDay( listptr, &ct);
			break;

	
		case 'P':
//		Display list
			printFormatted(listptr);
			break;

		case 'Q':
//		Sort by average skill 

			listptr=sortByAvgSkill(listptr);
			break;
			

		case 'S':
//		Sort by Hospital
			listptr=sortByHospital(listptr);
			break;

	
		case 'T':
//		Terminate
			terminateAndWrite (listptr);
		
			break;

		case 'V':
//		
		
			analyzeApplicantList(listptr);
			break;

	
	
		}
    
	}


	return 1;

}


void print_main_menu()
{
	printf("*******************************************************\n");
	printf("*******************************************************\n");
	printf("                Main Menu\n");
	printf("*******************************************************\n");
	printf("\tD\t\tdelete an application from list\n");
	printf("\tM\t\ta New Day -- process applications\n");
	printf("\tP\t\tdisplay Applications\n");
	printf("\tQ\t\tsort list by average Skill\n");
	printf("\tS\t\tsort list By hospital\n");
	printf("\tT\t\tterminate.. Write data to file and free list \n");
	printf("\tV\t\tanalyze application list\n");
	printf("*******************************************************\n");
	printf("*******************************************************\n");

}
