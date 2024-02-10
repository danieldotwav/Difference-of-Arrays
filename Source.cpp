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


	printLists(findDifference({ 1, 2, 3 }, { 2, 4, 6 }));


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
	for (vector<int> subContainer : container) {
		for (int element : subContainer) {
			cout << element << " ";
		}
		cout << endl;
	}
	cout << endl;
}