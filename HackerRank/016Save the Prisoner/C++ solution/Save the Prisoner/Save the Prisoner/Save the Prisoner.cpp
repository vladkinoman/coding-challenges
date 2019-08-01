//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {
	// constraints
	if (!(n >= 1 && n <= pow(10, 9)))
		throw;
	if (!(m >= 1 && m <= pow(10, 9)))
		throw;
	if (!(s >= 1 && s <= n))
		throw;
	
	// brute-force
	/* int i = s;
	while(m != 0)
	{
		if (--m != 0) i++;
		if (i > n) i = 1;
	}*/

	// constant
	/*
	if(m % n != 0) // all prisoners haven't equal amount of candy
	{
		if(m > n)
		{
			//i = m % n + s - 1;
			//i = (m + s) % n - 1;
			i = (m + s) % n - 1;
		}
		else
		{
			//i = abs(n - m - s) - 1;
			//i = m % n + s - 1;
			i = (m + s) % n - 1;
		}
	}
	else // all prisoners have equal amount of candy
	{
		if (n + s - 1 != n) i = s - 1;
		else                i = n;
	}
	*/

	return (m % n != 0) ? (m > n ? m % n + s - 1 : (m + s) % n - 1
		/*(m + s > n ? : abs(m - n) + s - 1)*/)
		: (n + s - 1 != n ? s - 1 : n); // all prisoners have equal amount of candy
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	if (!(t >= 1 && t <= 100))
		throw;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string nms_temp;
		getline(cin, nms_temp);

		vector<string> nms = split_string(nms_temp);

		int n = stoi(nms[0]);

		int m = stoi(nms[1]);

		int s = stoi(nms[2]);

		int result = saveThePrisoner(n, m, s);

		cout << result << "\n";
		
	}

	//fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
		});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
