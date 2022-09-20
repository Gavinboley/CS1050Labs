#include <stdio.h>
#include "university.h"
#include <string.h>

/*****************************************************************************
 * gzbkxc
 * Gavin Boley
 * 12/3/2021
 * Lab 13
 * CS1050
 *
 *****************************************************************************/

// Stubs for functions you need to implement
Course GetCourseByDeptAndNumber(char * dept, int number)
{
    Course * courses = GetAllCourses();
    for(;courses->id != -1; courses++)
        {
                if(!strcmp(courses->dept,dept) && (courses->number == number))
                {
                        return *courses;
                }
        }
    Course course={-1};
    return course;

}

Course GetCourseByID(COURSE_ID id)
{
    Course * courses = GetAllCourses();
    for(;courses->id != -1; courses++)
	{
		if(courses->id == id)
		{
			return *courses;
		}
	}
    Course course={-1};
    return course;
}

void PrintCourse(Course course)
{
	if(course.id != -1)
	{
		printf("ID: %d Name: %s, Department: %s, Number: %d, Instructor: %s %s\n", course.id, course.name, course.dept, course.number, course.instructor_fname, course.instructor_lname);
	}
}


//////////////////////////////////////////////////////////////
// Stubs for bonus functions you may choose to implement
Student * GetStudentsByLastName(char * lname)
{
    Student * students = GetAllStudents();
    Student theStudents[500];
    int g = 0;
    while(g<500)
	{
		theStudents[g].number = -1;
		g++;
	}
    int stucount = 0;
    for(;students->number != -1; students++)
        {
                if(!strcmp(students->lname,lname))
                {
			theStudents[stucount] = *students;
                        stucount++;
                }
        }
   Student * beginningPerson = &theStudents[0];
   return beginningPerson;

}

// For Honors students, you must also implement this function if you want bonus points
Student * GetStudentsByFirstAndLastName(char * fname, char * lname)
{
    return NULL;
}
/////////////////////////////////////////////////////////////////



// main() - Don't change this
int main(int argc, char * argv[])
{
    Course c;

    printf("Test #1:\n");
    c=GetCourseByID(5);
    PrintCourse(c);

    printf("\nTest #2:\n");
    c=GetCourseByID(11);
    PrintCourse(c);

    printf("\nTest #3:\n");
    c=GetCourseByID(999);
    PrintCourse(c);

    printf("\nTest #4:\n");
    c=GetCourseByDeptAndNumber("CS",1050);
    PrintCourse(c);

    printf("\nTest #5:\n");
    c=GetCourseByDeptAndNumber("STAT",4540);
    PrintCourse(c);

    printf("\nTest #6:\n");
    c=GetCourseByDeptAndNumber("ZZZZZZZZ",1050);
    PrintCourse(c);

    printf("\nTest #7:\n");
    c=GetCourseByDeptAndNumber("CS",999999);
    PrintCourse(c);

    /////////////////////////////
    // OPTIONAL BONUS TESTS
    /////////////////////////////
    Student * s;
    printf("\nTest #8:\n");
    s=GetStudentsByLastName("Ries");
    PrintStudents(s);

    printf("\nTest #9:\n");
    s=GetStudentsByLastName("Walkenhorst");
    PrintStudents(s);

    printf("\nTest #10:\n");
    s=GetStudentsByLastName("ZZZZZZZZZZZ");
    PrintStudents(s);

    printf("\nTest #11:\n");
    s=GetStudentsByFirstAndLastName("Charlotte","Ries");
    PrintStudents(s);
    /////////////////////////////
    /////////////////////////////

    return 0;
}
