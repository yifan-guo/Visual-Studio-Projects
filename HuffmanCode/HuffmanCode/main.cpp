#include <stddef.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <time.h>
using namespace std;

struct StringCnt {
	string s;
	int cnt;
	bool operator<(const StringCnt& that) const {
		return cnt > that.cnt;
	}
};

// A Huffman tree node
struct MinHeapNode
{
	string data;			 // One of the input characters
	unsigned freq;			 // Frequency of the character
	MinHeapNode *left, *right; // Left and right child

	MinHeapNode(string data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of two heap nodes (needed in min heap)
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;

	if (root->data != "$")
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

//return the encoded string parameter
//otherwise, returns "" if the string does not exist in this tree
string encodeMessage(struct MinHeapNode* root, string str, string acc) {
	if (!root)
		return "";
	if (root->data == str)
		return acc;

	string left = encodeMessage(root->left, str, acc + "0");
	if (left != "")
		return left;

	//if you reach here in the code, could not find str in the left half of the tree
	string right = encodeMessage(root->right, str, acc + "1");
	if (right != "")
		return right;

	//could not find str in either left or right (not possible for the root of the Huffman Tree)
	return "";
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(string message, vector<string> data, vector<int> freq, bool isPair)
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data vector
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (size_t i = 0; i < data.size(); ++i) {
		//cout << data[i] << ": " << freq[i] << endl;
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}
	//cout << "end of freq counts" << endl;

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1)
	{
		// Extract the two minimum freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with frequency equal to the
		// sum of the two nodes frequencies. Make the two extracted
		// node as left and right children of this new node. Add
		// this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = new MinHeapNode("$", left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	// Print Huffman codes using the Huffman tree built above
	cout << "Huffman Code for: \"" << message << "\" is: " << endl;
	printCodes(minHeap.top(), "");

	// Print encoded message
	string encodedMsg = "";
	if (isPair) {
		for (size_t i = 0; i < message.size() - 1; i += 2) {
			encodedMsg += encodeMessage(minHeap.top(), message.substr(i, 2), "");
		}
		cout << endl;
	}
	else {
		for (size_t i = 0; i < message.size(); i++) {
			encodedMsg += encodeMessage(minHeap.top(), message.substr(i, 1), "");
		}
	}
	cout << "encoded message for: \"" << message << "\" is: " << encodedMsg << endl;
	cout << "length of encoded message: " << encodedMsg.size() << "\n" << endl;
}

// Driver program to test above functions
int main()
{
	string s;
	cout << "Type input string to be encoded: ";
	getline(cin, s);
	//===============================Part 1: Huffman Code on single characters====================================
	cout << "Part 1: Huffman Code on single characters" << endl;
	vector<string> unique_chars;		//unique_chars is a vector of distinct single chars (repr. as strings of length 1)
	vector<int> unique_chars_freq;

	unordered_map<string, int> freq_of_string;
	for (size_t i = 0; i < s.size(); i++) {
		freq_of_string[s.substr(i, 1)]++;
	}

	priority_queue<StringCnt, vector<StringCnt>> min_heap;
	for (const pair<string, int>& p : freq_of_string) {
		min_heap.emplace(StringCnt{p.first, p.second});
	}
	while (min_heap.size() > 0) {
		StringCnt tmp = min_heap.top();
		min_heap.pop();
		unique_chars.emplace_back(tmp.s);
		unique_chars_freq.emplace_back(tmp.cnt);
	}
	//done with min_heap

	clock_t startTime = clock();
	HuffmanCodes(s, unique_chars, unique_chars_freq, false);
	clock_t endTime = clock();

	std::cout << "\n\nTime used: "
		<< (endTime - startTime) / (double)CLOCKS_PER_SEC
		<< " seconds.\n" << std::endl;

	freq_of_string.clear();

	//====================================Part 2: Huffman Code for pairs======================================
	//if input is odd number, this algorithm omit the last character
	cout << "Part 2: Huffman Code for pairs" << endl;
	vector<string> arr;
	vector<int> freq;

	//omit the last letter if input string is odd
	for (size_t i = 0; i < s.size() - 1; i += 2) {
		freq_of_string[s.substr(i, 2)]++;
	}

	for (const pair<string, int>& p : freq_of_string) {
		min_heap.emplace(StringCnt{ p.first, p.second });
	}
	while (min_heap.size() > 0) {
		StringCnt tmp = min_heap.top();
		min_heap.pop();
		arr.emplace_back(tmp.s);
		freq.emplace_back(tmp.cnt);
	}
	//done with min_heap

	startTime = clock();
	HuffmanCodes(s, arr, freq, true);
	endTime = clock();

	std::cout << "\n\nTime used: "
		<< (endTime - startTime) / (double)CLOCKS_PER_SEC
		<< " seconds.\n" << std::endl;
	arr.clear();
	freq.clear();
	freq_of_string.clear();

	//=====================================Part 3: Huffman Code for different segments==================================
	cout << "Part 3: Huffman Code for different segments" << endl;

	vector<string> segments;
	//divide the input string s into i segments (the last segment containing extra leftovers) and put them into the vector
	//I experimented by dividing the input into 2, 3, and 4 segments, and observed the results
	for (int i = 2; i < 5; i++) {

		segments.clear();
		int part_size = s.size() / i;
		for (int j = 0; j < i - 1; j++) {
			segments.emplace_back(s.substr(j * part_size, part_size));
		}
		segments.emplace_back(s.substr((i - 1) * part_size));			//last segment can be longer than previous ones

		cout << "Huffman Codes for " << i << " segments of size " << part_size << "\n" << endl;
		//for each segment, generate a Huffman Tree and encode the message
		for (size_t k = 0; k < segments.size(); k++) {
			arr.clear();
			freq.clear();

			//omit the last letter if input string is odd
			freq_of_string.clear();
			for (size_t x = 0; x < segments[k].size(); x++) {
				freq_of_string[segments[k].substr(x, 1)]++;
			}

			for (const pair<string, int>& p : freq_of_string) {
				min_heap.emplace(StringCnt{ p.first, p.second });
			}
			while (min_heap.size() > 0) {
				StringCnt tmp = min_heap.top();
				min_heap.pop();
				arr.emplace_back(tmp.s);
				freq.emplace_back(tmp.cnt);
			}
			//done with min_heap

			startTime = clock();
			HuffmanCodes(segments[k], arr, freq, false);
			endTime = clock();

			std::cout << "\n\nTime used: "
				<< (endTime - startTime) / (double)CLOCKS_PER_SEC
				<< " seconds.\n" << std::endl;
		}
		cout << "End Huffman Code for " << i << " segments\n\n\n\n\n" << endl;
	}

	cin.get();
	return 0;
}


//This skeleton Huffman Code (the struct declaration and first 3 methods) are contributed by Aditya Goel. 
//I made modifications and extensions to this code to support this assignment.
