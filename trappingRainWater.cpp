class Solution {
public:
    int trap(vector<int>& height) {
        int maxRight = 0;
        int maxLeft = 0;
        int left = 0;
        int right = height.size() - 1;
        int water = 0;
        
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    water += maxLeft - height[left];
                }
                left++;
            } else if (height[right] < height[left]) {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    water += maxRight - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

/*
        if (height.size() < 3) {
            return 0;
        }

        int element = 0;
        int water = 0;
        int tempElement, tempWater;

        while (height[element] < height[element + 1] && element < height.size()) {
            element++;
        }   
        while (element < height.size() - 1) {
            tempElement = element;
            tempWater = 0;
            while(height[tempElement + 1] < height[element] && tempElement < height.size() - 1) {
                tempWater += height[element] - height[tempElement + 1];
                tempElement++;
            }
            if (tempElement == height.size() - 1 && height[tempElement] < height[element]) {
                element++;
            } else {
                water += tempWater;
                element = tempElement + 1;
            }
        }
        return water;
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
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
