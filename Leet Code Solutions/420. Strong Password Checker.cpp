class Solution {
public:
    int strongPasswordChecker(string s) {
        bitset<3> requirements{111}; 
        list<int> repeats;
        auto it = s.begin();
        auto it2 = s.end();
        while (it != s.end()) {
            if (*it != *it2) {
                if (requirements.test(0) && islower(*it))
                    requirements.reset(0);
                if (requirements.test(1) && isupper(*it))
                    requirements.reset(1);
                if (requirements.test(2) && isdigit(*it))
                    requirements.reset(2);
            } else {
                while (it != s.end() && *it == *it2)
                    ++it;
                if (distance(it2, it) != 2)
                    repeats.push_back(distance(it2, it));
                if (it != s.end())
                    continue;
                else
                    break;
            }
            it2 = it;
            ++it;
        }
        repeats.sort([](const int &lhs, const int &rhs) { return (lhs % 3) < (rhs % 3); });
        int ans{0}, len{static_cast<int>(s.size())};
        while (len > 20) {
            if (!repeats.empty()) {
                if (repeats.front() == 3) {
                    repeats.pop_front();
                }
                else {
                    --repeats.front();
                    repeats.sort([](const int &lhs, const int &rhs) { return (lhs % 3) < (rhs % 3); });
                }
                ++ans;
                --len;
            }
            else {
                ans += len - 20;
                len = 20;
            }
        }
        int rep_ins{0};
        while (!repeats.empty()) {
            rep_ins += repeats.front() / 3;
            repeats.pop_front();
        }
        if ((len + rep_ins) < 6) {
            rep_ins += 6 - len - rep_ins;
        }
        ans += max(static_cast<int>(requirements.count()), rep_ins);
        return ans;
    }
};
