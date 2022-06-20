#include "HashTable.h"
#include <iostream>	
#include <sstream>		//for istringstream >> operator
#include <string>
#include <vector>		//for vector<int>
#include <deque>		//for deque<bool>
#include <functional>		//for priority_queue<...greater<int>>
#include <unordered_map>		//include unordered_map
#include <array>		//include array<string, kNumTelDigits>
#include <algorithm>	//unique(), distance()
using namespace std;

//destruct an array object by referencing its pointer
void function1( int arrayP[]) {
	delete[] arrayP;
	arrayP = nullptr;
}

//destruct an array object by referencing a reference to a pointer to the arrays
void function2(int*& r) {
	delete []r;
}

//traverse the vector from beginning to end
//return: true if possible, else false
bool traverse(vector<int> a, size_t index) {
	if (index == a.size() - 1) {
		return true;
	}
	for (size_t i = index + 1; i <= index + a.at(index) && i < a.size(); i++) {
		if (a[i] != 0) {
			return traverse(a, i);
		}
	}
	return false;
}

//delete duplicate entires from the array
//returns size of updated array
size_t deleteDuplicates(int a[], size_t length) {
	if (length == 0) {
		return 0;
	}
	size_t write_index = 0;
	for (size_t i = 1; i < length; i++) {
		if (a[i - 1] != a[i]) {
			a[write_index++] = a[i - 1];
		}
	}
	//to account for the last element
	a[write_index++] = a[length - 1];
	//pad with zeros
	size_t filler = write_index;
	while (filler < length) {
		a[filler++] = 0;
	}
	return write_index;
}

//delete entries with value same as key
//returns size of updated array
size_t deletekey(vector<int>* a_ptr, int key) {
	//vector<int> a = *a_ptr;
	vector<int>& a = *a_ptr;		//why the &?
	size_t write_index = 0;
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] != key) {
			a[write_index++] = a[i];
		}
	}
	size_t filler = write_index;
	while (filler < a.size()) {
		a[filler++] = 0;
	}
	return write_index;
}

//return: max attainable profit from buying and selling a stock once
int maxOnce(vector<int> a) {
	if (a.size() == 0 || a.size() == 1) {
		return 0;
	}
	int currentProfit;
	int maxProfit = 0;	
	int minPrice = numeric_limits<int>::max();
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] < minPrice) {
			minPrice = a[i];
		}
		currentProfit = a[i] - minPrice;
		if (currentProfit > maxProfit) {
			maxProfit = currentProfit;
		}
	}
	return maxProfit;
}

//int maxTwice(vector<int> a) {
	
//}

//return: vector of primes smaller than argument
vector<int> showPrimesUpTo(int n) {
	deque<bool> isPrime(n + 1, true);	//use deque for boolean arrays (not vector<bool>)
	isPrime[0] = isPrime[1] = false;
	const int FIRST_PRIME_NUMBER = 2;
	for (size_t i = FIRST_PRIME_NUMBER; i < isPrime.size(); i++) {
		if (isPrime[i]) {
			for (size_t j = 2 * i; j < isPrime.size(); j += i) {
				isPrime[j] = false;
			}
		}
	}
	vector<int> a;	//can grow and shrink as needed
	for (size_t i = 0; i < isPrime.size(); i++) {
		if (isPrime[i]) {
			a.emplace_back(i);		//why not push_back?
		}
	}
	return a;
}

//test 7.6 reverse the words in a sentence
//O(n) and O(n) space
//return: string containing words reversed 
string reverseWords(string s) {
	if (s == "") {
		return s;
	}
	size_t num_white_spaces = 0;
	for (size_t i = 0; i < s.size(); i++) {
		if (!isalnum(s[i])) {	//count number of white spaces
			num_white_spaces++;
		}
	}
	//size_t NUM_OF_WORDS = num_white_spaces + 1;
	//string word[NUM_OF_WORDS];
	vector<string> word(num_white_spaces + 1);			//cannot use array b/c array size must be a constant		
	for (size_t i = 0, j = num_white_spaces; i < s.size(); i++, j--) {
		while (i < s.size() && isalnum(s[i])) {
			word[j] += s[i++];
		}
	}
	string reverse = "";
	for (size_t i = 0; i < num_white_spaces + 1; i++) {
		reverse += i < num_white_spaces ? word[i] + ' ': word[i];
	}
	return reverse;
}

