#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> split_string(string);


// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	
	if (!(scores.capacity() >= 1 && scores.capacity() <= 2 * 100000)) // 10^5
		throw;
	if (!(alice.capacity() >= 1 && alice.capacity() <= 2 * 100000))  // 10^5
		throw;

	vector<int> leader_ranks(scores.size());
	vector<int> alice_ranks(alice.size());

	// filling leader_ranks array
	for (int i = 0, r = 0; i < scores.size(); i++)
	{
		if ((i != 0 && scores[i - 1] < scores[i])
			|| !(scores[i] >= 0 && scores[i] <= 1000000000)) // 10^9
			throw;
		if (i != 0 && scores[i] == scores[i - 1]) leader_ranks[i] = r;
		else leader_ranks[i] = ++r;
	}

	// main part of algorithm
	for (int i = 0, j = leader_ranks.size() - 1; i < alice.size(); i++)
	{
		if ((i != 0 && alice[i - 1] > alice[i])
			|| !(alice[i] >= 0 && alice[i] <= 1000000000)) // 10^9
			throw;
		for (; true; j--)
		{
			if (alice[i] == scores[j])
			{
				alice_ranks[i] = leader_ranks[j];
				break;
			}
			else if (alice[i] < scores[j])
			{
				if (j + 1 != leader_ranks.size())
					alice_ranks[i] = leader_ranks[j + 1];
				else
					alice_ranks[i] = leader_ranks[j] + 1;
				break;
			}
			else if (j == 0)
			{
				alice_ranks[i] = leader_ranks[j];
				break;
			}
		}
	}

	return alice_ranks;
}

int main()
{
	// ofstream fout(getenv("OUTPUT_PATH"));

	int scores_count;
	cin >> scores_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string scores_temp_temp;
	getline(cin, scores_temp_temp);

	vector<string> scores_temp = split_string(scores_temp_temp);

	vector<int> scores(scores_count);

	for (int i = 0; i < scores_count; i++) {
		int scores_item = stoi(scores_temp[i]);

		scores[i] = scores_item;
	}

	int alice_count;
	cin >> alice_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string alice_temp_temp;
	getline(cin, alice_temp_temp);

	vector<string> alice_temp = split_string(alice_temp_temp);

	vector<int> alice(alice_count);

	for (int i = 0; i < alice_count; i++) {
		int alice_item = stoi(alice_temp[i]);

		alice[i] = alice_item;
	}

	vector<int> result = climbingLeaderboard(scores, alice);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << "\n";
		}
	}

	cout << "\n";

	// fout.close();

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
