// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
        if (i != j)
            if (arr[i] + arr[j] == value)
                c++;
    return c / 2;
}
int countPairs2(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++)
        for (int j = len - 1; j > i; j--)
            if (arr[i] + arr[j] == value)
                c++;
    return c;
}
int binsearch(int *arr, int l, int r, int x) {
    int left = l, right = r, mid = 0; bool f = 0;
    while (left <= right)  {
        mid = (left + right) / 2;
        if (arr[mid] == x) {
            return binsearch(arr, l, mid - 1, x) + binsearch(arr, mid + 1, r, x) + 1;
        }
        if (x < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}
int countPairs3(int *arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len; i++) {
      c += binsearch(&arr[i + 1], 0 , len - i, value - arr[i]);
    }
    return c;
}
