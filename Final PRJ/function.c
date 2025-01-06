// trien khai ham
#include <unistd.h>
#include<stdio.h>
#include"datatype.h"
#include <conio.h>
#include<ctype.h>
void searchStudent() {
    char searchName[20];
    printf("nhap ten sinh vien: ");
    scanf("%s", searchName);
    int found = 0;
    printf("**** All Student ****\n");
    printf("+----+---------------------+-------------+---------+----------------------+-------------+----------+\n");
    printf("| ID | Name                | Date        | Gender  | Email                | Phone       | ClassRoom |\n");
    printf("+----+---------------------+-------------+---------+----------------------+-------------+----------+\n");

    for (int i = 0; i < number_student; i++) {
        if (strstr(student[i].name, searchName) != NULL) {
       printf("| %-2s | %-19s | %02d/%02d/%4d  | %-7s | %-20s | %-11s | %-8s |\n",
               student[i].id,
               student[i].name,
               student[i].dateOfBirth.day,
               student[i].dateOfBirth.month,
               student[i].dateOfBirth.years,
               student[i].gender,
               student[i].email,
               student[i].phone,
               student[i].classRoom);
               
            found = 1;
        }
    }
    
    printf("+----+---------------------+-------------+---------+----------------------+-------------+----------+\n");

    if (!found) {
        printf("khong tim thay sinh vien '%s'\n", searchName);
    }
}
void searchTeacher() {
    char searchName[20];
    printf("nhap ten giao vien: ");
    scanf("%s", searchName);
    int found = 0;
    printf("**** All Teacher ****\n");
    printf("+----+---------------------+---------------------+-------------+\n");
    printf("| ID | name                | Email               | phone       |\n");
    printf("+----+---------------------+---------------------+-------------+\n");

    for (int i = 0; i < number_student; i++) {
        if (strstr(teacher[i].name, searchName) != NULL) {
printf("| %-3s |%-19s | %-19s | %-11s |\n",
               teacher[i].teacherID,
               teacher[i].name,
               teacher[i].email,
               teacher[i].phone);
               
               
            found = 1;
        }
    }
    
  printf("+----+---------------------+---------------------+-------------+------------+\n");

    if (!found) {
        printf("khong tim thay giao vien '%s'\n", searchName);
    }
}
bool loginadmin() {
    char password[100] = {0};
    char c;
    int index = 0;
    FILE *file;
    char passadmin[100] = {0};
    file = fopen("admin.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        return false;
    }
    if (fgets(passadmin, sizeof(passadmin), file) == NULL) {
        perror("Loi khi doc file");
        fclose(file);
        return false;
    }
    fclose(file);
    passadmin[strcspn(passadmin, "\n")] = '\0';

    printf("Nhap mat khau: ");
    do {
        c = getch();
        if (c != 13&&c !=8) { 
            printf("*");
            if (index < sizeof(password) - 1) {
                password[index++] = c;
            }
        }
    } while (c != 13);
    password[index] = '\0'; 
    if (strcmp(password, passadmin) == 0) {
    
        return true;
    } else {
   
        return false;
    }
}
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
void menuRoll(){
	printf("\n***Student Management System Using C***\n");
	printf("CHOSSE YOUR ROLE\n");
	printf("[1] Admin.\n");
	printf("[0] Exit The Program.\n" );
	printf("Enter the Choice : ");
}
void menuAdmin(){
	int choice;
	printf("\n***Student Management System Using C***\n");
	printf("[1] Student Management.\n");
	printf("[2] Classroom Management.\n");
	printf("[3] Teacher Management.\n");
	printf("[0] Exit Program.\n");
	printf("Enter the Choice : ");
	
}
void menuStudent(){
printf("\n***Student Management System Using C***\n");
printf("[1] Add A New Student.\n");
printf("[2] Show All Student. \n");
printf("[3] Search A Student. \n");
printf("[4] Edit A Student. \n");
printf("[5] Delete A Student. \n");
printf("[6] Sort Student.\n");
printf("[0] Exit The Program.\n");
printf("Enter the Choice : ");
}

