#include <string>

using namespace std;

namespace rpn{
	/*
		Is Digit
		@param A character "c"
		@return If character "c" is a recognized digit
	*/
	bool isDigi(char c);

	/*
		Is Digit
		@param A character "c"
		@return If character "c" is a recognized operand
	*/
	bool isOper(char c);

	/*
		Remove Spaces
		@param A string of an expression "str"
		@return the passed expression "str" with no spaces
	*/
	string remSpace(string str);

	/*
		To Reverse Polish Notation
		@param A string of an expression "str"
		@return The passed expression in rpn	
	*/
	string to_rpn(string str);

	/*
		To decimal
		@param A string of an expression in rpn "rpn"
		@return The passed expression in its calculated decimal form
	*/
	double to_dec(string str);
}
