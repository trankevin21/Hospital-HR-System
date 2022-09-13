

#include "prj.h"

struct HR_Application  *sortByHospital(struct HR_Application *head);
struct HR_Application *deleteApplication  (struct HR_Application *head, struct HR_Application *to_be_gone);
struct HR_Application *processDay(struct HR_Application* head, int *clockTime);
struct HR_Application* sortByAvgSkill(struct HR_Application* head);
void printFormatted (struct HR_Application * head);
void analyzeApplicantList (struct HR_Application * head);
void terminateAndWrite  (struct HR_Application * head);