void menuClassRoom() {
	printf("\n***ClassRoom Management System Using C***\n");
	printf("[1] Add New ClassRoom.\n");
	printf("[2] Show All ClassRoom.\n");
	printf("[3] Delete ClassRoom.\n");
	printf("[0] Exit the Program.\n");
	printf("Enter the Choice : ");
}
void loadClassRoom() {
    FILE *file = fopen("classroom.bin", "rb");
    if (file != NULL) {
        fread(&number_classRoom, sizeof(int), 1, file);
        fread(classRoom, sizeof(ClassRoom), number_classRoom, file);
        fclose(file);
    }
}
void saveClassRoom() {
    FILE *file = fopen("classroom.bin", "wb");
    fwrite(&number_classRoom, sizeof(int), 1, file);
    fwrite(classRoom, sizeof(ClassRoom), number_classRoom, file);
    fclose(file);
}
void loadStudent() {
    FILE *file = fopen("student.bin", "rb");
    if (file != NULL) {
        fread(&number_student, sizeof(int), 1, file);
        fread(student, sizeof(Student), number_student, file);
        fclose(file);
    }
}
void loadTeacher() {
    FILE *file = fopen("teacher.bin", "rb");
    if (file != NULL) {
        fread(&number_teacher, sizeof(int), 1, file);
        fread(teacher, sizeof(Teacher), number_teacher, file);
        fclose(file);
    }
}
void saveTeacher() {
    FILE *file = fopen("teacher.bin", "wb");
    fwrite(&number_teacher, sizeof(int), 1, file);
    fwrite(teacher, sizeof(Teacher), number_teacher, file);
    fclose(file);
}
void saveStudent() {
    FILE *file = fopen("student.bin", "wb");
    fwrite(&number_student, sizeof(int), 1, file);
    fwrite(student, sizeof(Student), number_student, file);
    fclose(file);
}
void printStudent() {
    printf("**** All Student ****\n");
    printf("+----+---------------------+-------------+---------+----------------------+-------------+----------+\n");
    printf("| ID | Name                | Date        | Gender  | Email               | Phone       | ClassRoom |\n");
    printf("+----+---------------------+-------------+---------+----------------------+-------------+----------+\n");
    
    for (int i = 0; i < number_student; i++) {
        printf("| %-2s | %-19s | %02d/%02d/%4d  | %-7s | %-20s | %-11s | %-8s |\n",
               student[i].id,
               student[i].name,
               student[i].dateOfBirth.day,
               student[i].dateOfBirth.month,
               student[i].dateOfBirth.years,
               student[i].gender,
               student[i].email,
               student[i].phone,
               student[i].classRoom);
    }
    
    printf("+----+---------------------+-------------+---------+----------------------+-------------+----------+\n");
}

void printTeacher() {
    printf("**** All Teacher ****\n");
    printf("+----+---------------------+---------------------+-------------+\n");
    printf("| ID | name                | Email               | phone       |\n");
    printf("+----+---------------------+---------------------+-------------+\n");
    
    for (int i = 0; i < number_teacher; i++) {
        printf("| %-3s |%-19s | %-19s | %-11s |\n",
               teacher[i].teacherID,
               teacher[i].name,
               teacher[i].email,
               teacher[i].phone);
               
    }
    
    printf("+----+---------------------+---------------------+-------------+\n");
}
void printClassRoom() {
	printf("**** All Class ****\n");
    printf("+----+---------------------+\n");
    printf("| ID | name                |\n");
    printf("+----+---------------------+\n");
    
    for(int i =0;i<number_classRoom;i++){
    	printf("| %-3s| %-19s |\n",
    		classRoom[i].classRoomID,
    		classRoom[i].classRoomName);
	}
	 printf("+----+---------------------+\n");	
}
bool validateTeacherID(Teacher *newTeacher) {
    if (strlen(newTeacher->teacherID) == 0) {
        printf("ID khong duoc de trong\n");
        return false;
    }
    for (int i = 0; i < number_teacher; i++) {  
        if (strcmp(newTeacher->teacherID, teacher[i].teacherID) == 0) {
            printf("ID da ton tai\n");
            return false;
        }
    }
    return true;
}

bool validateTeacherName(Teacher *newTeacher) {
    if (strlen(newTeacher->name) == 0) {
        printf("Ten khong duoc de trong\n");
        return false;
    }
    return true;
}

