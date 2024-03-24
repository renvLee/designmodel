# 排序算法性能对比

常见的排序算法及其平均时间复杂度和空间复杂度如下表所示：

| 排序算法 | 平均时间复杂度 | 最坏时间复杂度 | 空间复杂度 | 稳定性 |
| -------- | -------------- | -------------- | ---------- | ------ |
| 冒泡排序 | O(n^2)         | O(n^2)         | O(1)       | 稳定   |
| 选择排序 | O(n^2)         | O(n^2)         | O(1)       | 不稳定 |
| 插入排序 | O(n^2)         | O(n^2)         | O(1)       | 稳定   |
| 希尔排序 | O(n^(1.3~2))   | O(n^2)         | O(1)       | 不稳定 |
| 归并排序 | O(n log n)     | O(n log n)     | O(n)       | 稳定   |
| 快速排序 | O(n log n)     | O(n^2)         | O(log n)   | 不稳定 |
| 堆排序   | O(n log n)     | O(n log n)     | O(1)       | 不稳定 |
| 基数排序 | O(d * (n + b)) | O(d * (n + b)) | O(n + b)   | 稳定   |
| 桶排序   | O(n + k)       | O(n^2)         | O(n)       | 稳定   |

**说明：**

- n：待排序元素数量
- d：数据的位数
- b：基数
- k：桶的数量

#  排序算法适用场景

选择合适的排序算法需要考虑以下因素：

- **数据规模：** 数据量较小时，简单的排序算法如冒泡排序、选择排序、插入排序即可满足需求。数据量较大时，需要使用更高效的排序算法如归并排序、快速排序、堆排序等。
- **时间复杂度：** 当对排序速度要求较高时，应选择时间复杂度较低的排序算法。
- **空间复杂度：** 当内存空间有限时，应选择空间复杂度较低的排序算法。
- **稳定性：** 当需要保持相同元素的相对顺序时，应选择稳定的排序算法。

以下是几种常见排序算法的适用场景：

- **冒泡排序、选择排序、插入排序：** 适用于数据量较小且对性能要求不高的场景。
- **归并排序：** 适用于需要稳定排序且对空间复杂度要求不高的场景。
- **快速排序：** 适用于对排序速度要求较高且数据量较大的场景。
- **堆排序：** 适用于需要快速找到最大值或最小值的场景。
- **基数排序、桶排序：** 适用于数据分布比较均匀的场景。

# 归并排序

```C++
void merge(int arr[], int l, int m, int r) {
      int n1 = m - l + 1;
     int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    //归并排序
    if (l < r) {
        int m = (l + r )/ 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main() {
    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i]<<"   ";
    }
    delete[]arr;
}
```

# 快速排序

```C++

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i]<<"   ";
    }
    delete[]arr;
}
```

# 堆排序

```C++
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2-1 ; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n-1 ; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {
    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i]<<"   ";
    }
    delete[]arr;
}
```

# 冒泡排序

```C++
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i]<<"   ";
    }
    delete[]arr;
}
```

