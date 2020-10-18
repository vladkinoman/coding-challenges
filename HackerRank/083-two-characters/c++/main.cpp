#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

template <typename T1, typename T2>
struct less_first {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

// Complete the alternate function below.
int alternate(string s) {
    /* 0. Concerning data structures */
    // We use map to store quantities of each character  
    unordered_map<char, int> quantities;
    for (char c : s) {
        quantities[c]++;
    }
    // Now we need to sort the map. Unfortunately, map doesn't allow this to do
    // So, we have to copy its elements to a vector and sort it
    vector<pair<char, int> > mapcopy(quantities.begin(), quantities.end());
    sort(mapcopy.begin(), mapcopy.end(), less_first<char, int>());
    // Copy sorted elements back to the map
    quantities.clear();
    copy(mapcopy.begin(), mapcopy.end(), 
          inserter(quantities, quantities.begin()));
    // We use doubly linked list to quickly remove consecutive values
    list<char> list_s;
    for (char c: s) {
        list_s.push_back(c);
    }
    /* 1. Go through the list and remove characters 
        that have adjacent identical values */
    auto list_s_it = list_s.begin();
    char c = *list_s_it;
    while (++list_s_it != list_s.end()) {
        if (c == *list_s_it) { 
            list_s.remove(c);
            quantities.erase(c);
            list_s_it = list_s.begin();
        }
        c = *list_s_it;
    }
    
    /* 2. Try to remove additional characters 
        if an element has equal neighbors, we won't remove it */
    list_s_it = list_s.begin();
    auto list_s_last_it = prev(list_s.end(), 1);
    auto quantities_it = quantities.begin();
    while (quantities_it != quantities.end() && quantities.size() != 2) {

        while ((list_s_it = find(++list_s_it, list_s_last_it,
         quantities_it->first)) != list_s_last_it 
            && *prev(list_s_it, 1) != *next(list_s_it, 1))
            ;

        if (list_s_it == list_s_last_it) {
            list_s.remove(quantities_it->first);
            quantities.erase(quantities_it->first);
            list_s_it = list_s.begin();
            quantities_it = quantities.begin();
        } else {
            quantities_it++; 
        }
    }

    /* if there are only two characters in the map, return their amount */
    if (quantities.size() == 2) {
        return quantities.begin()->second +
         next(quantities.begin(), 1)->second;
    }

    return 0;
}

/* Debug code 

for (auto p: quantities) {
    cout << p.first << " " << p.second << " ";
}
cout << "\n";

for (char c: list_s) {
    cout << c << " ";
}
cout << "\n";
*/

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