bool validateTeacherPhone(Teacher *newTeacher) {
    if (strlen(newTeacher->phone) == 0) {
        printf("So dien thoai khong duoc de trong\n");
        return false;
    }
    for (int i = 0; i < strlen(newTeacher->phone); i++) {
        if (!isdigit(newTeacher->phone[i])) {
            printf("So dien thoai phai la so\n");
            return false;
        }
    }
    if (strlen(newTeacher->phone) < 10 || strlen(newTeacher->phone) > 11) {
        printf("So dien thoai phai tu 10 den 11 so\n");
        return false;
    }
    for (int i = 0; i < number_teacher; i++) {
        if (strcmp(newTeacher->phone, teacher[i].phone) == 0) {
            printf("So dien thoai da ton tai\n");
            return false;
        }
    }
    return true;
}

bool validateTeacherEmail(Teacher *newTeacher) {
    if (strlen(newTeacher->email) == 0) {
        printf("Email khong duoc de trong\n");
        return false;
    }
    if (strchr(newTeacher->email, '@') == NULL || strchr(newTeacher->email, '.') == NULL) {
        printf("Email khong hop le\n");
        return false;
    }
    for (int i = 0; i < number_teacher; i++) {
        if (strcmp(newTeacher->email, teacher[i].email) == 0) {
            printf("Email da ton tai\n");
            return false;
        }
    }
    return true;
}
bool validateStudentID(Student *newStudent) {
    if (strlen(newStudent->id) == 0) {
        printf("ID khong duoc de trong\n");
        return false;
    }
    for (int i = 0; i < number_student; i++) {  
        if (strcmp(newStudent->id, student[i].id) == 0) {
            printf("ID da ton tai\n");
            return false;
        }
    }
    return true;
}


bool validateStudentName(Student *newStudent) {
    if (strlen(newStudent->name) == 0) {
        printf("Ten khong duoc de trong\n");
        return false;
    }
    return true;
}

bool validateStudentPhone(Student *newStudent) {
    if (strlen(newStudent->phone) == 0) {
        printf("So dien thoai khong duoc de trong\n");
        return false;
    }
    for (int i = 0; i < strlen(newStudent->phone); i++) {
        if (!isdigit(newStudent->phone[i])) {
            printf("So dien thoai phai la so\n");
            return false;
        }
    }
    if (strlen(newStudent->phone) < 10 || strlen(newStudent->phone) > 11) {
        printf("So dien thoai phai tu 10 den 11 so\n");
        return false;
    }
    for (int i = 0; i < number_student; i++) {
        if (strcmp(newStudent->phone, student[i].phone) == 0) {
            printf("So dien thoai da ton tai\n");
            return false;
        }
    }
    return true;
}

bool validateStudentEmail(Student *newStudent) {
    if (strlen(newStudent->email) == 0) {
        printf("Email khong duoc de trong\n");
        return false;
    }
    if (strchr(newStudent->email, '@') == NULL || strchr(newStudent->email, '.') == NULL) {
        printf("Email khong hop le\n");
        return false;
    }
    for (int i = 0; i < number_student; i++) {
        if (strcmp(newStudent->email, student[i].email) == 0) {
            printf("Email da ton tai\n");
            return false;
        }
    }
    return true;
}

bool validateStudentClassRoom(Student *newStudent) {
    if (strlen(newStudent->classRoom) == 0) {
        printf("Lop hoc khong duoc de trong\n");
        return false;
    }
    for (int i = 0; i < number_classRoom; i++) {
        if (strcmp(newStudent->classRoom, classRoom[i].classRoomID) == 0) {
            return true;
        }
    }
    printf("Khong tim thay lop hoc ");
    return false;
}
 


bool validateStudentGender(Student *newStudent) {
    if (strlen(newStudent->gender) == 0) {
        printf("Gioi tinh khong duoc de trong\n");
        return false;
    }
    return true;
}