const int kNumTelDigits = 10;
const array<string, kNumTelDigits> a = { "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

//references, once assigned, cannot be made to reference another object
//const vector<string>& M: called method cannot make changes to M
//vector<string> M: copy of M, calling method won't see	
void recurseHere(const string& s, size_t length, string N, vector<string>& M) {			
	if (s == "") {
		return;
	}
	int digit = s[0] - '0';			//converts char to int, s.charAt(i) only for Java
	string options = a[digit];
	for (size_t j = 0; j < options.size(); j++) {
		string t = N + options[j];
		if (t.size() == length) {
			M.push_back(t);		//not insert or add
		}
		recurseHere(s.substr(1), length, t, M);
	}
}

void computeMnemonics(const string& phone_number, vector<string>& M) {		//this function must come after recurseHere (o/w: identifier not found error appears)											
	//cannot create vector<string> M here and return a constant reference to it, M would be a local variable
	string Mnemonic = "";
	recurseHere(phone_number, phone_number.size(), Mnemonic, M);	
}

const int kBase = 26, kMod = 997;
//test 7.14: Find the first occurrence of a substring
//return: index of start of substring (in string t) that matches the search string s, o/w returns -1
//I have no idea how to make up a hash function on my own
int RabinKarp(const string &t, const string &s) {
	if (s.size() > t.size()) {
		return -1;
	}
	int t_hash = 0, s_hash = 0;
	int power_s = 1;
	for (size_t i = 0; i < s.size(); ++i) {
		power_s = (i) ? power_s * kBase % kMod : 1;		//is i non-zero?
		t_hash = (t_hash * kBase + t[i]) % kMod;
		s_hash = (s_hash * kBase + s[i]) % kMod;
	}
	//checks the two substrings are actually equal or not, to protect against has collision
	for (size_t i = s.size(); i < t.size(); i++) {
		if (t_hash == s_hash && !t.compare(i - s.size(), s.size(), s)) {		//t.compare() returns 0 if strings are equal
			return i - s.size();
		}

		//uses rolling hash to compute the new hash code
		t_hash -= (t[i - s.size()] * power_s) % kMod;
		if (t_hash < 0) {
			t_hash += kMod;
		}
		t_hash = (t_hash * kBase + t[i]) % kMod;
	}
		//tries to match s and the last possible substring in t
		if (t_hash == s_hash && t.compare(t.size() - s.size(), s.size(), s) == 0) {
			return t.size() - s.size();
		}
		return -1;
}

//required for 11.1: priority_queue of Iterators pointing to the beginning and end of a subarray
struct IteratorCurrentAndEnd {			//should you use a class (contains both methods and member variables)?
	//operator overloading: "<", i guess it doesn't count as a true method
	bool operator<(const IteratorCurrentAndEnd& that) const {			
		return *current > *(that.current);		//parentheses around that.current are just for clarification, comparing pointed-to content, not addresses
	}
	vector<int>::const_iterator current;
	vector<int>::const_iterator end;
};

#include <queue>		//includes priority_queue (heaps)
//Exercise 11.1: merge sorted files
vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
	priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>> min_heap;

	for (const vector<int>& sorted_array : sorted_arrays) {
		if (!sorted_array.empty()) {
			min_heap.emplace(IteratorCurrentAndEnd{ sorted_array.cbegin(), sorted_array.cend() });		//parameter passed to emplace() is constructed in place, must initialize struct objects with {} not (), C standard, each parameter corresponds to the member variables declared within the struct
		}
	}

	vector<int> result;
	while (!min_heap.empty()) {
		auto smallest_array = min_heap.top();		//why not IteratorCurrentAndEnd?
		min_heap.pop();
		result.emplace_back(*smallest_array.current);			//NOT smallest_array->current (i.e. (*smallest_array).current)
		//to prevent placing empty IteratorCurrentAndEnd Objects into the min_heap (oeprator<() throws exception: cannot dereference an iterator that refers to end
		if (next(smallest_array.current) != smallest_array.end) {	// end refers to past-the-end element in the container (cbegin == cend iff there are no elements)
			min_heap.emplace(IteratorCurrentAndEnd{ next(smallest_array.current), smallest_array.end });		//why don't I need to #include <Iterator>?
		}
	}
	return result;
}

