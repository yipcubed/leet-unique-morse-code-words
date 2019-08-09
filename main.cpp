#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

// https://leetcode.com/problems/unique-morse-code-words/

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        static const int a = 'a';
        static const vector<string> m
                {".-", "-...", "-.-.", "-..", ".",
                 "..-.", "--.", "....", "..", ".---",
                 "-.-", ".-..", "--", "-.",
                 "---", ".--.", "--.-", ".-.", "...", "-",
                 "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> found;
        ostringstream ss;
        for (auto &w : words) {
            for (auto &c: w) {
                ss << m[c - a];
            }
            found.insert(ss.str());
            ss.str("");
        }
        return static_cast<int>(found.size());
    }
};

void test1() {
    vector<string> words{"gin", "zen", "gig", "msg"};

    cout << "2 ? " << Solution().uniqueMorseRepresentations(words) << endl;
}

void test2() {

}

void test3() {

}