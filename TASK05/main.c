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
#include <semaphore.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

typedef long long ll;

pthread_mutex_t desk_chair; // The chair for student infront of Teacher's table
const int MAX_WAITING_CHAIRS = 3;

void *studentProcess(void *identity)
{
    int *id = (int *)identity;
    while (1)
    {

    }
}

void *teacherProcess()
{
    while (1)
    {
        printf("---------Teacher waken up by student--------\n");
        pthread_mutex_lock(&desk_chair);

        pthread_mutex_unlock(&desk_chair);
        sleep(1);
    }
}
int main(int argc, const char **argv)
{
    ll no_of_students = 5LL;             // Keeping 5 students as default
    if (argc == 2)
    {
        no_of_students = atoll(argv[1]); // Taking the first argument as input
        printf("Number of students taken from argument is %lld\n", no_of_students);
    }
    else if (argc == 1)
    {
        printf("Enter the number of students ");
        scanf("%lld", &no_of_students);
    }
    else
    {
        printf("Passed argument doesn\'t seem to match. Taking number of student 5 as default.");
    }
    
    pthread_t *student_thread = (pthread_t *)malloc(no_of_students * sizeof(pthread_t));
    pthread_t teacher_thread;

    pthread_mutex_init(&desk_chair, NULL);

    // Creating threads of teacher and student
    pthread_create(&teacher_thread, NULL, &teacherProcess, NULL);
    for (int i = 0; i < no_of_students; i++)
        pthread_create(&student_thread[i], NULL, &studentProcess, NULL);

    // Joining the threads to the main process
    pthread_join(teacher_thread, NULL);
    for (int i = 0; i < no_of_students; i++)
        pthread_join(student_thread[i], NULL);

    return 0;
}