bool validateStudentBirthday(Student *newStudent) {
    if (newStudent->dateOfBirth.day <= 0 || newStudent->dateOfBirth.month <= 0 || newStudent->dateOfBirth.years <= 0) {
        printf("Ngay sinh khong hop le\n");
        return false;
    }
    return true;
}
bool validateClassRoomID(ClassRoom *newClassRoom) {
	for(int i =0;i<number_classRoom;i++){
			if(strcmp(newClassRoom->classRoomID,classRoom[i].classRoomID)==0){
				printf("da ton tai lop\n");
				return false;
			}
	}
	if(strlen(newClassRoom->classRoomID)==0){
		printf("ID lop ko duoc de trong\n");
		return false;
	}
	return true;
}
bool validateClassRoomName(ClassRoom *newClassRoom) {
		for(int i =0;i<number_classRoom;i++){
			if(strcmp(newClassRoom->classRoomName,classRoom[i].classRoomName)==0){
				printf("da ton tai ten lop\n");
				return false;
			}
	}
	if(strlen(newClassRoom->classRoomName)==0){
		printf("ten lop ko duoc de trong\n");
		return false;
	}
	return true;
}
void addTeacher() {
    fflush(stdin);
   Teacher newTeacher;

    do {
        printf("Nhap teacher ID: ");
        fgets(newTeacher.teacherID, 50, stdin);
        newTeacher.teacherID[strcspn(newTeacher.teacherID, "\n")] = '\0';
    } while (!validateTeacherID(&newTeacher));

    do {
        printf("Nhap teacher name: ");
        fgets(newTeacher.name, 50, stdin);
        newTeacher.name[strcspn(newTeacher.name, "\n")] = '\0';
    } while (!validateTeacherName(&newTeacher));
 
    do {
        printf("Nhap teacher phone: ");
        fgets(newTeacher.phone, 12, stdin);
        newTeacher.phone[strcspn(newTeacher.phone, "\n")] = '\0';
    } while (!validateTeacherPhone(&newTeacher));

    do {
        printf("Nhap teacher email: ");
        fgets(newTeacher.email, 50, stdin);
        newTeacher.email[strcspn(newTeacher.email, "\n")] = '\0';
    } while (!validateTeacherEmail(&newTeacher));

   teacher[number_teacher++] = newTeacher;
    saveTeacher();
    printf("Them Giao vien thanh cong.\n");
}
void addStudent() {
    fflush(stdin);
    Student newStudent;

    do {
        printf("Nhap student ID: ");
        fgets(newStudent.id, 50, stdin);
        newStudent.id[strcspn(newStudent.id, "\n")] = '\0';
    } while (!validateStudentID(&newStudent));

    do {
        printf("Nhap student name: ");
        fgets(newStudent.name, 50, stdin);
        newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    } while (!validateStudentName(&newStudent));

    do {
        printf("Nhap student classroom: ");
        fgets(newStudent.classRoom, 50, stdin);
        newStudent.classRoom[strcspn(newStudent.classRoom, "\n")] = '\0';
    } while (!validateStudentClassRoom(&newStudent));

    do {
        printf("Nhap student phone: ");
        fgets(newStudent.phone, 12, stdin);
        newStudent.phone[strcspn(newStudent.phone, "\n")] = '\0';
    } while (!validateStudentPhone(&newStudent));

    do {
        printf("Nhap student email: ");
        fgets(newStudent.email, 50, stdin);
        newStudent.email[strcspn(newStudent.email, "\n")] = '\0';
    } while (!validateStudentEmail(&newStudent));

    do {
        printf("Nhap student gender: ");
        fgets(newStudent.gender, 50, stdin);
        newStudent.gender[strcspn(newStudent.gender, "\n")] = '\0';
    } while (!validateStudentGender(&newStudent));

    do {
        printf("Nhap student birthday\n");
        printf("Day: ");
        scanf("%d", &newStudent.dateOfBirth.day);
        printf("Month: ");
        scanf("%d", &newStudent.dateOfBirth.month);
        printf("Year: ");
        scanf("%d", &newStudent.dateOfBirth.years);
        getchar();
    } while (!validateStudentBirthday(&newStudent));

    student[number_student++] = newStudent;
    saveStudent();
    printf("Them sinh vien thanh cong\n");
}
void addClassRoom() {
	fflush(stdin);
	ClassRoom newClassRoom;
	do{
			printf("Nhap ID classRoom\n");
	fgets(newClassRoom.classRoomID,50,stdin);
	newClassRoom.classRoomID[strcspn(newClassRoom.classRoomID, "\n")] = '\0';
	}while(!validateClassRoomID(&newClassRoom));

	do{
			printf("Nhap Name classRoom\n");
	fgets(newClassRoom.classRoomName,50,stdin);
	newClassRoom.classRoomName[strcspn(newClassRoom.classRoomName, "\n")] = '\0';
	}while(!validateClassRoomName(&newClassRoom));

	classRoom[number_classRoom++] = newClassRoom;
	saveClassRoom();
	printf("them lop thanh cong");
}

