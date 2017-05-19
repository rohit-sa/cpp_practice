#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <limits.h>
#include <set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int first = l1->val + l2->val;
	int carry = first/10;
	struct ListNode *out = new ListNode(first%10);
	struct ListNode *p = out;
	l1 = l1->next;
	l2 = l2->next;
	while(l1 != NULL || l2 != NULL){
		int sum = carry;
		if(l1 != NULL && l2 != NULL){
			sum = sum + l1->val + l2->val;
		}
		else if(l1 != NULL){
			sum = sum + l1->val;
		}
		else{
			sum = sum + l2->val;
		}
		carry = sum/10;
		struct ListNode *new_node = new ListNode(sum%10);
		p->next = new_node;
		p = p->next;
		
		if(l1 != NULL){
			l1 = l1->next;
		}
		if(l2 != NULL){
			l2 = l2->next;
		}
	}
	if(carry == 1){
		struct ListNode *new_node = new ListNode(carry);
		p->next = new_node;
		return out;
	}
	else{
		return out;
	}
}

void two_sum(void){
	unordered_map<int, int> num_map;
	vector<int> nums = {2, 5, 5, 7, 11, 15};
	int target =  12;
	int len = nums.size();
	for(int i = 0; i < len; i++){
		int comp =  target - nums[i];
		auto search = num_map.find(comp);
		if(search != num_map.end()){
			cout << search->second << " " << i << endl;
			break;
		}
		else{
			num_map.insert({nums[i],i});
		}
	}
}

int lengthOfLongestSubstring(string s) {
	int len  = s.size();
	if(len == 1){
		return 1;
	}
	unordered_map <char, int> s_map;
	int max_len = 0;
	int i = 0, j = 0;
	while( i < len && j < len){
		if(! s_map.insert({s.at(j),j}).second){
			s_map.erase(s.at(i));
			i++;
		}
		else{
			j++;
			int s_len = j - i;
			if(max_len < s_len){
				max_len = s_len;
			}
		}
	}
	return max_len;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size();
	int len2 = nums2.size();
	int median_pos = (len1 + len2)/2;
	double median = 0.0;
	double median1 = 0.0, median2 = 0.0;
	int i = 0,j = 0, k = 0;
	while(k <= median_pos){
		
		if( i < len1 && j < len2){
			if(nums1[i] <= nums2[j]){
				median1 = nums1[i];
				i++;
			}
			else{
				median1 = nums2[j];
				j++;
			}
			k++;
		}
		else if(i < len1){
			median1 = nums1[i];
			i++;
			k++;
		}
		else{
			median1 = nums2[j];
			j++;
			k++;
		}
		if(k == median_pos){
			median2 = median1;
		}
	}

	if((len1+len2)%2 == 0){
		median = (median1+median2)/2;
	}
	else{
		median = median1;
	}
	return median;
}

int reverse(int x) {
	int rev = 0;
	while(x!= 0){
		int temp = (rev*10) + x%10;
		if(temp/10 != rev){
			return 0;
		}
		rev = temp;
		x = x/10;
	}
	return rev;
}

int myAtoi(string str) {
	if(str.size() == 0){
		return 0;
	}
	int j = 0;
	int len = str.size();
	while(j < len && str.at(j) == ' '){
		if(j == len-1){
			return 0;
		}
		j++;
	}
	str.erase(0,j);
	int neg = 1;
	char sign = str.at(0);
	if(sign == '-'){
		neg = -1;
		str.erase(0,1);
	}
	else if(sign == '+'){
		str.erase(0,1);
	}
	if(str.size() == 0){
		return 0;
	}
	
	long int out = 0, i = 0;
	len = str.size();
	char c = str.at(0);
	int num = c - '0';
	while(i < len && num <= 9 && num >= 0){
		c = str.at(i);
		num = c - '0';
		if(num > 9 || num < 0){
			break;
		}
		long int temp = (out*10) + num;
		if(neg*temp >= INT_MAX) return INT_MAX;
		if(neg*temp <= INT_MIN) return INT_MIN; 
		out = temp;
		i++;
	} 
	return neg*out;
}

int maxArea(vector<int>& height) {
	int len = height.size();
	int max_area = 0;
	 for(int i = 0, j = len-1; i != j;){
		 int area = (j - i)*min(height[i],height[j]);
		 max_area = max(max_area, area);
		 if(height[i] < height[j]){
			 i++;
		 }
		 else{
			 j--;
		 }
	 }
	 return max_area;
}

int romanToInt(string s) {
	int len = s.size();
	unordered_map <char,int> s_map = {{'L',50},{'X',10},{'V',5},{'I',1},{'M',1000},{'D',500},{'C',100}};
	
	int total = s_map[s.at(len-1)]; 
	for(int i = 0; i < len-1; i++){
		if(s_map[s.at(i+1)] <= s_map[s.at(i)]){
			total = total + s_map[s.at(i)];
		}
		else{
			total = total - s_map[s.at(i)];
		}
	}
	return total;
}

