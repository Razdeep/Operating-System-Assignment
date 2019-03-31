/**
 * @author : Rajdeep Roy Chowdhury
 * @handle : razdeep <rrajdeeproychowdhury@gmail.com>
 * 
 * ---------------
 *    TASK #05
 * ---------------
 * 
 * Question 
 * 
 * A university computer science department has a teaching assistant (TA) 
 * who helps undergraduate students with their programming assignments 
 * during regular office hours. The TA’s office is rather small and has 
 * room for only one desk with a chair and computer. There are three chairs
 * in the hallway outside the office where students can sit and wait if 
 * the TA is currently helping another student. When there are no students 
 * who need help during office hours, the TA sits at the desk and takes a nap.
 * If a student arrives during office hours and finds the TA sleeping,
 * the student must awaken the TA to ask for help. If a student arrives 
 * and finds the TA currently helping another student, the student sits on 
 * one of the chairs in the hallway and waits. If no chairs are available, 
 * the student will come back at a later time.
 * 
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef long long ll;

void *studentProcess(void *identity)
{
    int *id = (int*)identity;

}

void *teacherProcess()
{

}
int main(int argc, const char **argv)
{
    ll no_of_students;
    printf("Enter the number of students ");
    scanf("%lld", &no_of_students);

    pthread_t *student_thread = (pthread_t *)malloc(no_of_students * sizeof(pthread_t));
    pthread_t teacher_thread;
    
    // Creating threads of teacher and student
    pthread_create(&teacher_thread, NULL, &teacherProcess, NULL);
    for(int i = 0; i < no_of_students; i++)
        pthread_create(&student_thread[i], NULL, &studentProcess, NULL);  
    
    // Joining the threads to the main process
    pthread_join(teacher_thread, NULL);
    for(int i = 0; i < no_of_students; i++)
        pthread_join(student_thread[i], NULL);

    return 0;
}