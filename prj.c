

#include"prj.h"

char * hosp[6]={"IUhealth", "Eskenazi", "Riley", "Methodist", "IUhealthNorth", "Stvincent"};
char *pos[4]={"ER", "primary", "ICU", "clinic"}; 

void fillData(struct HR_Application *X, int clockTime )
{
	int i;
	int numb;
	
	static int val=1001;
	
	X->appID=val;
	val+=1+(rand()%7);
	X->appDate=clockTime;
	X->timeIn=0;
	numb=rand()%4;
	strcpy(X->positionApplied, pos[numb]);
	numb=rand()%6;
	strcpy(X->hospital, hosp[numb]);
	

	X->skillLevelENT=1+(rand()%5);
	X->skillLevelGastrointestinal=1+(rand()%5);
	X->skillLevelophthalmology =1+(rand()%5);
	X->nextApp=NULL;
}

struct HR_Application*checkForApp(struct HR_Application* head, int x){

	while(head!=NULL)
	{

		if(head->appID==x)
			break;
		head=head->nextApp;
	}

	return head;
}

struct HR_Application*makeInitialList(int clocktime)
{ 
	struct HR_Application*H;
	struct HR_Application*ptr;
	struct HR_Application*last;
	int i;


	H=(struct  HR_Application *)malloc(sizeof(struct  HR_Application ));

 fillData(H, clocktime );
 last=H;
	for(i=0;i<20;i++)
	{
		ptr=(struct  HR_Application *)malloc(sizeof(struct  HR_Application ));
        fillData(ptr, clocktime );
		last->nextApp=ptr;
		last=last->nextApp;
	}

	




	return H;
}


struct HR_Application *NewApplications(int clocktime)
{
	struct HR_Application *head;
	struct HR_Application *ptr, *prev;
	int num=3;
	int i;
	num=num+(rand()%5);
	


	head=(struct HR_Application *)malloc(sizeof(struct HR_Application));
	fillData(head, clocktime);
	prev=head;
	for(i=0; i<num-1;i++)
	{
		ptr=(struct HR_Application *)malloc(sizeof(struct HR_Application));
	    fillData(ptr, clocktime);
		prev->nextApp=ptr;
		prev=ptr;
	}


	

	return head;
}


void printApps(struct HR_Application *X)
{
	struct HR_Application *ptr;

	ptr=X;
	printf("%10s %6s  %6s   %30s %10s\n", "pointer","Date", "ID", "positionApplied", "nextApp");
	while(ptr!=NULL)
	{
		printf("%10d %6d  %6d   %30s %10d\n", ptr, ptr->appDate, ptr->appID, ptr->positionApplied, ptr->nextApp);
		ptr=ptr->nextApp;
    }
}


