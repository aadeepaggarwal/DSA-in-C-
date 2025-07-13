class Solution {
public:
    char processStr(string s, long long k) {
        string res = s;
        vector<long long> lengths;
        long long len = 0;

        for (char op : res) {
            if (op >= 'a' && op <= 'z') {
                len++;
            } else if (op == '*') {
                if (len > 0) {
                    len--;
                }
            } else if (op == '#') {
 
                len *= 2;
            }
            lengths.push_back(len);
        }

        if (k >= len) {
            return '.';
        }

        for (int i = res.length() - 1; i >= 0; --i) {
            char op = res[i];
            long long len_before = (i > 0) ? lengths[i - 1] : 0;

            if (op == '#') {
                if (len_before > 0) {
                    k %= len_before;
                }
            } else if (op == '%') {
                if (len_before > 0) {
                    k = len_before - 1 - k;
                }
            } else if (op >= 'a' && op <= 'z') {
               if (k == len_before) {
                    return op;
                }
            }
        }

        return '.'; 
    }
};