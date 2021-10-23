class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> table(size + 1, 0);
        
        table[0] = 1;
        for (auto i = 1; i <= size; ++i)
        {
            if (s[i - 1] != '0')
            {
                table[i] += table[i - 1];
            }
            
            if(i - 2 >= 0 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] - '0' <= 6)))
            {
                table[i] += table[i - 2];
            }
        }
        
        return table[size];
    }
};