//test 11.2: Sorts a k increasing-decreasing array
//returns the sorted array
vector<int> SortKIncreasingDecreasingArray(const vector<int>& a) {
	vector<vector<int>> sorted_subarrays;
	typedef enum { INCREASING, DECREASING } SubarrayType;		//this is new
	SubarrayType subarray_type = INCREASING;					//an enum variable can only take on values proposed in the enum declaration
	size_t start_index = 0;
	for (size_t i = 1; i <= a.size(); i++) {
		if (i == a.size() || (subarray_type == INCREASING && a[i - 1] >= a[i]) || (subarray_type == DECREASING && a[i - 1] < a[i])) {
			if (subarray_type == INCREASING) {
				sorted_subarrays.emplace_back(vector<int>(a.cbegin() + start_index, a.cbegin() + i));
			}
			else {
				sorted_subarrays.emplace_back(vector<int>(a.crbegin() + a.size() - i, a.crbegin() + a.size() - start_index));
			}
			start_index = i;							
			subarray_type = (subarray_type == INCREASING ? DECREASING : INCREASING);			//careless: you executed these two lines on every iteration of the for loop
		}
	}
	return MergeSortedArrays(sorted_subarrays);
}

//test 11.3 Sort an almost sorted stream of integers
//each entry in the stream is at most k away from its correctly sorted position
void SortApproximatelySortedData(istringstream* sequence, size_t k) {
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int x;
	for (size_t i = 0; i < k && *sequence >> x; i++) {
		min_heap.push(x);
	}
	while (*sequence >> x) {
		min_heap.push(x);
		cout << min_heap.top() << endl;
		min_heap.pop();
	}
	while (!min_heap.empty()) {
		cout << min_heap.top() << endl;
		min_heap.pop();
	}
}

struct Star {
	double x, y, z;
	double distance() const {			//must include "const" modifier s.t. you can call that.distance() on a const ref. to a obj
		return sqrt(x * x + y * y + z * z);
	}
	bool operator<(const Star& that) const {		//must include const modifier after parameter list to ensure this method does not change the Star obj it is invoked on, else won't compile
		return distance() < that.distance();
	}
};


//test 11.4: Compute k closest stars
vector<Star> FindKClosestStars(istringstream* iss, size_t k) {
	priority_queue<Star, vector<Star>> max_heap;
	string line;
	//fill the max_Heap with k stars
	while (getline(*iss, line)) {	//i.e. line = "3,5,7"
		stringstream ss(line);
		double cdts[3];
		for (size_t i = 0; i < 3 && getline(ss, line, ','); i++) {		//i.e. line = "3"
			cdts[i] = stod(line);		//convert string to double		
		}
		max_heap.emplace(Star{ cdts[0], cdts[1], cdts[2] });
		if (max_heap.size() == k + 1) {
			max_heap.pop();
		}
	}

	vector<Star> kClosest;
	while (!max_heap.empty()) {
		kClosest.emplace_back(max_heap.top());
		max_heap.pop();
	}
	reverse(kClosest.begin(), kClosest.end());		//new, this requires comparing stars, therefore must overload operator<
	return kClosest;
}


//test 11.5: compute the median of a stream of ints
//prints the median of every k numbers for k = [1:n]
void onlineMedian(istringstream* sequence) {
	int x;
	enum {EVEN, ODD} amt = EVEN;
	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	while (*sequence >> x) {
		if (amt == EVEN) {
			if (!max_heap.empty() && x < max_heap.top()) {
				min_heap.emplace(max_heap.top());
				max_heap.pop();
				max_heap.emplace(x);
			}
			else {
				min_heap.emplace(x);
			}
			cout << min_heap.top() << endl;
		}
		else {	//insert into max_heap
			if (x > min_heap.top()) {
				max_heap.emplace(min_heap.top());
				min_heap.pop();
				min_heap.emplace(x);
			}
			else {
				max_heap.emplace(x);
			}
			cout << ((double)max_heap.top() + (double)min_heap.top()) / 2 << endl;	
		}
		amt = (amt == EVEN) ? ODD : EVEN;
	}
}

