#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> findDifference(const vector<int>& nums1, const vector<int>& nums2);
void printLists(const vector<vector<int>>& container);

int main() {

	// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
	// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
	// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
	// Note that the integers in the lists may be returned in any order.

	cout << "Test case 1: Some common elements\n";
	printLists(findDifference({ 1, 2, 3 }, { 2, 4, 6 }));

	cout << "Test case 2: No common elements\n";
	printLists(findDifference({ 7, 8, 9 }, { 1, 2, 3 }));

	cout << "Test case 3: Identical arrays\n";
	printLists(findDifference({ 1, 2, 3 }, { 1, 2, 3 }));

	cout << "Test case 4: One array is empty\n";
	printLists(findDifference({}, { 1, 2, 3 }));

	cout << "Test case 5: Both arrays are empty\n";
	printLists(findDifference({}, {}));

	cout << "Test case 6: Arrays with negative numbers\n";
	printLists(findDifference({ -1, -2, -3 }, { 2, -2, 3 }));

	cout << "Test case 7: Arrays with duplicate elements (to test the distinct property)\n";
	printLists(findDifference({ 1, 2, 2, 3 }, { 2, 4, 4, 6 }));

	cout << "Test case 8: Larger range of numbers\n";
	printLists(findDifference({ 10, 20, 30 }, { 20, 40, 60 }));

	cout << "Test case 9: Arrays with extreme values\n";
	printLists(findDifference({ INT_MIN, 0 }, { 0, INT_MAX }));

	cout << "Test case 10: Arrays where all elements are the same\n";
	printLists(findDifference({ 1, 1, 1 }, { 2, 2, 2 }));

	return 0;
}

vector<vector<int>> findDifference(const vector<int>& nums1, const vector<int>& nums2) {
	vector<vector<int>> answer;
	unordered_set<int> nums1List;
	unordered_set<int> nums2List;

	// First, place all values from the containers in separate lists
	for (int element : nums1) {
		nums1List.insert(element);
	}
	for (int element : nums2) {
		nums2List.insert(element);
	}

	// Next, for each element in nums1, determine if it exists in nums2
	vector<int> uniqueNums;
	for (int element : nums1List) {
		// If the element is unique, add it to the vector
		if (nums2List.find(element) == nums2List.end()) {
			uniqueNums.push_back(element);
		}
	}

	// Now store the unqiue numbers in set1
	answer.push_back(uniqueNums);

	// Reset containers and repeat for the numbers in set 2
	uniqueNums.clear();

	for (int element : nums2List) {
		// If the element is unique, add it to the vector
		if (nums1List.find(element) == nums1List.end()) {
			uniqueNums.push_back(element);
		}
	}

	answer.push_back(uniqueNums);
	return answer;
}

void printLists(const vector<vector<int>>& container) {
	// Check if the entire vector of vectors is empty
	if (container.empty()) {
		cout << "The container is empty." << endl;
		return; // Exit the function if the container is empty
	}

	for (const vector<int>& subContainer : container) {
		// Check if the current sub-vector is empty
		if (subContainer.empty()) {
			cout << "(empty list)" << endl; // Print a placeholder for an empty list
		}
		else {
			for (int element : subContainer) {
				cout << element << " ";
			}
			cout << endl; // Move to the next line after printing all elements in the sub-vector
		}
	}
	cout << endl; // Extra line for separation between test cases or for clarity
}