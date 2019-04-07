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
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define DEBUGI(identifier, x) printf("DEBUG : %s is %d\n", identifier, x)

typedef long long ll;

#define MAX_WAITING_CHAIRS 3
pthread_mutex_t mutex; // For mutual exclusion among the processes
ll no_of_students_waiting = 0;
ll next_teach_index = 0;
int waiting_queue[MAX_WAITING_CHAIRS];
sem_t student_sem, teacher_sem;

void *studentProcess(void *identity)
{
    int *id = (int *)identity;
    DEBUGI("ID", *id);
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        if(no_of_students_waiting + 1 < MAX_WAITING_CHAIRS)
        {
            printf("Student %d is sitting in the waiting seat queue\n", *id);
            waiting_queue[no_of_students_waiting++ % MAX_WAITING_CHAIRS] = *id;
            printf("%lld students are waiting in the seat queue\n", no_of_students_waiting);
            
            pthread_mutex_unlock(&mutex);

            sem_post(&student_sem);
            sem_wait(&teacher_sem);
        }
        else{
            pthread_mutex_unlock(&mutex);
            printf("Student %d is doing programming at home\n", *id);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    

}

void *teacherProcess()
{
    while (1)
    {
        sleep(1);
        sem_wait(&student_sem);
        no_of_students_waiting--;
        pthread_mutex_lock(&mutex);

        if(no_of_students_waiting > 0)
        {
            printf("---------Teacher waken up by student--------\n");
            printf("Teacher is teaching student %d\n", waiting_queue[next_teach_index++ % MAX_WAITING_CHAIRS]);
        }
        else{
            printf("Teacher is sleeping\n");
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&teacher_sem);
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

    // Initialization of mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&student_sem, 0, 0); // pshared = 0(mid arg) means it'll be shared among only one process
    sem_init(&teacher_sem, 0, 1);
    memset(waiting_queue, -1, sizeof(int) * MAX_WAITING_CHAIRS);

    // Creating threads of teacher and student
    pthread_create(&teacher_thread, NULL, &teacherProcess, NULL);
    for (int i = 0; i < no_of_students; i++)
        pthread_create(&student_thread[i], NULL, &studentProcess, &i);

    // Joining the threads to the main process
    pthread_join(teacher_thread, NULL);
    for (int i = 0; i < no_of_students; i++)
        pthread_join(student_thread[i], NULL);

    return 0;
}