template <typename Compare>
int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp, vector<int>* A_ptr) {
	vector<int>& A = *A_ptr;
	int pivot_value = A[pivot_idx];
	int new_pivot_idx = left;
	swap(A[pivot_idx], A[right]);
	for (int i = left; i < right; i++) {
		if (comp(A[i], pivot_value)) {
			swap(A[i], A[new_pivot_idx++]);
		}
	}
	swap(A[right], A[new_pivot_idx]);
	return new_pivot_idx;
}

#include <random>		//default_random_engine, random_device(), uniform_int_distribution
template <typename Compare>
int FindKth(int k, Compare comp, vector<int>* A_ptr) {
	vector<int>& A = *A_ptr;
	int left = 0, right = A.size() - 1;
	default_random_engine gen((random_device())());
	while (left <= right) {
		//generates a random integer in [left, right]
		int pivot_idx = uniform_int_distribution<int>{ left, right } (gen);
		int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, comp, &A);
		if (new_pivot_idx == k - 1) {
			return A[new_pivot_idx];
		}
		else if (new_pivot_idx > k - 1) {
			right = new_pivot_idx - 1;
		}
		else {
			left = new_pivot_idx + 1;
		}
	}
	return -1;
}

int FindKthLargest(int k, vector<int>* A_ptr) {
	return FindKth(k, greater<int>(), A_ptr);
}

struct StringCnt {
	string s;	int freq;		//cant have const for some reason???
	bool operator<(const StringCnt& that) const {
		return freq > that.freq;
	}
	string toString() const {
		return s;
	}
};


//test 13.6 compute the k most frequent queries
vector<string> kMostFrequentQueries(vector<string> s, size_t k) {
	unordered_map<string, int> freq_of_string;
	priority_queue<StringCnt, vector<StringCnt>> min_heap;
	if (s.size() <= k) {
		return s;
	}
	for (size_t i = 0; i < s.size(); i++) {		//O(n)
		freq_of_string[s[i]]++; 
		//if (freq_of_string[s[i]] == 1) {			//smart way to prevent inserting duplicates into the heap 
		//	min_heap.emplace(StringCnt{ s[i] });		//the reason why debug assertion: invalid heap error apppears is b/c the value of operator<() returns different values for some entry while that entry remains in the queue
		//}
		//if (min_heap.size() == k + 1) {		//cannot do this because strings will be deleted before their frequency can increase
		//	min_heap.pop();
		//}
	}
	for (const pair<string, int>& p : freq_of_string) {		//O(m log m), where m is the # of distinct strings, and insertion/extraction take logarithmic time
		min_heap.emplace(StringCnt{ p.first, p.second });
	}
	while (min_heap.size() > k) {		//only keep the k most frequent entries, O(n-k)
		min_heap.pop();
	}
	vector<string> mostFreqStrings;
	while (!min_heap.empty()) {		//O(k)
		mostFreqStrings.emplace_back(min_heap.top().toString());
		min_heap.pop();
	}
	return mostFreqStrings;
}

//test 13.3 
bool isLetterConstructableFromMagazine(const string& letter, const string& magazine) {
	unordered_map<char, int> freq_of_chars;		//maps each character to its frequency count
	for (char c : letter) {
		freq_of_chars[c]++;
	}
	for (char c : magazine) {
		auto it = freq_of_chars.find(c);
		if (it != freq_of_chars.cend()) {
			it->second--;
			if (it->second == 0) {
				freq_of_chars.erase(it);
			}
		}
	}
	return freq_of_chars.empty();
}


