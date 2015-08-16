#include "Help.h"
void Help::dropHelp(){
    printf("\n");
    printf("[DROP TABLE]:\n");
    printf("    To delete an existing table.\n");
    printf("[Example]:\n");
    printf("    DROP TABLE student;\n");
}

void Help::createHelp(){
    printf("\n");
    printf("[CREATE TABLE]:\n");
    printf("    To create an no existing table.\n");
    printf("[Example]:\n");
    printf("CREATE TABLE student(\n");
    printf("    s_name  char(20) PRIMARY KEY,\n");
    printf("    s_id    char(20),\n");
    printf("    s_age   int,\n");
    printf("    s_class char(20),\n");
    printf(");\n");
}

void Help::selectHelp(){
    printf("\n");
    printf("[SELECT]:\n");
    printf("    Choose to meet the conditions of the data.\n");
    printf("[Example]:\n");
    printf("    1. SELECT * FROM student;\n");
    printf("    2. SELECT  s_name , s_id FROM student WHERE s_class = 'class_one';\n");
}

void Help::insertHelp(){
    printf("\n");
    printf("[INSERT]:\n");
    printf("    Insert data into table.\n");
    printf("[Example]:\n");
    printf("    INSERT INTO student(s_name,s_id) VALUES('Han Shukai','1001');\n");
}

void Help::updateHelp(){
    printf("\n");
    printf("[UPDATE]:\n");
    printf("    Update data in the table.\n");
    printf("[Example]:\n");
    printf("    UPDATE  student SET s_class = 'class_two'\n");
    printf("    WHERE s_id = '1001' AND s_class = 'class_one';\n");
}
