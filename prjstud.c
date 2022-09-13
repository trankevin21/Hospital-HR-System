/*
Program Name: Semester Project
Author's Name: Kevin Tran
Class Day & Time: Friday @ 3pm
Description: Hospital HR Manager System
*/

#include "prjstud.h"

//Prints the list sorted by Hospital
struct HR_Application* sortByHospital(struct HR_Application* head){
	struct HR_Application* ptr;
	ptr = head;
	while (ptr != NULL) {
		printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		ptr = ptr->nextApp;
	}

	ptr = head;	
	printf("\n\n\n");

	while (ptr != NULL) {
		if (strcmp(ptr->hospital, "Eskenazi") == 0) {
			printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		}
		ptr = ptr->nextApp;
	}
	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->hospital, "IUhealth") == 0) {
			printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		}
		ptr = ptr->nextApp;
	}
	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->hospital, "IUhealthNorth") == 0) {
			printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		}
		ptr = ptr->nextApp;
	}
	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->hospital, "Methodist") == 0) {
			printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		}
		ptr = ptr->nextApp;
	}
	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->hospital, "Riley") == 0) {
			printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		}
		ptr = ptr->nextApp;
	}
	ptr = head;
	while (ptr != NULL) {
		if (strcmp(ptr->hospital, "Stvincent") == 0) {
			printf("ID: %d Hospital: %s \n", ptr->appID, ptr->hospital);
		}
		ptr = ptr->nextApp;
	}
	
	return head;
}

//Prints the list sorted by Average Skill Level
struct HR_Application* sortByAvgSkill(struct HR_Application* head){
	int id[1000];
	double avgSkill[1000];
	int size = 0;
	struct HR_Application* ptr;
	ptr = head;

    while (ptr != NULL){
		avgSkill[size] = ((double)(ptr->skillLevelENT + ptr->skillLevelGastrointestinal + ptr->skillLevelophthalmology) / 3);
		id[size] = ptr->appID;
		size++;
		printf("ID: %d ENT: %d Gas: %d Oph: %d Hospital: %s\n", ptr->appID, ptr->skillLevelENT, ptr->skillLevelGastrointestinal, ptr->skillLevelophthalmology, ptr->hospital);
		ptr = ptr->nextApp;
    }
	int j, k, tempID;
	float tempAvg;
	for (k = 0; k < size; ++k){

		for (j = k + 1; j < size; ++j){

			if (avgSkill[k] < avgSkill[j]){
				tempAvg = avgSkill[k];
				avgSkill[k] = avgSkill[j];
				avgSkill[j] = tempAvg;

				tempID = id[k];
				id[k] = id[j];
				id[j] = tempID;
			}
		}
	}

	printf("\n\n\n");
	for (int i = 0; i < size; i++) {
		printf("ID: %d AvgSkill: %lf\n", id[i], avgSkill[i]);
	}



	return head;
}

//User inputs which application to delete from the list
struct HR_Application *deleteApplication  (struct HR_Application *head, struct HR_Application *to_be_gone){
	struct HR_Application* temp;
	struct HR_Application* ptr;
	ptr = head;
	if (ptr == to_be_gone){
		temp = head;
		head = head->nextApp;
		free(temp);
	}else{
		while (ptr != NULL){
			temp = ptr;

			if (temp->nextApp == to_be_gone){
				temp = ptr->nextApp;
				ptr->nextApp = ptr->nextApp->nextApp;
				free(temp);
				printf("Successfully Deleted!");
				break;
			}else{
				ptr = ptr->nextApp;
			}
		}
	}

	return head;
}

//Manges the timeIn increments. Determines which applicant to hire for a specific job and deletes it
struct HR_Application *processDay(struct HR_Application* head, int *clockTime){
	struct HR_Application* ptr;
	struct HR_Application* ptr2 = NULL;
	int spotER = 1;
	int hiredER_ID;
	int spotPrimary = 1;
	int hiredPrimary_ID;
	int spotICU = 1;
	int hiredICU_ID;
	int spotClinic = 1;
	int hiredClinic_ID;
	int unit = 5;

	ptr = head;

	while (ptr != NULL) {
		ptr->timeIn += 1;
		ptr = ptr->nextApp;
	}

	ptr = head;
	ptr2 = NewApplications(clockTime);
	joining(ptr, ptr2);

	
	while (ptr != NULL){

		if (ptr->timeIn >= unit){
			ptr = deleteApplication(ptr, &ptr->appID);
		}

		if ((strcmp(ptr->positionApplied, "ER") == 0) && (spotER == 1)){
			printf("Hired ER: %d\n", ptr->appID);
			spotER--;
			hiredER_ID = &ptr->appID;
		}

		if ((strcmp(ptr->positionApplied, "primary") == 0) && (spotPrimary == 1)){
			printf("Hired Primary: %d\n", ptr->appID);
			spotPrimary--;
			hiredPrimary_ID = &ptr->appID;
		}

		if ((strcmp(ptr->positionApplied, "ICU") == 0) && (spotICU == 1)){
			printf("Hired ICU: %d\n", ptr->appID);
			spotICU--;
			hiredICU_ID = &ptr->appID;
		}

		if ((strcmp(ptr->positionApplied, "clinic") == 0) && (spotClinic == 1)){
			printf("Hired Clinic: %d\n", ptr->appID);
			spotClinic--;
			hiredClinic_ID = &ptr->appID;
		}
		ptr = ptr->nextApp;
	}