//test 13.4 can you rearrange the letters of a string to form a palindrome?
bool CanFormPalindrome(const string& s) {
	unordered_map<char, int> freq_of_char;	
	for (size_t i = 0; i < s.size(); i++) {		//skips whiespace characters automatically
		freq_of_char[s.at(i)]++;
	}
	size_t number_of_odd_chars = 0;
	for (const pair<char, int>& p : freq_of_char) {		//don't need to #include anything to use pair<>
		if (p.second % 2) {		//if the freq of that char is odd
			number_of_odd_chars++;
		}
	}
	return number_of_odd_chars <= 1 ? true : false;
}

//test 14.1 Compute the intersection of two sorted arrays
//pre: input arrays are sorted in increasing order
//application: search engine finds the sorted array for each word and computes the intersection of these arrays
//soln: iterate through both arrays simultaneously, advancing one iterator if its element is smaller than another, and writing an element to the result if it appears in both arrays
vector<int> IntersectTwoSorteddArrays(const vector<int>& a, const vector<int>& b) {
	size_t i = 0, j = 0;
	vector<int> result;
	while (i < a.size() && j < b.size()) {
		if (a[i] == b[j]) {
			result.push_back(a[i]);
			i++;
			j++;
		}
		else if (a[i] < b[j]) {
			i++;
		}
		else {	//a[i] > b[j]
			j++;
		}
	}
	return result;
}


//test 14.2 Implement mergesort in-place (i.e. in O(1) space)
//m is the size of a[], n size of b[]
//soln: start with the largest element, put it in the last position in a[], and work backwords
void MergeTwoSortedArrays(int a[], int m, int b[], int n) {
	int write_idx = m + n - 1;
	//find the max element of both arrays and insert at write_idx of 1st array
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] <= b[j]) {
			a[write_idx] = b[j];
			j--;
		}
		else if (a[i] > b[j]) {
			a[write_idx] = a[i];
			i--;
		}
		write_idx--;
	}
	while (j >= 0) {		//if j runs out first, the remaining elements in a[] are smaller than every element in b, no need to sort remaining elements in a, but if i runs out first, need to put the remainin elemnts in b[] into a[], that is what this loop is for
		a[write_idx--] = b[j--];
	}
}

//test 14.3 count the frequencies of characters in a sentence
//soln: sort the string, iterate through to count the number of times a letter appears, resetting cnt to 1 whenever you encounter a new letter
void CountOccurrences(string s) {
	if (s.empty()) {
		return;
	}
	sort(s.begin(), s.end());
	size_t cnt = 1;		//the letter to be considered is present
	for (size_t i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			cnt++;
		}
		else {		//s[i] != s[i+1]
			cout << s.substr(i, 1) << " " << cnt << endl;
			cnt = 1;
		}
	}
	if (s[s.size() - 1] == s[s.size() - 2]) {
		cout << s.substr(s.size() - 1) << " " << cnt << endl;
	}
	else {
		cout << s.substr(s.size() - 1) << " " << 1 << endl;
	}
}

//test 14.4 Remove first name duplicates
//soln: sort the entries, then call unique() to remove duplicates, then erase() to erase the excess elements that do not belong to the array of unique elements
//why doesn't unique() automatically delete leftover elements after moving unique elements to the front of the container???
struct Name {
	string first, last;
	bool operator== (const Name& that) const {		//unique() needs this operator to check for duplicate entries
		return first == that.first;
	}
	bool operator< (const Name& that) const {
		if (first == that.first) {
			return last < that.last;	//why < ?
		}
		return first < that.first;
	}
};

void EliminateDuplicate(vector<Name>* a_ptr) {
	vector<Name> a = *a_ptr;
	sort(a.begin(), a.end());
	//vector<Name>::iterator it = unique(a.begin(), a.end());	//pointer to first element not belonging to the unique array
	//a.erase(it, a.end());		//erase from that element to the end
	a.erase(unique(a.begin(), a.end()), a.end());
}

struct disjointInterval {
	int left, right;
};

