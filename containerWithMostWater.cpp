class Solution {
public:
    int minElement (int firstNumber, int secondNumber) {
        if (firstNumber >= secondNumber) {
            return secondNumber;
        }
        return firstNumber;
    }
    int maxElement (int firstNumber, int secondNumber) {
        if (firstNumber <= secondNumber) {
            return secondNumber;
        }
        return firstNumber;
    }
    
    int maxArea (vector<int>& height) {
        int areaHeight;
        int firstElement = 0;
        int secondElement = height.size() - 1;
        int area = 0;
        
        while (firstElement < secondElement) {
            areaHeight = minElement (height[firstElement], height[secondElement]);
            area = maxElement (area, areaHeight * (secondElement - firstElement));
            if (areaHeight == height[firstElement]) {
                firstElement++;
            } else if (areaHeight == height[secondElement]) {
                secondElement--;
            }
        }
        return area;
    }
};

/*
    int minElement (int firstNumber, int secondNumber) {
        if (firstNumber >= secondNumber) {
            return secondNumber;
        }
        return firstNumber;
    }
    int maxElement (int firstNumber, int secondNumber) {
        if (firstNumber <= secondNumber) {
            return secondNumber;
        }
        return firstNumber;
    }
    
    int maxArea (vector<int>& height) {
        int NumberOfLines = height.size();
        int areaHeight;
        int firstElement = 0;
        int secondElement = NumberOfLines - 1;
        int area = 0;
        
        while (firstElement < secondElement) {
            areaHeight = minElement (height[firstElement], height[secondElement]);
            area = maxElement (area, areaHeight * (secondElement - firstElement));
            while (firstElement < secondElement && height[firstElement] <= areaHeight) {
                firstElement++;
            }
            while (firstElement < secondElement && height[secondElement] <= areaHeight) {
                secondElement--;
            }
        }
        return area;
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
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
