/**
 * @author : Rajdeep Roy Chowdhury
 * @handle : razdeep <rrajdeeproychowdhury@gmail.com>
 * 
 * ---------------
 *    TASK #22
 * ---------------
 * 
 * Question:
 *  
 * Write a program that implements the FIFO page replacement algorithm. 
 * First, generate a random page-reference string where page numbers range 
 * from 0 to 9. Apply the random page-reference string to each algorithm, 
 * and record the number of page faults incurred by each algorithm.
 * Implement the replacement algorithm so that the number of page frames 
 * can vary from 1 to 7. Assume that demand paging is used.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define debugi(x) printf("DEBUG : %d\n", x)
#define FORN(i, n) for(__typeof(i) i = 0; i < n; i++)

typedef long long ll;

int random_flag = 0; //false
void showInputs(ll *virtual_memory_pages, ll no_of_pages, ll no_of_frames);
void drawLine();
int findPageHit(ll *frame_list, ll no_of_frames, ll target)
{
    for(int i = 0; i < no_of_frames; i++)
    {
        if(frame_list[i] == target)
            return 1;
    }
    return 0;
}

void populatePages(ll *virtual_memory_pages, ll no_of_pages)
{
    // debugi(no_of_pages);
    for (int i = 0; i < no_of_pages; i++)
        virtual_memory_pages[i] = (rand() % 10);
}
int main(int argc, const char **argv)
{
    srand(time(NULL));
    ll no_of_pages;
    ll *virtual_memory_pages;
    if(argc == 1)
    {
        printf("Enter the number of pages in virtual memory ");
        scanf("%lld", &no_of_pages);
        virtual_memory_pages = (ll *)malloc(sizeof(ll) * no_of_pages);
        populatePages(virtual_memory_pages, no_of_pages);
        random_flag = 1; //true
    }
    else
    {
        no_of_pages = argc - 1;
        virtual_memory_pages = (ll *)malloc(sizeof(ll) * no_of_pages);
        int index = 0;
        for(int i = 1; i < argc; i++)
            virtual_memory_pages[index++] = atoll(argv[i]);
    }
    ll no_of_frames;
    printf("Enter the number of frames ");
    scanf("%lld", &no_of_frames);
    showInputs(virtual_memory_pages, no_of_pages, no_of_frames);
    ll *frame_list = (ll *)malloc(no_of_frames * sizeof(ll));
    memset(frame_list, -1, no_of_frames * sizeof(ll));

    ll count_page_hit, count_page_fault;
    count_page_hit = count_page_fault = 0;
    
    ll last = -1;
    for(int i = 0; i < no_of_pages; i++)
    {
        if(findPageHit(frame_list, no_of_frames, virtual_memory_pages[i]))
            count_page_hit++;
        else
        {
            frame_list[++last % no_of_frames] = virtual_memory_pages[i];
            count_page_fault++;
        }
    }

    printf("Number of Page hits are %lld\n", count_page_hit);
    printf("Number of Page faults are %lld\n", count_page_fault);
    return 0;
}

void showInputs(ll *virtual_memory_pages, ll no_of_pages, ll no_of_frames)
{
    printf("You have entered the following data....");
    drawLine();
    printf("Number of pages\t\t\t: %lld\n", no_of_pages);
    if(random_flag) printf("Random ");
    else            printf("Custom ");
    printf("Virtual Memory Pages \t: ");
    for(int i = 0; i < no_of_pages; i++)
        printf("%lld ", virtual_memory_pages[i]);
    printf("\nNumber of frames\t\t: %lld", no_of_frames);
    drawLine();
}
void drawLine()
{
    printf("\n");
    for(int i = 0; i < 30; i++)
        printf("-");
    printf("\n");
}