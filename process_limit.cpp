#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main()
{
    // this array is storing the interval of time that took for each process to be created
    int size_array = 1000;
    double arr[size_array];
    timeval start, end;
    int id = 0;
    for(int i=0; i< size_array; i++)
    {
        printf("%d\n",i);
        gettimeofday(&start, NULL);
        id = fork();
        // if the id is the child then continue and put him in the infinite loop
        if (id == 0)
        {
            break;
        }
        gettimeofday(&end, NULL);
        // get the time in seconds
        arr[i] = (start.tv_usec - end.tv_usec)/ 1000;
    }
    if (id == 0)
    {
        while(true)
        {
            continue;
        }
    }
    // sum array and calculate the average
    double av = 0;
    for(int i=0; i< size_array; i++)
    {
        av += arr[i];
    }
    av /= size_array;
    printf("%f\n", av);
    return 0;
}









