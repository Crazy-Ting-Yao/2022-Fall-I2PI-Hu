#include<stdio.h>
#include<string.h>
int main(){
    char dict[62];
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<26;i++) dict[i] = 'A'+i;
        for(int i=0;i<26;i++) dict[i+26] = 'a'+i;
        for(int i=0;i<10;i++) dict[i+52] = '0'+i;
        int nums[62];
        for(int i=0;i<62;i++) nums[i]=0;
        char s[400];
        scanf("%s",s);
        int len = strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z') nums[s[i]-'A']++;
            else if(s[i]>='a'&&s[i]<='z') nums[s[i]-'a'+26]++;
            else if(s[i]>='0'&&s[i]<='9')nums[s[i]-'0'+52]++;
        }
        for(int i=61;i>0;i--){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                    char c = dict[j];
                    dict[j] = dict[j+1];
                    dict[j+1] = c;
                }
            }
        }
        for(int i=0;i<62;i++){
            if(nums[i]==0) break;
            for(int j=0;j<nums[i];j++){
                printf("%c",dict[i]);
            }
        }
        printf("\n");
    }
}