void editStudent(){
	char checkID[20];
	int flag=-1;
	printf("Moi ban nhap id : ");
	scanf("%s",&checkID);
	
	
	for(int i =0;i<number_student;i++){
		
	 if (strcmp(checkID, student[i].id) == 0){
		flag=1;
		if(flag==1){
		fflush(stdin);
			printf("Moi ban nhap lai thong tin sinh vien \n");
			printf("Nhap student name: ");
			fgets(&student[i].name,sizeof(student[i].name),stdin);
			student[i].name[strcspn(student[i].name,"\n")]='\0';
			printf("Nhap student classRoom: ");
			scanf("%s",&student[i].classRoom);
			student[i].classRoom[strcspn(student[i].classRoom,"\n")]='\0';
			printf("Nhap student phone: ");
      		scanf("%s",&student[i].phone);
      		student[i].phone[strcspn(student[i].phone,"\n")]='\0';
      		printf("Nhap student email: ");
     		scanf("%s",&student[i].email);
     		printf("Nhap student birthday\n");
     		printf("Day: ");
      		scanf("%d",&student[i].dateOfBirth.day);
      		printf("Month: ");
      	 	scanf("%d",&student[i].dateOfBirth.month);
     	 	printf("Years: ");
     	 	scanf("%d",&student[i].dateOfBirth.years);
     	 	printf("thay doi thong tin sinh vien thanh cong");
     	 	saveStudent();
			 break; 
      }
     
		}
		printf("sai id sinh vien");
	}
}
void editTeacher(){
	char checkID[20];
	int flag=-1;
	printf("Moi ban nhap id : ");
	scanf("%s",&checkID);
	
	
	for(int i =0;i<number_teacher;i++){
		
	 if (strcmp(checkID, teacher[i].teacherID) == 0){
		flag=1;
		if(flag==1){
		fflush(stdin);
			printf("Moi ban nhap lai thong tin giao vien \n");
			printf("Nhap teacher name: ");
			fgets(&teacher[i].name,sizeof(teacher[i].name),stdin);
			teacher[i].name[strcspn(teacher[i].name,"\n")]='\0';
			printf("Nhap teacher phone: ");
      		scanf("%s",&teacher[i].phone);
      		teacher[i].phone[strcspn(teacher[i].phone,"\n")]='\0';
      		printf("Nhap teacher email: ");
     		scanf("%s",&teacher[i].email);
     	
     	 	saveTeacher();
     	 	printf("thay doi thong tin giao vien thanh cong");
			 break; 
      }
     
		}
		printf("sai id giao vien");
	}
}