//test 14.6 Compute the union of a specified interval with a set of sorted disjoint intervals
//soln: since set is sorted by left endpoints, insert all intervals that do not intersect x, then reassign the value of x to the union of the intersecting interval and x for all intersecting intervals, push x to the result, then insert all intervals that don't intersect
vector<disjointInterval> addInterval(const vector<disjointInterval>& p, disjointInterval x) {
	vector<disjointInterval> result;
	if (p.empty()) {
		result.emplace_back(x);
		return result;
	}
	size_t i = 0;
	while (i < p.size() && x.left > p[i].right) {	//don't intersect x (less than x), add it to result
		result.emplace_back(p[i]);
		i++;
	}
	while (i < p.size() && x.right > p[i].left) {	//no need for x.left < i.right b/c condition is implied if it failed the first "if" condition
		x.left = min(x.left, p[i].left);
		x.right = max(x.right, p[i].right);
		i++;
	}
	result.emplace_back(x);
	while (i < p.size() ) {			//intervals that don't intersect x (greater than x)
		result.emplace_back(p[i]);
		i++;
	}
	return result;
}

struct Interval {
	struct Endpoint {
		int val;
		bool isClosed;
	};
	bool operator<(const Interval& that) const {
		if (left.val != that.left.val) {
			return left.val < that.left.val;
		}
		//if left.val's are equal
		return left.isClosed && !that.left.isClosed;
	}
	Endpoint left, right;
};

//test 14.7 Compute the Union of intervals
vector<Interval> computeUnion(vector<Interval> intervals) {
	if (intervals.empty()) {
		return{};
	}
	sort(intervals.begin(), intervals.end());
	vector<Interval> result;
	Interval cur = intervals.front();
	for (size_t i = 1; i < intervals.size(); i++) {
		if (cur.right.val > intervals[i].left.val || (cur.right.val == intervals[i].left.val && (cur.right.isClosed || intervals[i].left.isClosed))) {	//some overlapping going on
			if (cur.right.val < intervals[i].right.val || (cur.right.val == intervals[i].right.val && intervals[i].right.isClosed)) {	//keep the intervals[i].right
				cur.right = intervals[i].right;
			}
		}
		else {	//no overlap
			result.emplace_back(cur);
			cur = intervals[i];
		}
	}
	result.emplace_back(cur);
	return result;
}

struct Person {
	string name;
	int age;
};

//test 14.8 Partitiong and sorting an array with many repeated entries
void groupByAge(vector<Person>* students) {
	unordered_map<int, int> age_to_count;					//stores the count of people of each age to sort
	for (const Person& p : *students) {	
		age_to_count[p.age]++;
	}
	unordered_map<int, int> age_to_offset;					//stores the offset in the orig. array that a person of age "x" is supposed to go
	int offset = 0;	
	for (const pair<int, int>& p : age_to_count) {			
		age_to_offset[p.first] = offset;
		offset += p.second;
	}
	//find the age of the person @from, based off of his age, find the index at which position he is supposed to be (hash table lookup), and swap the elements
	while (age_to_offset.size()) {
		auto from = age_to_offset.begin();		
		auto to = age_to_offset.find((*students)[from->second].age);	//find the person in the position specified by from->second
		swap((*students)[from->second], (*students)[to->second]);		//find where he is supposed to go based on his age, and swap
		age_to_count[to->first]--;							//people of age "x" left to swap
		if (age_to_count[to->first] > 0) {					//store the next position a person of age "x" is supposed to go in the hash table
			to->second++;
		}
		else {
			age_to_offset.erase(to);
		}
	}
}

