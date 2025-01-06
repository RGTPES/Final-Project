#include <stdio.h>
#include <stdlib.h>
#include "function.h"



// mat khau la 1111 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main() {
    int choice;
    loadStudent();
    loadTeacher();
    loadClassRoom();
    do {
        clearScreen();
        menuRoll();
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:	
            	AdminManage();   	
                break;	         
            case 0:
                printf("thoat chuong trinh\n");
                break;
            default:
                printf("nhap sai moi nhap lai\n");
        }
    } while (choice != 0);
    saveStudent();
    return 0;
}
