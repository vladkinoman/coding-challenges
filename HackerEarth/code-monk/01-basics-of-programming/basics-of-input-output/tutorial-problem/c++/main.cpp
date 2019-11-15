#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

int main() {
    int N;
	cin >> N;
	char S[16];
	cin>> S;
    if (N < 0 || N > 10)
        throw std::invalid_argument("Check the number.");
    if (strlen(S) < 1 || strlen(S) > 15)
        throw std::invalid_argument("Check the size of the string.");
											// Reading input from STDIN
	cout << N * 2 << endl;		// Writing output to STDOUT
	cout << S << endl;
	return 0;
}