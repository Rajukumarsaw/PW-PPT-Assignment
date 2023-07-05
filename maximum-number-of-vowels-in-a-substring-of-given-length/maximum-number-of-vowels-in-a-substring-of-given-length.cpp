class Solution {
public:
    int maxVowels(string s, int k) {
        int vol=0;
        int i=0;int j=0;
        int maxvol=0;
        for(j=0;j<k;j++){
            if(s[j]=='a' || s[j]=='e' || s[j]=='o' || s[j]=='i' || s[j]=='u' ){
                vol++;
            }
        }
        j--;
        maxvol=vol;
        while(j<s.size()-1){
             if(s[j+1]=='a' || s[j+1]=='e' || s[j+1]=='o' || s[j+1]=='i' || s[j+1]=='u' ){
                vol++;
            }
             if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' ){
                vol--;
            }
            i++;
            j++;
            maxvol=max(maxvol,vol);
        }
        return maxvol;
        }
        
};