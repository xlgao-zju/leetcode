#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    
    map<char, int> m;
    map<char, int>::iterator itor;

    int start = 1;
    int i, lengthmax = 1;

    for (i = 1; i <= s.size(); i++) {
        if (m.count(s.at(i - 1))) {
            itor = m.find(s.at(i - 1));
            if (itor->second >= start)
                start = itor->second + 1;
        }
        m[s.at(i - 1)] = i;
        lengthmax = (lengthmax > (i - start + 1)) ? lengthmax : (i - start + 1);

    }
    return lengthmax;
}

int main()
{
    string s("aabcd");

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}

