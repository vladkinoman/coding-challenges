#include <iostream>
#include <stdexcept>
using namespace std;

int count_one(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
	int T;
	cin >> T;
	if (T < 1 || T > 1000)
	    throw invalid_argument("");
	
	for (int i = 0; i < T; i++) {
	    int N;
        cin >> N;
        if (N < 1 || N > 1000)
            throw invalid_argument("");
	    cout << count_one(N) << endl;
	}
	
	return 0;
}
