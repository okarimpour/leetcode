class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0){
            return true;
        }
        if (s.size() % 2 != 0) {
            return false;
        }
        std::map<char, char> hashmap;
        hashmap.insert({'{', '}'});
        hashmap.insert({'(', ')'});
        hashmap.insert({'[', ']'});
        
        std::stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            if (hashmap.find(s[i]) != hashmap.end()) {
                stack.push(s[i]);
            }
            if (!stack.empty()) {
                if (s[i] == hashmap.find(stack.top())->second) {
                    stack.pop();
                }
            }
        }
        if (!stack.empty()) {
            return false;
        }
        return true;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
