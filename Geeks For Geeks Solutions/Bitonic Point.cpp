class Solution {
public:
    int findMaximum(int arr[], int n) {
        int low = 0;
        int high = n - 1;
        int maxElement = arr[high];  // Initialize the maxElement with the last element

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > maxElement) {
                maxElement = arr[mid];
            }

            if (arr[mid] > arr[mid + 1]) {
                high = mid - 1;  // Search in the left half
            } else {
                low = mid + 1;  // Search in the right half
            }
        }

        return maxElement;
    }
};