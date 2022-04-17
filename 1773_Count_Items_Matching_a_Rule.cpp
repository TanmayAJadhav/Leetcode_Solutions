// You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by 
// two strings, ruleKey and ruleValue.The ith item is said to match the rule if one of the following is true:
// ruleKey == "type" and ruleValue == typei.
// ruleKey == "color" and ruleValue == colori.
// ruleKey == "name" and ruleValue == namei.
// Return the number of items that match the given rule.

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string rulekey, string ruleValue) {
        int cnt = 0;
        int j;
        if(rulekey == "type")
        {
            j = 0;
        }
        else if(rulekey == "color")
        {
            j = 1;
        }
        else if(rulekey == "name")
        {
            j = 2;
        }
        
        for(int i = 0; i < items.size(); i++)
        {
            if(items[i][j] == ruleValue)
            {
                cnt++;
            }
        }
        return cnt;
    }
};