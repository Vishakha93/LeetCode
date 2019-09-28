class Solution {
public:
    vector<vector<string>> groupWords(vector<string>& words, int maxWidth) {  
        int sum = 0, rowSum, pos = 0;
        vector<vector<string>> res;
        vector<string> temp;
        
        for(int i = 0;  i < words.size(); i++) {
            sum = sum + words[i].length();
            rowSum = sum + (i - pos);
            if(rowSum > maxWidth) {
                sum = words[i].length();
                pos = i;
                res.push_back(temp);
                temp.clear();
            }
            temp.push_back(words[i]);
        }
        
        res.push_back(temp);
        return res;
    }
    
    string createSentence(vector<string> &sentenceWords, int maxWidth, int isLast) {
        
        int sum = 0;
        for(int i = 0; i < sentenceWords.size(); i++) {
            sum = sum + sentenceWords[i].length();
        }
        
        int spaceCount = maxWidth - sum;
        if(sentenceWords.size() == 1) {
            string s = sentenceWords[0];
            for(int i = 0; i < spaceCount; i++) {
                s = s + " ";
            }
            return s;
        }
        
        vector<int> gaps(sentenceWords.size(), 0);
        int slotCount = gaps.size() - 1;
        if(isLast == 0) {
            int i = 0;
            while(spaceCount > 0) {
                gaps[i]++;
                i = (i + 1) % slotCount;
                spaceCount--;
            }
        }
        else {
            int i;
            for(i = 0; i < slotCount; i++) {
                gaps[i] = 1;
                spaceCount--;
            }
            gaps[i] = spaceCount;
            slotCount++;
        }
        
        string s = ""; 
        for(int i = 0; i < slotCount; i++) {
            s = s + sentenceWords[i];
            for(int j = 0; j < gaps[i]; j++) {
                s = s + " ";
            }
        }
        
        if(isLast == 0) {
            s = s + sentenceWords[sentenceWords.size()-1];
        }
        return s;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ans;
        vector<vector<string>> groupedWords = groupWords(words, maxWidth);
        for(int i = 0; i < groupedWords.size(); i++) {
            int isLast = i == (groupedWords.size() - 1);
            string s = createSentence(groupedWords[i], maxWidth, isLast);
            ans.push_back(s);
        }
        
        return ans;
    }
};
