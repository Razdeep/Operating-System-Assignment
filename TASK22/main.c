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

int findPageHit(ll *frame_list, ll no_of_frames, ll target); // @TODO

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
    printf("Enter the page-reference string ");
    scanf("%lld", &no_of_pages);
    ll *virtual_memory_pages = (ll *)malloc(sizeof(ll) * no_of_pages);
    populatePages(virtual_memory_pages, no_of_pages);
    // DEBUG
    // for(int i=0; i < no_of_pages; i++)
    //     printf("%lld ", virtual_memory_pages[i]);
    // DEBUG ENDS

    ll no_of_frames;
    printf("Enter the number of frames ");
    scanf("%lld", &no_of_frames);
    ll *frame_list = (ll *)malloc(no_of_frames * sizeof(ll));
    memset(frame_list, -1, no_of_frames);

    // DEBUG @FIX BUG HERE
    ll i;
    FORN(i, no_of_frames) debugi(frame_list[i]);
    // DEBUG ENDS

    return 0;
}