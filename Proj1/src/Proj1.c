/*
 ============================================================================
 Name        : Proj1.c
 Author      : 21153
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main() {
	int n;
	printf("Number of students:\t");
	scanf("%d",&n);

	struct student{
		int rollno;
		char name[20];
		int marks;
		int attendance;
	}s[n];

	int i,j, sum=0, highest=0, lowest=1000, max_count=0, max_marks=0, present=0;
	for(i=0;i<n;i++){
		printf("Enter Roll No, Name, Marks and attendance(1 for present and 0 for absent) of student %d: \n",i+1);
		scanf("%d %s %d %d", &s[i].rollno, &s[i].name, &s[i].marks, &s[i].attendance);

	}

	for(i=0;i<n;i++){
		sum += s[i].marks;

		if(s[i].marks > highest)
			highest = s[i].marks;
		if(s[i].marks < lowest)
			lowest = s[i].marks;

		int count=0;
		for(j=i+1;j<n;j++){
			count=1;
			if(s[j].marks == s[i].marks)
				count++;
		}
		if(count > max_count){
			max_count = count;
			max_marks = s[i].marks;
		}

		if(s[i].attendance)
			present++;
	}

	sum /= present;
	printf("The avg score is : %d\n",sum);

	printf("Highest score: %d\nLowest score: %d\n", highest,lowest);

	printf("Marks scored by maximum students: %d\n",max_marks);

	printf("List of students who were absent:\n");
	for(i=0;i<n;i++){
		if(!s[i].attendance)
			printf("%d. %d %s\n", i+1, s[i].rollno, s[i].name);
	}
	return 0;
}#include <stdio.h>

int main() {
	int n;
	printf("Number of students:\t");
	scanf("%d",&n);

	struct student{
		int rollno;
		char name[20];
		int marks;
		int attendance;
	}s[n];

	int i,j, sum=0, highest=0, lowest=1000, max_count=0, max_marks=0, present=0;
	for(i=0;i<n;i++){
		printf("Enter Roll No, Name, Marks and attendance(1 for present and 0 for absent) of student %d: \n",i+1);
		scanf("%d %s %d %d", &s[i].rollno, &s[i].name, &s[i].marks, &s[i].attendance);

	}

	for(i=0;i<n;i++){
		sum += s[i].marks;

		if(s[i].marks > highest)
			highest = s[i].marks;
		if(s[i].marks < lowest)
			lowest = s[i].marks;

		int count=0;
		for(j=i+1;j<n;j++){
			count=1;
			if(s[j].marks == s[i].marks)
				count++;
		}
		if(count > max_count){
			max_count = count;
			max_marks = s[i].marks;
		}

		if(s[i].attendance)
			present++;
	}

	sum /= present;
	printf("The avg score is : %d\n",sum);

	printf("Highest score: %d\nLowest score: %d\n", highest,lowest);

	printf("Marks scored by maximum students: %d\n",max_marks);

	printf("List of students who were absent:\n");
	for(i=0;i<n;i++){
		if(!s[i].attendance)
			printf("%d. %d %s\n", i+1, s[i].rollno, s[i].name);
	}
	return 0;
}
