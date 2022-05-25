// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int a = 0; a < len - 1; a++) {
        for (int b = a + 1; b < len; b++) {
            if (arr[a] + arr[b] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int a = 0; a < len - 1; a++) {
        for (int b = len - 1; b > a; b--) {
            if (arr[a] + arr[b] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int a = 0; a < len-1; a++) {
        int left = a; int right = len;
        while (left < right - 1) {
            int mid = (left + right) / 2;
            if (arr[a] + arr[mid] == value) {
                count++;
                int b = mid + 1;
                while ((arr[a] + arr[b] == value) && (b < right)) {
                    count++;
                    b++;
                }
                b = mid - 1;
                while ((arr[a] + arr[b] == value) && (b > left)) {
                    count++;
                    b--;
        }
                break;
    }
            if (arr[a] + arr[mid] > value)
                right = mid;
            else
                left = mid;
        }
    }
    return count;
}