string longestCommonPrefix(vector<string>& strs) {
	int total_num = strs.size();
	if(total_num == 0){
		return "";
	}
	string sample = strs[0];
	int len = sample.size();
	string lc_prefix = "";
	for(int i = 0; i < len; i++){
		string prefix = sample.substr(0,i+1);
		for(int j = 0; j < total_num; j++){
			string test_str = strs[j]; 
			int test_size = test_str.size();
			if((i >= test_size) || prefix.compare(test_str.substr(0,i+1)) != 0){
				return lc_prefix;
			}
		}
		lc_prefix = prefix;
	}
	return lc_prefix;
}
vector<string> combine(vector <string>& a, vector <string>& b){
	int len_a = a.size();
	int len_b = b.size();
	vector <string> comb;
	for(int i = 0; i< len_a; i++){
		for(int j = 0; j < len_b; j++){
			comb.push_back(a[i]+b[j]);
		}
	}
	return comb;
}
vector<string> letterCombinations(string digits) {
	unordered_map <char, vector<string>> num_map = {{'2',{"a","b","c"}},{'3',{"d","e","f"}},
	{'4',{"g","h","i"}},{'5',{"j","k","l"}},{'6',{"m","n","o"}},
	{'7',{"p","q","r","s"}},{'8',{"t","u","v"}},{'9',{"w","x","y","z"}}};
	int len = digits.size();
	if(len == 0){
		return {};
	}
	vector <string> final_comb = num_map[digits.at(0)];
	for(int i = 1; i < len; i++){
		final_comb = combine(final_comb, num_map[digits.at(i)]);
	}
	return final_comb;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* p = head;
	ListNode* q = head;
	int len = 0;
	while(q != NULL && len < n){
		q = q->next;
		len++;
	}
	if( q == NULL){
		head = p->next;
		return head;
	}
	while(q-> next != NULL){
		p = p->next;
		q = q->next;
	}
	ListNode* to_remove = p->next;
	p->next = to_remove->next;
	delete to_remove;
	return head;
}

bool isValid(string s) {
	int len = s.size();
	vector <char> search;
	int open = 0;
	if(len > 0 && (s.at(0) == '}' || s.at(0) == ')' || s.at(0) == ']')){
		return false;
	}
	for(int i = 0; i < len; i++){
		char c = s.at(i);
		switch(c){
			case '(':
			search.push_back(')');
			open++;
			break;
			case '{':
			search.push_back('}');
			open++;
			break;
			case '[':
			search.push_back(']');
			open++;
			break;
			default:
			open--;
			if(c == search.back()){
				search.pop_back();
			}
		}
	}
	if(open != 0 || search.size() != 0){
		return false;
	}
	return true;	
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* p = l1;
	ListNode* q = l2;
	ListNode* merge_list = new ListNode(0);
	ListNode* r = merge_list;
	if(p == NULL && q == NULL){
		return NULL;
	}
	while(p != NULL && q != NULL){
		if(p->val < q->val){
			r->next = new ListNode(p->val);
			p = p->next;
		}
		else {
			r->next = new ListNode(q->val);
			q = q->next;
		}
		r = r->next;
	}
	if(p != NULL){
		r->next = p;
	}
	else{
		r->next = q;
	}
	
	return merge_list->next;
}

int removeDuplicates(vector<int>& nums) {
	int len = nums.size();
	if(len < 2){
		return 1;
	}
	int id = 1;
	for(int i = 1; i < len; i++){
		if(nums[i] > nums[i-1]){
			nums[id] = nums[i];
			id++;
		}
	}
	return id;
}

int strStr(string haystack, string needle) {
	int haystack_len = haystack.size();
	int needle_len = needle.size();
	if(needle_len == 0){
		return 0;
	}
	if(needle_len > haystack_len){
		return -1;
	}
	for(int i = 0; i <= haystack_len-needle_len; i++){
		int j = 0;
		for(; j < needle_len; j++){
			if(haystack.at(i+j) != needle.at(j)){
				break;
			}
		}
		if(j == needle_len){
			return i;
		}
	}
	return -1;
}

int divide(int dividend, int divisor) {
	int neg = 1;
	long int num = dividend;
	long int den = divisor;
	if(divisor == 0 || (dividend == INT_MIN && divisor == -1)){
		return INT_MAX;
	}
	if(dividend < 0){
		neg = -neg;
		num = -num;
	}
	if(divisor < 0){
		neg = -neg;
		den = -den;
	}
	long int res = 0;
	while(num >= den){
		long int temp = den;
		long int quotient = 1;
		while(num >= (temp << 1)){
			temp = temp << 1;
			quotient = quotient << 1;
		}
		num = num - temp;
		res = res + quotient;
	}
	if(neg == -1){
		return -res;
	}
	return res;
}

int search(vector<int>& nums, int target) {
	int len = nums.size();
	if(len == 0){
		return -1;
	}
	int low = 0, high = len-1;
	while(low < high){
		int mid = low + (high-low)/2;
		if(nums[mid] == target){
			return mid;
		}
		else if(nums[mid] < nums[low]){
			if(nums[low] <= target || nums[mid] > target){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		else{
			if(nums[low] <= target && nums[mid] > target){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
	}
	if(nums[low] == target){
		return low;
	}
	return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int len = nums.size();
	vector <int> result = {-1,-1};
	if(len == 0){
		return result;
	}
	int low = -1, high = len-1;
	while(high - low > 1){
		int mid = low + (high - low)/2;
		if(nums[mid] < target){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	if(nums[high] == target){
		result[0] = high;
	}
	low = 0;
	high = len;
	while(high - low > 1){
		int mid = low + (high - low)/2;
		if(nums[mid] <= target){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	if(nums[low] == target){
		result[1] = low;
	}
	return result;
}

bool isValidSudoku(vector<vector<char>>& board) {
	int rows = board.size();
	int cols = board[0].size();
	
	for(int i = 0; i < rows; i++){
		vector <char> row = board[i];
		set<char> row_set;
		for(int j = 0; j < cols; j++){
			if(row[j] != '.'){
				if(row_set.insert(row[j]).second == false){
					return false;
				}
			}
		}
	}
	return true;
}
int main(){
	
	return 0;
}
