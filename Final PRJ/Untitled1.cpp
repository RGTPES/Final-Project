#include<stdio.h>
bool validateStudentID(Student *newStudent) {
    if (strlen(newStudent->id) == 0) {
        printf("ID khong duoc de trong.\n");
        return false;
    }
    for (int i = 0; i < number_student; i++) {
        if (strcmp(newStudent->id, student[i].id) == 0) {
            printf("ID da ton tai.\n");
            return false;
        }
    }
    return true;
}

bool validateStudentName(Student *newStudent) {
    if (strlen(newStudent->name) == 0) {
        printf("Ten khong duoc de trong.\n");
        return false;
    }
    return true;
}

bool validateStudentPhone(Student *newStudent) {
    if (strlen(newStudent->phone) == 0) {
        printf("So dien thoai khong duoc de trong.\n");
        return false;
    }
    for (int i = 0; i < strlen(newStudent->phone); i++) {
        if (!isdigit(newStudent->phone[i])) {
            printf("So dien thoai phai la so.\n");
            return false;
        }
    }
    if (strlen(newStudent->phone) < 10 || strlen(newStudent->phone) > 15) {
        printf("So dien thoai phai tu 10 den 15 so.\n");
        return false;
    }
    for (int i = 0; i < number_student; i++) {
        if (strcmp(newStudent->phone, student[i].phone) == 0) {
            printf("So dien thoai da ton tai.\n");
            return false;
        }
    }
    return true;
}

bool validateStudentEmail(Student *newStudent) {
    if (strlen(newStudent->email) == 0) {
        printf("Email khong duoc de trong.\n");
        return false;
    }
    if (strchr(newStudent->email, '@') == NULL || strchr(newStudent->email, '.') == NULL) {
        printf("Email khong hop le.\n");
        return false;
    }
    for (int i = 0; i < number_student; i++) {
        if (strcmp(newStudent->email, student[i].email) == 0) {
            printf("Email da ton tai.\n");
            return false;
        }
    }
    return true;
}

bool validateStudentClassRoom(Student *newStudent) {
    if (strlen(newStudent->classRoom) == 0) {
        printf("Lop hoc khong duoc de trong.\n");
        return false;
    }
    return true;
}

bool validateStudentGender(Student *newStudent) {
    if (strlen(newStudent->gender) == 0) {
        printf("Gioi tinh khong duoc de trong.\n");
        return false;
    }
    return true;
}

bool validateStudentBirthday(Student *newStudent) {
    if (newStudent->dateOfBirth.day <= 0 || newStudent->dateOfBirth.month <= 0 || newStudent->dateOfBirth.year <= 0) {
        printf("Ngay sinh khong hop le.\n");
        return false;
    }
    return true;
}
int main(){




return 0;

}

