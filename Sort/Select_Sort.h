#ifndef _SELECT_SORT_H_
#define _SELECT_SORT_H_

template<class T>
void selectSort(T a[], int n)
{
    for (int i=0; i<n-1; i++) {
        T temp;
        int pos = i;
        int j = i+1;
        while (j < n) {
            pos = a[i] < a[j] ? i : j;
            j++;
        }
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;
    }
}

#endif
