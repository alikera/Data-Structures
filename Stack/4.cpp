#include <iostream>
#include <stack>

using namespace std; 

int main()
{
	string type;
	cin >> type;

	string line;
	cin >> line;

	if(type == "Preorder")
	{
		stack<long long int> my_stack;
		for (int i = line.size() - 1; i >= 0 ; i--)
		{
			if (isdigit(line[i]))
				my_stack.push((long long int)(line[i] - '0'));

			else
			{
				long long int n = my_stack.top();
				my_stack.pop();
				long long int m = my_stack.top();
				my_stack.pop();

				if (line[i] == '+')
					my_stack.push(n + m);

				else if (line[i] == '-')
					my_stack.push(n - m);

				else if (line[i] == '*')
					my_stack.push(n * m);
			}
		}
		cout << my_stack.top() << endl;
	}
	else if(type == "Postorder")
	{
		int len = line.length();
		for (int i = 0; i < len/2; ++i)
			swap(line[i], line[len-i-1]);

		stack<long long int> my_stack;
		for (int i = line.size() - 1; i >= 0 ; i--)
		{
			if (isdigit(line[i]))
				my_stack.push((long long int)(line[i] - '0'));

			else
			{
				long long int n = my_stack.top();
				my_stack.pop();
				long long int m = my_stack.top();
				my_stack.pop();

				if (line[i] == '+')
					my_stack.push(n + m);

				else if (line[i] == '-')
					my_stack.push(m - n);

				else if (line[i] == '*')
					my_stack.push(n * m);
			}
		}
		cout << my_stack.top() << endl;
	}

}
