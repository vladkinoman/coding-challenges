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

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};

void remove_additional_chars_without_equal_neighbors(list<char> &list_s,
        map<char, int> &quantities, vector<pair<char, int>> &mapcopy,
        int &q_size);

// Complete the alternate function below.
int alternate(string s) {
    /* 0. Concerning data structures */
    // We use map to store quantities of each character  
    map<char, int> quantities;
    for (char c : s) {
        quantities[c]++;
    }
    // Now we need to sort the map. Unfortunately, map doesn't allow this to do
    // So, we have to copy its elements to a vector and sort it
    vector<pair<char, int>> mapcopy_asc(quantities.begin(), quantities.end());
    sort(mapcopy_asc.begin(), mapcopy_asc.end(), less_first<char, int>());
    
    vector<pair<char, int>> mapcopy_desc(quantities.begin(), quantities.end());
    sort(mapcopy_desc.begin(), mapcopy_desc.end(), less_second<char, int>());
    // We use doubly linked list to quickly remove consecutive values
    list<char> list_s;
    for (char c: s) {
        list_s.push_back(c);
    }
    
    /* 1. Go through the list and remove characters 
        that have consecutive identical values */
    int q_size = quantities.size();
    auto list_s_it = list_s.begin();
    char c = *list_s_it;
    while (++list_s_it != list_s.end()) {
        if (c == *list_s_it) { 
            list_s.remove(c);
            quantities[c] = 0;
            q_size--;
            list_s_it = list_s.begin();
        }
        c = *list_s_it;
    }
    auto copy_list_s = list_s;
    map<char, int> copy_quantities = quantities;
    int copy_q_size = q_size;

    /* 2. Try to remove additional characters starting with rare occurrences
        if an element has equal neighbors, we won't remove it */
    remove_additional_chars_without_equal_neighbors (list_s, quantities, 
        mapcopy_asc, q_size);
    for (char c: list_s) {
        cout << c;
    }
    cout << "\n";
    /* if there are only two characters in the map, return their amount 
        we can take the first two items from the list cause they different*/
    int asc_sum = 0;
    if (q_size == 2) {
        asc_sum = quantities[*list_s.begin()] +
         quantities[*next(list_s.begin(), 1)];
    }

    list_s = copy_list_s;
    quantities = copy_quantities;
    q_size = copy_q_size;
    /* 3. Try to remove additional characters starting with frequent occurrences
        if an element has equal neighbors, we won't remove it */
    remove_additional_chars_without_equal_neighbors(list_s, quantities,
        mapcopy_desc, q_size);
    
    for (char c: list_s) {
        cout << c;
    }
    cout << "\n";
    /* if there are only two characters in the map, return their amount */
    int desc_sum = 0;
    if (q_size == 2) {
        desc_sum = quantities[*list_s.begin()] +
         quantities[*next(list_s.begin(), 1)];
    }

    return asc_sum > desc_sum ? asc_sum : desc_sum;
}

void remove_additional_chars_without_equal_neighbors(list<char> &list_s,
        map<char, int> &quantities, vector<pair<char, int>> &mapcopy,
        int &q_size) {
    
    auto list_s_it = list_s.begin();
    auto list_s_last_it = prev(list_s.end(), 1);
    for (auto mapcopy_it = mapcopy.begin(); 
    mapcopy_it != mapcopy.end() && q_size != 2; mapcopy_it++) {
        if (mapcopy_it->second == 0 || quantities[mapcopy_it->first] == 0) 
            continue;

        while ((list_s_it = find(++list_s_it, list_s_last_it,
         mapcopy_it->first)) != list_s_last_it
            && *prev(list_s_it, 1) != *next(list_s_it, 1))
        ;

        if (list_s_it == list_s_last_it) {
            list_s.remove(mapcopy_it->first);
            mapcopy_it->second = 0;
            quantities[mapcopy_it->second] = 0;
            q_size--;
            list_s_last_it = prev(list_s.end(), 1);
        }

        list_s_it = list_s.begin();
    }
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
