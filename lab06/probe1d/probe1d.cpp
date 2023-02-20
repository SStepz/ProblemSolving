/*
LANG: C++
*/

#include "probelib.h"
#include <cstdio>

int n;

int binarysearch(int start, int end)
{
    int mid;
    if (start == end)
        return start;   
    mid = (end + start)/2;
    if (probe_check(start,mid))
        return binarysearch(start,mid);
    else
        return binarysearch(mid+1,end);
}

int main()
{
    n = probe_init();
    probe_answer(binarysearch(0,n-1));
}