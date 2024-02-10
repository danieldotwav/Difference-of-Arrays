## Introduction

A simple, yet effective algorithm to find the differences between two sets of integers using C++.

## Algorithms

### **Find Difference Algorithm**

#### Logic

- The algorithm first inserts all elements from two input arrays into separate unordered sets to eliminate duplicates and allow for efficient lookup.
- It then iterates through each set, comparing elements to identify which are unique to each array (i.e., present in one but not the other).
- The unique elements are stored in two separate vectors, which are then returned together as a vector of vectors.

#### Complexity Analysis

- **Time Complexity:** O(n + m), where n and m are the sizes of the two input arrays. This accounts for the insertion and lookup operations in the unordered sets.
- **Space Complexity:** O(n + m), primarily due to storage used by the two unordered sets and the two vectors that store unique elements.

### Code Snippet

```cpp
vector<vector<int>> findDifference(const vector<int>& nums1, const vector<int>& nums2) {
    vector<vector<int>> answer;
    unordered_set<int> nums1List;
    unordered_set<int> nums2List;

    for (int element : nums1) {
        nums1List.insert(element);
    }
    for (int element : nums2) {
        nums2List.insert(element);
    }

    vector<int> uniqueNums;
    for (int element : nums1List) {
        if (nums2List.find(element) == nums2List.end()) {
            uniqueNums.push_back(element);
        }
    }

    answer.push_back(uniqueNums);
    uniqueNums.clear();

    for (int element : nums2List) {
        if (nums1List.find(element) == nums1List.end()) {
            uniqueNums.push_back(element);
        }
    }

    answer.push_back(uniqueNums);
    return answer;
}
```

## Test Cases

The `main` function contains several test cases:

- Arrays with some common elements.
- Arrays with no common elements.
- Identical arrays.
- One array is empty.
- Both arrays are empty.
- Arrays with negative numbers.
- Arrays with duplicate elements.
- Arrays with a larger range of numbers.