#include <string>
#include <iostream>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

	return "something";
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string result = encryption(s);

	cout << result << "\n";

	//fout.close();

	return 0;
}