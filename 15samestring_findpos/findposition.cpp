#include <iostream>
#include <string>
#include <vector>
using namespace std;


int strStr(string haystack, string needle)
{
	if(!needle.size())
		return 0;

	vector<int> pos;

	int hlen = haystack.size();
	int nlen = needle.size();
	int i = 0;
	for(i=0;i<hlen;i++)
	{
		if(haystack[i]==needle[0])
		{
			if((hlen-i)>=(nlen))
			{
				pos.push_back(i);
			}
			else
			{
				break;
			}
		}
	}
	if(!pos.size())
		return -1;
	int j=0;
	int pos_index=0;
	for(i=pos[pos_index];i<hlen;i++)
	{
		if(haystack[i]==needle[j])
		{
			j++;                
			if(j==nlen)
			{
				return i-j+1;//mississippi issip
			}
		}
		else
		{
			if(pos_index+1 == pos.size())
				break;

			i = pos[++pos_index];
			i--;
			j = 0;
		}
	}
	return -1;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int ans = strStr(s1,s2);
	cout<<ans;
	return 0;
}


//another answer
/*
int strStr(string haystack, string needle) {
        int nSizeH = haystack.size();
        int nSizeN = needle.size();
        if(!nSizeN) return 0;
        if(nSizeH<nSizeN) return -1;
        for(int i=0; i<nSizeH, nSizeH-i>=nSizeN; i++)
        {
            if(haystack[i]==needle[0])
            {
                int j=1;
                for(1; j<nSizeN; j++)
                {
                    if(haystack[i+j] != needle[j])
                        break;
                }
                if(j>=nSizeN) return i;
            }
        }
        return -1;
    }*/