int main() {
	//test: difference between calling delete on a pointer and on a reference to a pointer
	/*int p1[5];
	for (size_t i = 0; i < 5; i++) {
		p1[i] = 2 * i;
	}
	function1(p1);		
	cout << *p1 << endl;	//breaks program; pointing to deallocated memory
	cin.get();*/
	
	///////////////////////////////////////////
	//test: difference between --i and i-- 
	/*int a[6];
	for (size_t i = 0; i < 6; i++) {	//no different than ++i
		a[i] = 2 * i;
	}
	int index = 4;
	swap(a[2], a[index--]);		//different from --index
	for (size_t i = 0; i < 6; i++) {
		cout << a[i] << endl;
	}
	cin.get();*/
	//////////////////////////////////////////
	
	//test:can you get to the end of the vector?
	/*int myints[] = { 3, 2, 0, 1, 4, 0, 1 };
	vector<int> a(myints, myints + sizeof(myints)/ sizeof(int));		//parameters: a(beginning address, end address) (in bytes or words)?
	cout << traverse(a, 0) << endl;
	cin.get();
	*/
	////////////////////////////////////////////////

	//test:delete duplicate entries in array
	/*int myints[] = {2 ,3, 5, 5, 7, 11, 11, 11, 13 };
	cout << deleteDuplicates(myints, 9) << endl;
	cin.get();
	*/

	//////////////////////////////////////////////////
	//test:delete entries with a specific value (key)
	/*int myints[] = { 5, 3, 7, 11, 2, 3, 13, 5, 7 };
	vector<int>* a(new vector<int>(myints, myints + sizeof(myints) / sizeof(int)));		//is a pointer value (memory address) inherently size_t?	//difference between vector and dynamically allocated vector?
	cout << deletekey(a, 3) << endl;
	for (int i = 0; i < a->size(); i++) {		//another way using iterators?
		cout << (*a)[i] << endl;
	}
	cin.get(); */
	///////////////////////////////////////////////////

	//test: max profit from buying and selling a stock once
	/*int myints[] = { 12, 11, 13, 9, 12, 15, 14, 13, 8 };
	vector<int> a(myints, myints + sizeof(myints) / sizeof(int));
	cout << maxOnce(a) << endl;
	cin.get();
	*/
	//////////////////////////////////////////////////////

	//test: maxprofit from buying and selling a stock twice

	//////////////////////////////////////////////////////
	//test: return primes smaller than input
	/*int n;
	cin >> n;
	cin.get();
	vector<int> a = showPrimesUpTo(n);
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	cin.get(); */
	
	///////////////////////////////////////////////////////

	/*
	//test 7.6: reverse words in a string
	string s = "Alice likes Bob very much";
	//cin >> s;				//how to read multiple words from std input into s? 
	//cin.get();		
	cout << reverseWords(s) << endl;
	cin.get();

	//test: reverseWords(s) should be " ", not "   " (i.e size should be 1, not 3)
	s = " ";
	if (reverseWords(s).size() == 1) {
		cout << "Success: reverse of 1 whitespace characters is 1 character" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}
	cin.get();
	*/

	//////////////////////////////////////////////////

	////test: 7.7: compute all mneumoics for a phone number
	//string s;
	//cin >> s;
	//vector<string> M;
	//computeMnemonics(s, M);
	//for (size_t i = 0; i < M.size(); i++) {
	//	cout << M[i] << endl;
	//}
	//cin.get();
	//cin.get();

		/////////////////////////////////////////////
	/*
	//test 7.14: find 1st occurrence of substring
	string s = "CGC";
	string t = "GACGCCA";
	cout << RabinKarp(t, s) << endl;
	cin.get();
	*/
	
	///////////////////////////////////////////////////
	
	/*
	//test 11.1
	vector<vector<int>> x = { {3,5,7}, {0,6}, {0, 6, 28} };
	vector<int> result = MergeSortedArrays(x);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	cin.get();
	*/

	////////////////////////////////////////////////////
	/*
	//test 11.2 sorted an increasing-decreasing array
	int myints[] = { 57, 131, 493, 294, 221, 339, 418, 452, 442, 190 };		//no need to specify size inside []
	vector<int> a(myints, myints + sizeof(myints) / sizeof(int));
	vector<int> sorted_a = SortKIncreasingDecreasingArray(a);
	for (size_t i = 0; i < sorted_a.size(); i++) {
		cout << sorted_a[i] << endl;			//so careless: you put a[i] instead of sorted_a[i]
	}
	cin.get();
	*/
	/////////////////////////////////////////////////////
/*
	//test 11.3 almost sorted array
	string line;
	getline(cin, line);				//read user input into "line" var
	istringstream iss(line);		//essentially, create istringstream object around user input
	SortApproximatelySortedData(&iss, 3);
	cin.get();

	//test 11 .4: find k closest stars

	*/
/*
	//test 11.5 compute online median
	string line;
	getline(cin, line);
	istringstream iss(line);
	onlineMedian(&iss);
	cin.get();
	*/

	/*
	//test 12.9 Find kth largest
	int myints[] = { 12, 11, 13, 9, 12, 15, 14, 13, 8 };
	vector<int>* a(new vector<int>(myints, myints + sizeof(myints) / sizeof(int)));
	cout << FindKthLargest(4, a) << endl;
	//cout << random_device()() << endl;		//random number
	cin.get();
	*/

	/*
	//test 13.3 Is anonymous letter constructable from magazine
	string letter = "dogs love bones";
	string magazine = "gones love bods";
	cout << isLetterConstructableFromMagazine(letter, magazine) << endl;
	cin.get();
	*/
	/*
	vector<string> s;
	string str;
	while (cin >> str && str != "Q") {
		s.emplace_back(str);		//why does emplace() not work?
	}
	vector<string> result = kMostFrequentQueries(s, 2);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	cin.get();
	cin.get();
	*/
	//
	////test 13.4 Can you rearrange letters of a string to form a palindrome?
	//string s; 
	//while (getline(cin, s)) {
	//	if (CanFormPalindrome(s)) {
	//		cout << "true" << endl;
	//	}
	//	else {
	//		cout << "false" << endl;
	//	}
	//}

	/*
	//test 11.3 compute k closest stars
	string s = "3,5,7\n 5,1,8\n 6,8,9\n 2,5,8";
	istringstream iss (s);
	vector<Star> stars = FindKClosestStars(&iss, 3);
	for (size_t i = 0; i < stars.size(); i++) {
		cout << stars[i].distance() << endl;
	}
	cin.get();*/
	
/*
	//test 14.3 Count the frequencies of characters in a sentence
	string s ("abbccdef");
	CountOccurrences(s);
	cin.get();
	*/

	/*
	//test s.erase()
	string s ("This is a sentence.");
	auto it = s.erase(s.begin(), s.end() - 9);	//erase() returns an iterator pointing to the first character not erased, or string.end() (i.e. whatever the 2nd parameter poitns at)
	cout << *it << endl;
	cin.get();
	*/

	/*
	//understand unique()
	int myints[] = { 10 };
	vector<int> myvector(myints, myints + 1);
	vector<int>::iterator it = unique(myvector.begin(), myvector.end() - 1);	//unique() returns an iterator pointing to the first element that does not belong to the unique version of the container, or container.end()
	cout << *it << endl;
	cin.get();
	*/
	
	/*
	//test 14.6 Compute the union of a specified interval with a set of disjoint intervals
	vector<disjointInterval> p = { {-4, -1 }, {0, 2}, {3, 6}, {7, 9}, {11, 12}, {14, 17} };
	disjointInterval x = { 1,8 };
	vector<disjointInterval> result = addInterval(p, x);
	for (size_t i = 0; i < result.size(); i++) {
		cout << "[" << result[i].left << ", " << result[i].right << "]" << endl;
	}
	cin.get();
	*/

	/*
	//test 14.7 Compute the union of a set of intervals [not necessarily disjoint]
	vector<Interval> intervals = { {{0, false}, {3, false}}, {{1, true}, {1, true}}, {{2, true}, 
	{4, true}}, {{3, true}, {4, false}}, {{5, true}, {7, false}}, {{7, true}, {8, false}}, 
	{{8, true}, {11, false}}, {{9, false}, {11, true}} };
	vector<Interval> result = computeUnion(intervals);
	for (size_t i = 0; i < result.size(); i++) {
		if (result[i].left.isClosed) {
			cout << "[";
		}
		else {
			cout << "(";
		}
		cout << result[i].left.val << ", " << result[i].right.val;
		if (result[i].right.isClosed) {
			cout << "]";
		}
		else {
			cout << ")";
		}
		cout << endl;
	}
	cin.get();
	*/

	//test 14.8
	/*vector<Person> p = { {"Greg", 14}, {"John", 12}, {"Andy", 11}, {"Jim", 13}, {"Phil", 12}, {"Bob", 13}, {"Chip", 13}, {"Tim", 14} };
	vector<Person>* students = &p;
	groupByAge(students);
	for (size_t i = 0; i < students->size(); i++) {
		cout << (*students)[i].name << endl;
	}
	cin.get();*/

}