	return head;
}
int joining(struct HR_Application* a, struct HR_Application* b) {
	
	if (a != NULL && b != NULL) {

		if (a->nextApp == NULL) {
			a->nextApp = b;
		}else {
			joining(a->nextApp, b);
		}
	}
}

//Prints list in a organized and formatted manner.
void printFormatted (struct HR_Application * head){
	struct HR_Application* ptr;
	ptr = head;
	
	printf("\n%-10s%-15s%-25s%-23s%-33s%-30s\n", "appID", "hospital", "positionApplied", "skillLevelENT", "skillLevelGastrointestinal", "skillLevelophthalmology");
	int j = 0;
	while (j != 130) {
		printf("-");
		j++;
	}
	printf("\n");
	while (ptr != NULL) {
		printf("%-10d%-17s%-27s%-25d%-35d%-32d\n", ptr->appID, ptr->hospital, ptr->positionApplied, ptr->skillLevelENT, ptr->skillLevelGastrointestinal, ptr->skillLevelophthalmology);
		ptr = ptr->nextApp;
	}
	printf("\n");
}

//Counts the number of applicants for each position and determines the Average skill 
void analyzeApplicantList (struct HR_Application * head){
	struct HR_Application* ptr;
	ptr = head;

	double appER = 0;
	double entER = 0;
	double AVGentER;
	double gasER = 0;
	double AVGgasER;
	double ophER = 0; 
	double AVGophER;
	
	double appPrimary = 0;
	double entPrimary = 0;
	double AVGentPrimary;
	double gasPrimary = 0;
	double AVGgasPrimary;
	double ophPrimary = 0;
	double AVGophPrimary;

	double appICU = 0;
	double entICU = 0;
	double AVGentICU;
	double gasICU = 0;
	double AVGgasICU;
	double ophICU = 0;
	double AVGophICU;

	double appClinic = 0;
	double entClinic = 0;
	double AVGentClinic;
	double gasClinic = 0;
	double AVGgasClinic;
	double ophClinic = 0;
	double AVGophClinic;

	while (ptr != NULL) {
		if (strcmp(ptr->positionApplied, "ER") == 0) {
			appER++;
			entER = entER + ptr->skillLevelENT;
			gasER = gasER + ptr->skillLevelGastrointestinal;
			ophER = ophER + ptr->skillLevelophthalmology;
		}
		if (strcmp(ptr->positionApplied, "primary") == 0) {
			appPrimary++;
			entPrimary = entPrimary + ptr->skillLevelENT;
			gasPrimary = gasPrimary + ptr->skillLevelGastrointestinal;
			ophPrimary= ophPrimary + ptr->skillLevelophthalmology;
		}
		if (strcmp(ptr->positionApplied, "ICU") == 0) {
			appICU++;
			entICU= entICU + ptr->skillLevelENT;
			gasICU= gasICU + ptr->skillLevelGastrointestinal;
			ophICU= ophICU + ptr->skillLevelophthalmology;
		}
		if (strcmp(ptr->positionApplied, "clinic") == 0) {
			appClinic++;
			entClinic = entClinic + ptr->skillLevelENT;
			gasClinic = gasClinic + ptr->skillLevelGastrointestinal;
			ophClinic = ophClinic + ptr->skillLevelophthalmology;
		}

		ptr = ptr->nextApp;
	}


	AVGentER = entER / appER;
	AVGgasER = gasER / appER;
	AVGophER = ophER / appER;

	AVGentPrimary = entPrimary / appPrimary;
	AVGgasPrimary = gasPrimary / appPrimary;
	AVGophPrimary = ophPrimary / appPrimary;

	AVGentICU = entICU / appICU;
	AVGgasICU = gasICU / appICU;
	AVGophICU = ophICU / appICU;

	AVGentClinic = entClinic / appClinic;
	AVGgasClinic = gasClinic / appClinic;
	AVGophClinic = ophClinic / appClinic;

	printf("\n%-15s%-25s%-15s%-15s%-15s\n", "Position", "Number Application", "AVG ENT", "AVG GAS", "AVG OPH");
	int j = 0;
	while (j != 80) {
		printf("-");
		j++;
	}
	printf("\n%-15s%-25.0lf%-15.2lf%-15.2lf%-15.2lf\n", "ER", appER, AVGentER, AVGgasER, AVGophER);
	printf("%-15s%-25.0lf%-15.2lf%-15.2lf%-15.2lf\n", "primary", appPrimary, AVGentPrimary, AVGgasPrimary, AVGophPrimary);
	printf("%-15s%-25.0lf%-15.2lf%-15.2lf%-15.2lf\n", "ICU", appICU, AVGentICU, AVGgasICU, AVGophICU);
	printf("%-15s%-25.0lf%-15.2lf%-15.2lf%-15.2lf\n\n", "clinic", appClinic, AVGentClinic, AVGgasClinic, AVGophClinic);
}

//Deletes data and exits program.
void terminateAndWrite(struct HR_Application * head){
	struct HR_Application* temp;
	struct HR_Application* ptr;
	ptr = head;

	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->nextApp;
		free(temp);
	}
	printf("\nData Deleted\n");
	exit(0);

}
