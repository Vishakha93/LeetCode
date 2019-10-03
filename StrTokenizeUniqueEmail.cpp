class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {  
        set<string> uniqueEmails;
        for (int i=0; i<emails.size(); i++) {
            stringstream ss(emails[i]);
            vector<string> words;
            string tmp;
            while(getline(ss, tmp, '@')) {
                words.push_back(tmp);
            }
            
            string localName = words[0];
            string domainName = words[1];
            string modifiedEmail = "";
            for(int j=0; j<localName.length(); j++) {
                if (localName[j] == '+') {
                    break;
                }
                if(localName[j] == '.') {
                    continue;
                }
                modifiedEmail = modifiedEmail + localName[j];
            }
            modifiedEmail = modifiedEmail + '@' + domainName;
            uniqueEmails.insert(modifiedEmail);
        }
        return uniqueEmails.size();
    }
};
