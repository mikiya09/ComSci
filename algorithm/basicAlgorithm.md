

## Basic Component of Algorithm

### [+] Design
#### &#x266f; goal
#### &#x266f; why

### [+] Analysis 
#### &#x266f; Growth Rate
#### &#x266f; Big O Notation



## Search Algorithm 

## Sorting Algorithm
#### [+] Selection Sort
```
most straightforward solution
```
#### [+] bubble Sort
```
smallest element will bubble up to the top, like a real bubble
```
#### &#x266f; cases

#### [+] Insertion Sort
##### &#x23f5; [c++ code](./code/insertion_sort.cpp)
##### &#x266f; pseudocode 
```
for j = 2 to n {

    key = A[j];
    i = j - 1;
    while (i>0) and (A[i] > key) {
        a[i+1] = a[i];
        i = i - 1;
    }
    A[i+1] = key;
}
```

#### [+] Merge Sort
##### &#x266f; pseudocode 
```
Merge-Sort(A, p, r)
{
    if (p < r)
    {
        q = floor( (p+r)/2 );
        Merge-Sort(A, p, q);
        Merge-Sort(A, q+1, r);
        Merge(A, p, q, r);
    }
}


Merge();
```
#### [+] Quick Sort
