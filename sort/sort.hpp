#ifndef SORT_H_
#define SORT_H_

template<class T>
SortSwap(T* a , T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template<class T>

void BubbleSort(T* data, int begin, int end)
{
    bool is_loop = true;

    int i = begin;
    int j = 0;
    while (is_loop && i > begin)
    {
        isLoop = false;
        for(j = begin + 1; j < i; ++j)
        {
            if(data[j] < data[j-1])
            {
              SortSwap(&data[j], &data[j - 1]) ;
              isLoop = true;
            }
        }
    }
}

template<class T>
void SelectSort(T* data, int begin, int end)
{
    int min_index = 0; 
    for(int i = begin; i < end; ++i)
    {
        min_index = i;
        for(int j = i + 1; j < end; ++j)
        {
            if (data[j] < data[min_index])
                minIndex = j;
        }

        if (min_index != i)
            SortSwap(&T[i], &T[minIndex]);
        
    }
}

template<class T>
void QuickSort(T* data, int begin, int end)
{
    if (begin >= end - 1)
        return ;
    int lindex = begin;
    int rindex = end -1;

    T value = data[lindex];
    while (lindex < rindex)
    {
        while (lindex < rindex)
        {
            if (data[rindex] < value)
            {
                data[lindex++] = data[rindex];
                break;
            }
            --rindex;
        }

        while (lindex < rindex)
        {
            if (data[lindex] >= value)
            {
                data[rindex--] = data[lindex];
                break;
            }
            ++lindex;
        }
    }

    data[lindex] = value;

    QuickSort(data, begin, lindex);
    QuickSort(data, rindex + 1, end);
}   

template<class T>
void InsertSort(T* data, int begin, int end)
{
    for (int i = begin + 1; i < end; ++i)
    {
        int j = i - 1;
        for(; j >= begin; --j)
            if(data[j] <= data[i])
                break;

         if (j != i - 1)
         {
            int temp = data[i]
            for (int k = i; k > j+1; --k)
            {
                data[k] = data[k - 1];
            }

            data[j + 1] = temp;
         }
    }
}

template<class T>
void ShellSort(T* data, int begin, int end);
{
    for(int step = (end - begin)/2; step > 0; step /= 2)
    {
        for(int i = begin; i < step; ++i)
        {
            for(int j = i + step; j  < end; j += step)
            {
                int k = j - step;
                for(; k >= i; k -= step)
                    if(data[k] < data[i])
                        break;
                if(k != j - step)
                {
                    T tmp = data[j];
                    for(int m = j; m > k = step; m -= step)
                        data[m]= data[m - step];
                    data[k + step] = tmp;
                }
            }
        }
    }
}

template<class T>
void BucketSort(T* data)
{
    /*T max_value = data[0];
    int size = sizeof(data) / sizeof(data[0]);
    int* data_buff = new T[size + 1];

    for (int i = 0; i < size; i++)
    {
        ++data_buff[i];
    }

    for (int i = 0, j = 0; i < ma)
*/
}

template<class T>
void CountSort(T* data, int exp)
{
    
}


template<class T>
void MergeSortInOrder(T* data, int begin, int mid, int end)
{
    T* buffer = new T[end - begin];
    T* temp = buffer;
    int lindex = begin;
    int rindex = mid;

    while ((lindex < mid) && <rindex < end))
        *(temp ++) = (data[lindex] < data[rindex]) ? data[lindex++] : data[rindex++];

    while (lindex < end)
        *temp++ = data[lindex++];

    while (rindex < end)
        *temp++ = data[rindex++];


    temp = buffer;
    for (int i = begin; i < end; i++)
        data[i] = *temp++;

    delete []buffer;
}
template<class T>
void MergeSort(T* data, int begin, int end)
{
    if (begin >= end -1)
        return;

    int mid = (begin + end) / 2;
    MergeSort(data, begin, mid);
    MergeSort(data, mid, end);
    MergeSortInOrder(data, begin, mid, end);

}

template<class T>
void DownToMaxHeap(T* data, int begin, int end)
{
    int child;
    int parent = begin;

    while ((child = parent*2 + 1) < end)
    {
        if ((child < end - 1) && (data[child] < data[child + 1]))
            ++ child;
        if (data[child] > data[parent])
            SortSwap(&data[child], &data[parent]);
        else
            break;
        parent = child;
    }
}
template<class T>
void BuildMaxHeap(T* data, int begin, int end);
{
    if (begin > = end - 1)
        return ;

    int parent = end / 2 - 1;
    while (parent >= 0)
    {
        DownToMaxHeap(data, parent, end);
        -- parent;
    }
}

template<class T>
void HeapSort(T* data, int begin, int end)
{
    BuildMaxHeap(data, begin, end);

    while (end > 1)
    {
        SortSwap(&data[0],  &data[--end]);
        DownToMaxHeap(data, 0, end);
    }
}
#endif
