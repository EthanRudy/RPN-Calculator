#include "rpn.h"
#include <algorithm>
#include <stack>

using namespace std;

bool rpn::isDigi(char c){
	char digits[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int size = sizeof(digits) / sizeof(digits[0]);
	if (count(digits, digits + size, c) != 0){
		return true;
	}
	return false;
}

bool rpn::isOper(char c){
	char ops[5] = {'+', '-', '*', '/', '('};
	int size = sizeof(ops) / sizeof(ops[0]);
	if (count(ops, ops + size, c) != 0){
		return true;
	}
	return false;
}

string rpn::remSpace(string str){
	while (count(str.begin(), str.end(), ' ') > 0){
		int pos = str.find(' ');
		if (pos != -1){
			str = str.substr(0, pos) + str.substr(pos + 1);
		}
	}
	return str;
}

string rpn::to_rpn(string str){
	str = remSpace(str);

	stack<char> operators;
	string rpn = "";
	
	for (int i = 0; i < str.length(); i++) {
		if (isOper(str[i])) {
			if (i != 0) {
				if (str[i] == '(' && isDigi(str[i - 1])) {
					operators.push('*');
				}
			}
			if (operators.size() > 0) {
				if (str[i] == '+' || str[i] == '-') {
					if (operators.top() == '*' || operators.top() == '/') {
						rpn += operators.top();
						operators.pop();
						operators.push(str[i]);
					}
					else {
						operators.push(str[i]);
					}
				}
				else {
					operators.push(str[i]);
				}
			}
			else {
				operators.push(str[i]);
			}
		}


		else if (isDigi(str[i])) {
			rpn += str[i];
		}
		else if (str[i] == ')') {
			while (operators.size() != 0) {
				if (operators.top() == '(') {
					operators.pop();
					break;
				}
				rpn += operators.top();
				operators.pop();
			}
		}
	}

	while (operators.size() != 0) {
		rpn += operators.top();
		operators.pop();
	}
	return rpn;
}

double rpn::to_dec(string str){

	stack<double> nums;

	for (int i = 0; i < str.length(); i++){
		if (isDigi(str[i])){
			nums.push(str[i] - '0');
		} else {
			double pTop = nums.top();
			nums.pop();
			if (str[i] == '+'){
				nums.top() += pTop;
			} else if (str[i] == '-'){
				nums.top() -= pTop;
			} else if (str[i] == '*'){
				nums.top() *= pTop;
			} else {
				nums.top() /= pTop;
			}
		}
	}
	return nums.top();
}
