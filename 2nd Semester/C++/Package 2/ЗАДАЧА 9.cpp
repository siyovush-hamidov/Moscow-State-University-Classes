#include <iostream>
using namespace std;  

bool cmpr_2_words(string s1, string s2){
    for(int i = 0; i < min(s1.length(), s2.length()); i++){
        if(s1[i]>s2[i]) return true; /// abcd abdd
        else if(s1[i]<s2[i]) return false;
    }
    return s1.length()>s2.length();
}

void sort_string(string str[], int s){
    bool check = true;
    while(check){
        check = false;
        for(int i = 0; i < s - 1; i++){
            if(cmpr_2_words(str[i], str[i+1])){
                swap(str[i], str[i+1]);
                check = true;
            }
        } 
    }
}
int main()
{
    char snt[50];
    cin.get(snt, 50);
    char* p = snt;
    string words[50];
    int n = 0;
    while(*p != '\0'){
        string temp;
        while(*p != '\0' && *p != ' '){
            temp += *p++;
        }
        words[n++] = temp;
        if(*p == '\0') break;
        p++;
    }
    sort_string(words, n);
    for(int i = 0; i < n; i++) cout << words[i] << '\n';
    return 0;
}
