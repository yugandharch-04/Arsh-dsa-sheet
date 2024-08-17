class Solution {
public:
    int check(vector<vector<int>>& matrix,int mid) {
        int count = 0; // Initialize count of elements <= mid
int n = matrix.size(); // Get the number of rows (n x n matrix)
int row = 0; // Start from the first row
int col = n - 1; // Start from the last column

// Continue while there are rows and columns to check
while (row < n && col >= 0) {
    // Check the element at the current position
    if (matrix[row][col] <= mid){
        // If the current element is <= mid, all elements in this column up to this row are also <= mid
        count += (col + 1); // Add all these elements to the count
        row++; // Move to the next row to continue checking
    }else{
        // If the current element is > mid, move left to check smaller elements in the same row
        col--;
    }
}
return count; 
    }

    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n-1][n-1];
    while (low <= high) {
        int mid = low + (high - low) / 2;
      // Count the number of elements in the matrix that are less than or equal to a given mid value.
        if (check(matrix,mid) < k){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low; 
    }
};