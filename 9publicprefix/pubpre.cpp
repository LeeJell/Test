#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pubprefix="";
        char a='\0';
        char b='\0';
        int i,j=0;
        for(i=0;i<strs.size();i++)
        {
            if(strs[i]=="")
                return pubprefix;
        }
        for(i=0;i<strs.size();i++)
        {
            a = (strs[i])[i];
            for(j=0;j<strs.size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                b = (strs[j])[i];
                if(a==b)
                {
                    continue;
                }
                else
                {
                    pubprefix[i]='\0';
                    return pubprefix;
                }
            }
            if(j==strs.size())
            {
                pubprefix[i]=a;
            }
        }
        pubprefix[i]='\0';
        return pubprefix;
    }
};

int main()
{
	Solution s;
	string ans;
	vector<string> strs(2);
	strs.push_back("ab");
	strs.push_back("ab");
	ans=s.longestCommonPrefix(strs);
	cout<<"½á¹û£º"<<ans<<endl;
	return 0;
}
