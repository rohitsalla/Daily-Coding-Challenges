class Solution {

    int maxIndexDiff(int arr[], int n) {
    int minarr[] = new int[n];
    int maxarr[] = new int[n];

    // Finding the minimum element on the left side of each element
    minarr[0] = arr[0];
    for (int i = 1; i < n; i++) {
        minarr[i] = Math.min(arr[i], minarr[i - 1]);
    }

    // Finding the maximum element on the right side of each element
    maxarr[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        maxarr[j] = Math.max(arr[j], maxarr[j + 1]);
    }

    int i = 0, j = 0, maxDiff = -1;

    // Finding the maximum difference between the minimum and maximum element
    // satisfying the condition minarr[i] <= maxarr[j]
    while (j < n && i < n) {
        if (minarr[i] <= maxarr[j]) {
            maxDiff = Integer.max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }

    return maxDiff;
}
}