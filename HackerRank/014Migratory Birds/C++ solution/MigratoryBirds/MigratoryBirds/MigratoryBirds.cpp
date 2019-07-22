#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

template<class T> struct bird_type
{
	T type_number;
	T sights;
};

template <class T> struct bird_type_less
	: public binary_function<T, T, bool>
{
	bool operator()(const T& x, const T& y) const
	{
		return x->sights < y->sights
			|| x->sights == y->sights && x->type_number > y->type_number;
	}
};

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) 
{	
    int number_of_types = 5;
	if (arr.capacity() < number_of_types || arr.capacity() > 2 * 100000)
		throw;
	
	vector<bird_type<int>*> v(number_of_types);
	for (int i = 0; i < number_of_types; i++)
		v[i] = new bird_type<int>{i + 1, 0};
	
	for(int i = 0; i < arr.capacity(); i++)
		switch (arr.at(i))
		{
		case 1: case 2: case 3: case 4: case 5:
			v[arr.at(i) - 1]->sights++;
			break;
		default:
			throw; 
			break;
		}

	sort(v.begin(), v.end(), bird_type_less<bird_type<int>*>());
	
	return v[number_of_types - 1]->type_number;
}

int main()
{
	//HackerRank's tricks:
	//ofstream fout(getenv("OUTPUT_PATH"));

	string arr_count_temp;
	getline(cin, arr_count_temp);

	int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(arr_count);

	for (int i = 0; i < arr_count; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int result = migratoryBirds(arr);

	cout << result << "\n";

	//HackerRank's tricks:
	//fout.close();

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string& str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
