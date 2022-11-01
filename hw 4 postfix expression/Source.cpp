#include<iostream>
#include<string>
#include<stack>
#include<vector>

std::vector<int> a;						//initialize vectors for displaying the expression value
std::vector<int> b{0};
void Calculation(std::string s)			//function takes in string
{
	std::stack<int> st;					//initialize stack and variables
	int c,i = 0;
	while (i< s.size())					//loop until end of input string
	{
		if (s == " ")					//ignore space
		{
			continue;					//keep going
		}
		 else if (isdigit(s.at(i)))			//if digit 
		{
			st.push(s.at(i) - '0');			//push to stack
		}
		else								//any operator
		{
			if (s.at(i) == '+')				//if it sees +
			{
				int a = st.top();			//set a to first number
				st.pop();					//remove from stack
				int b = st.top();			//set b to first number
				st.pop();					//remove from stack
				c = a + b;					//add the 2 numbers
				st.push(c);					//push that back into stack
			}
			else if (s.at(i) == '-')		//if it sees - 
			{
				int a = st.top();			//do same operations as above
				st.pop();
				int b = st.top();
				st.pop();
				c = b - a;					//but push the subtraction value
				st.push(c);
			}
			else if (s.at(i) == '*')		//if it sees *
			{
				int a = st.top();			//do same operations as above
				st.pop();
				int b = st.top();
				st.pop();
				c = a * b;					//but push the multiply value
				st.push(c);
			}
			else if (s.at(i) == '/')		//if it sees /
			{
				int a = st.top();			//do same operations as above
				st.pop();
				int b = st.top();
				st.pop();
				if (a == 0)					//if divide by 0
				{
					break;					//dont do
				}		
				else
				{
					c = a / b;				//push division value
					st.push(c);
				}
			}
			b.pop_back();					//remove any element
			b.push_back(st.top());			//push the new values in stack

			if (i == s.size() - 1)
			{
				a.push_back(st.top());		//do this if that
			}
		}
		i++;
	}
}
	
int main()
{
	std::string str;					//initialize these for doing the operands and getting expression
	std::vector<std::string> r;
	int f = 0;
	std::string e = "-1";
	std::string g = "0 /";
	while (1)						//infinite loop
	{
		std::getline(std::cin, str);		//user input
		if (str.find(e) != std::string::npos)			//if -1 entered, exit
		{
			break;
		}
		else if (str.find(g) != std::string::npos)		//if divide by 0, display invalid
		{
			std::cout << "Postfix Expression: " << str << " INVALID. " << std::endl;
			continue;			//keep going
		}
		r.push_back(str);			//push all of the user input to a vector
		Calculation(str);			//call the function

		f++;					//counter for each entry
	}
	
	for (auto k = 0; k < f; k++)		//loop through each entry
	{		
		std::cout << "Postfix Expression: " << r.at(k) << " Evaluation: " << a.at(k) << std::endl;		//display postfix expression and input per line
	}

	return 0; //done
}