// noi import kieu thu vien , khai bao struct
#include<stdbool.h>


typedef struct{
	int day,month,years;
}Date;
typedef struct{
	char id[100];
	char classRoom[20];
	char name[100];
	char email[30];
	char phone[30];
	char gender[20];
	Date dateOfBirth;
	
}Student;
Student student[100];

int number_teacher = 0;
int number_classRoom =0;
int number_student = 0;
typedef struct{
	char classRoomID[20];
	char teacherID[20];
	char classRoomName[20];
	Student student;
}ClassRoom;
ClassRoom classRoom[100];
typedef struct{
	char teacherID[20];
	char name[20];
	char email[20];
	char phone[20];
	ClassRoom classRoom;
}Teacher;
Teacher teacher[100];
