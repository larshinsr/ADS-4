// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int left, int right, int necessary_value) {
    int result = 0;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (arr[middle] == necessary_value) {
            result++;
            int step = middle + 1;
            while (arr[step] == necessary_value && step < right) {
                result++;
                step++;
            }
            step = middle - 1;
            while (arr[step] == necessary_value && step > left) {
                result++;
                step--;
            }
            break;
        }
        if (arr[middle] < necessary_value) {
            left = middle;
        }
        if (arr[middle] > necessary_value) {
            right = middle;
        }
    }
    return result;
}

int countPairs1(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if ((arr[i] + arr[j]) == value) {
                result++;
            }
    return result;
}

int countPairs2(int* arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; j > i; --j) {
            if (arr[i] + arr[j] == value)
                result++;
        }
    }
    return result;
}

int countPairs3(int* arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len-1; ++i) {
        int necessary_value = value - arr[i];
        result += cbinsearch(arr, i, len, necessary_value);
    }
    return result;
}
