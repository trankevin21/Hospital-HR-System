
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _STUFF_
#define _STUFF_

struct HR_Application {
	int appID;
	int appDate;
	int timeIn;
	char positionApplied[30];
	char hospital[30];
	int skillLevelENT;   // 1 to 5 where 5 is most skilled
	int skillLevelGastrointestinal;     // 1 to 5 where 5 is most skilled
	int skillLevelophthalmology;      // 1 to 5 where 5 is most skilled
    struct HR_Application*nextApp;

};
#endif

void fillData(struct HR_Application*X, int clockTime );
void printApps(struct HR_Application*X);
struct HR_Application  *sortByAvgSkill(struct HR_Application *head);
struct HR_Application  *makeInitialList(int ct);
void fillData(struct HR_Application *node, int clockTime);
struct HR_Application*checkForApp(struct HR_Application* head, int x);
struct HR_Application* NewApplications(int clocktime);