void deleteStudent(){
	int choice;
		char checkID[20];
	int flag=-1;
	printf("Moi ban nhap id : ");
	scanf("%s",&checkID);
	for(int i =0;i<number_student;i++){
		
	 if (strcmp(checkID, student[i].id) == 0){
	 	printf("Co xac nhan muon xoa Sinh vien \n");
	 	printf("1(Yes)       2(No) \n");
	 	scanf("%d",&choice);
	 	if(choice==1){
	 	for (int j = i; j < number_student - 1; j++) {
               student[j] = student[j + 1];
           }
	 		
	 	number_student--;
      	saveStudent();
      	printf("Xoa sinh vien thanh cong ");	
      	return;
		 }
		 else{
		 	printf("Ban ko xoa Sinh vien");
		 	return;
		 }
		 
	 }
	 
}
printf("sai ID ");
}
void deleteTeacher(){
	int choice;
		char checkID[20];
	int flag=-1;
	printf("Moi ban nhap id : ");
	scanf("%s",&checkID);
	for(int i =0;i<number_teacher;i++){
		
	 if (strcmp(checkID, teacher[i].teacherID) == 0){
	 	printf("Co xac nhan muon xoa Giao vien \n");
	 	printf("1(Yes)       2(No) \n");
	 	scanf("%d",&choice);
	 	if(choice==1){
	 	for (int j = i; j < number_teacher - 1; j++) {
               teacher[j] = teacher[j + 1];
           }
	 		
	 	number_teacher--;
      	saveTeacher();
      	printf("Xoa giao vien thanh cong ");	
      	return;
		 }
		 else{
		 	printf("Ban ko xoa giao vien");
		 	return;
		 }
		 
	 }
	 
}
printf("sai ID ");
}
void deleteClassRoom(){
	int choice;
		char checkID[20];
	int flag=-1;
	printf("Moi ban nhap id : ");
	scanf("%s",&checkID);
	for(int i =0;i<number_classRoom;i++){
		
	 if (strcmp(checkID, classRoom[i].classRoomID) == 0){
	 	printf("Co xac nhan muon xoa lop hoc \n");
	 	printf("1(Yes)       2(No) \n");
	 	scanf("%d",&choice);
	 	if(choice==1){
	 	for (int j = i; j < number_classRoom - 1; j++) {
               classRoom[j] = classRoom[j + 1];
           }
	 		
	 	number_classRoom--;
      	saveClassRoom();
      	printf("Xoa lop hoc thanh cong ");	
      	return;
		 }
		 else{
		 	printf("Ban ko xoa lop hoc ");
		 	return;
		 }
		 
	 }
	 
}
printf("sai ID ");
}
void sortID(){
	int choice;
	printf("[1] ascending\n");
	printf("[2] descending\n");
	printf("Enter the choice : ");
	scanf("%d",&choice);
	switch(choice){
		fflush(stdin);
		case 1:
			 for (int i = 0; i < number_student - 1; i++) {
                for (int j = i + 1; j < number_student; j++) {
                    if (strcmp(student[i].id, student[j].id) > 0) {
                          Student temp = student[i];
                        student[i] = student[j];
                        student[j] = temp;
                    }
                }
            }
            printf("sap xep thanh cong");
            saveStudent();
            break;
        case 2:
			 for (int i = 0; i < number_student - 1; i++) {
                for (int j = i + 1; j < number_student; j++) {
                    if (strcmp(student[i].id, student[j].id) < 0) {
                          Student temp = student[i];
                        student[i] = student[j];
                        student[j] = temp;
                    }
                }
            }
            printf("sap xep thanh cong");
            saveStudent();
            break;   
		break;
        
	}
}

void sortStudent() {
    int choice;
    printf("Choose sorting order:\n");
    printf("[1] By ID\n");
    printf("Enter the Choice: ");
    scanf("%d", &choice);
	 clearScreen();
    switch (choice) {
        case 1:
    	    fflush(stdin);
     	   sortID();
     	   break;   
    }
}
void StudentManage() {
    int choice;
    do {
        menuStudent();
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printStudent();
                break;
              case 3:
            	searchStudent();
            	break;
            case 4:
                editStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
				sortStudent(); 	
				break;
            case 0:
                printf("Thoat\n");
                break;
            default:
                printf("moi ban nhap lai\n");
        }
    } while (choice != 0);
}
void ClassRoomManage() {
	int choice;
	do{
		menuClassRoom();
		scanf("%d",&choice);
		clearScreen();
		switch (choice){
			case 1:
				addClassRoom();
				break;	
			case 2:
				printClassRoom();
				break;
			case 3:
				deleteClassRoom();
				break;		
			case 0:
				printf("Thoat\n");
				break;	
		}
	}while(choice!=0);
}

void AdminManage() {
    int choice;
    	if(loginadmin()==false){
    		return;
		}
    do {
    
        menuAdmin();
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
            	fflush(stdin);
                StudentManage();
                break;
            case 2:
                ClassRoomManage();
                break;
            case 3:
                teacherManage();
                break;
            case 0:
                printf("thoat \n");
                break;
            default:
                printf("moi ban nhap lai\n");
        }
    } while (choice != 0);
}
  void teacherMenu(){
printf("\n***Teacher Management System Using C***\n");
printf("[1] Add A New Teacher.\n");
printf("[2] Show All Teacher. \n");
printf("[3] Search A Teacher. \n");
printf("[4] Edit A Teacher. \n");
printf("[5] Delete A Teacher. \n");
printf("[0] Exit The Program.\n");
printf("Enter the Choice : ");
}

void teacherManage(){
	int choice;
	do{
	teacherMenu();
	scanf("%d",&choice);
	clearScreen();
	switch(choice){
		case 1:
			addTeacher();
			break;
		case 2:
			printTeacher();
			break;	
		case 3:
			searchTeacher();
			break;	
		case 4:
			editTeacher();
			break;
		case 5:
			deleteTeacher();
			break;	
		case 0:
			printf("Thoat\n");
			break;		
			
	}
	}while(choice!= 0);
}


