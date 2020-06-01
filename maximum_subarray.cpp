class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums [0];
        int totalMax = nums [0];
        int element;
        
        for (element = 1; element < nums.size(); ++element) {
            currentMax = std::max (currentMax + nums[element], nums[element]);
            totalMax = std::max (totalMax, currentMax);
        }
        
        return totalMax;
    }
};

/*
        //std::vector<int> sorted_nums (nums, nums + nums.size());
        //std::sort (sorted_nums.begin(), sorted_nums.begin() + sorted_nums.size());
        //int max = sorted_nums[sorted_nums.size() - 1];
        int max = nums[0];
        int sum;
        for (int i = 0; i < nums.size() - 1; ++i) {
            sum = nums[i];
            max = std::max (sum, max);
            
            for (int j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                max = std::max (sum, max);
            }
        }
        
        return std::max (max, nums[nums.size() - 1]);
*/

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}