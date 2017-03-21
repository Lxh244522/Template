#ifndef _INSERT_SORT_H_
#define _INSERT_SORT_H_

template<class T>
void insertSort(T a[], int n)
{
    T temp;
    if (n < 2) {
        return;
    }
    for (int i=1; i<n; i++) {
        int j=i;
        T temp = a[i];
        while (j>0 && temp<a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}

#endif
