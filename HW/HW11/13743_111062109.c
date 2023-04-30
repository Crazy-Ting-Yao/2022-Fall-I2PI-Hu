#include <string.h>
#include<stdlib.h>
typedef struct {
	int grade; 
	char* name;
} Student;

Student* Create_(int n){
	Student* s= (Student*) malloc(sizeof(Student)*n);
	for(int i=0;i<n;i++){
		s[i].name = (char*)malloc(sizeof(char)*51);
	}
	return s;
}
//set value of the student's grade and name
void SetVal_(Student* arr, int i, int num, char s[]){
	arr[i].grade = num;
	strcpy(arr[i].name,s);
	return;
}
//compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student* arr, int id1, int id2){
	if(arr[id2].grade>arr[id1].grade){
		return 1;
	}
	else if(arr[id2].grade==arr[id1].grade){
		if(strcmp(arr[id2].name,arr[id1].name)>0){
			return 1;
		}
	}
	return 0;
}
//swap student 
void Swap_(Student* arr, int id1, int id2){
	Student temp;
	temp.name = (char*)malloc(sizeof(char)*51);
	temp.grade = arr[id1].grade;
	strcpy(temp.name,arr[id1].name);
	arr[id1].grade = arr[id2].grade;
	strcpy(arr[id1].name,arr[id2].name);
	arr[id2].grade=temp.grade;
	strcpy(arr[id2].name,temp.name);
	free(temp.name);
	return;
}
//free the student list 
void Free_(Student* arr, int n){
	for(int i=0;i<n;i++){
		free(arr[i].name);
	}
	free(arr);
}