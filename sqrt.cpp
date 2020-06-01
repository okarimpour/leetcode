class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) {
            return 0;
        } else if (x < 2) {
            return 1;
        }
        
        long int mid = x / 2;
        
        if(mid*mid < x) {
            return sortingFunction (mid, x, x);
        } else if (mid*mid > x) {
            return sortingFunction (1, mid, x);
        }
        
        return mid;
    }
    
    int sortingFunction (int l, int h, int x) {
        long int m = (l + h) / 2;
        
        if (l == m) {
            return l;
        }
        if(m*m < x) {
            return sortingFunction (m, h, x);
        } else if (m*m > x) {
            return sortingFunction (l, m, x);
        } else if (m*m == x) {
            return m;
        }
        
        throw "No answer";
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
