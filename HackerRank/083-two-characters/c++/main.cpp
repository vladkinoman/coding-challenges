#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    /* 0. Use data structures */
    // We use map to store quantities of each character  
    unordered_map<char, int> quantities;
    for (char c : s) {
        quantities[c]++;
    }
    // We use doubly linked list to quickly remove consecutive values
    list<char> list_s;
    for (char c: s) {
        list_s.push_back(c);
    }
    /* 1. Go through the list and remove characters 
        that have adjacent identical values */
    auto list_s_iter = list_s.begin();
    char c = *list_s_iter;
    while (++list_s_iter != list_s.end()) {
        if (c == *list_s_iter) { 
            list_s.remove(c);
            quantities.erase(c);
            list_s_iter = list_s.begin();
        }
        c = *list_s_iter;
    }
    /* 2. Try to remove additional characters 
        if an element has equal neighbors, we won't remove it*/
    list_s_iter = list_s.begin();
    auto list_s_last_it = prev(list_s.end(), 1);
    auto quantities_it = quantities.begin();
    while (quantities_it != quantities.end() && quantities.size() != 2) {
        
        while ((list_s_iter = find(++list_s_iter, list_s_last_it,
         quantities_it->first)) != list_s_last_it 
            && *prev(list_s_iter, 1) != *next(list_s_iter, 1))
            ;

        if (list_s_iter == list_s_iter) {
            list_s.remove(quantities_it->first);
            quantities.erase(quantities_it->first);
            list_s_iter = list_s.begin();
        } else {
            quantities_it++; 
        }
    }

    // Debug
    for (char c: list_s) {
        cout << c << " ";
    }
    cout << "\n";

    if (quantities.size() == 2) {
        return quantities.begin()->second + next(quantities.begin(),1)->second;
    }

    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}