#include<bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class String{
public:
    char *s; String()
    {
        s = NULL;
    }
    String(char *);
    String(int, char c=' ');
    string ToString();
    int length();
    String operator=(String);
    String operator=(char *);
    String operator+(String);
    char* GetPointer();
    int Compare(String);
    void Del (int, int);
    void Insert (int, String);
    int Find(String, String, int);
    void Replace (String, String, int);
    String Substring(int, int);
    String Concate(String);
    String Trim();
    void Clear();
    void Print();
};

String :: String(char *p)
{
    s = p;
}

int String :: length()
{
    int TheLength = 0;
    char *string = s;
    while(*string != '\0')
    {
        string++;
        TheLength++;
    }
    return TheLength;
}

String :: String(int n, char p)
{
    s = new char[n+1];
    for(int i=0;i<n;i++)*(s+i)= p;
    *(s+n)=0;
}

string String::ToString(){
    string ToString = s;
    return ToString;
}

String String::operator=(String a){
    this->s = a.s;
    return *this;
}

String String::operator=(char *d){
    this->s = d;
    return *this;
}

String String::operator+(String x){
    int i, n1=length(), n2=x.length();
    String z(n1+n2); char *t = z.s, *v=t;
    char *a=s;   for(i=0; i<n1; i++)*v++=*(a+i);
    a=x.s;       for(i=0; i<n2; i++)*v++=*(a+i);
    *v=0;
    z.s=t;
    s = t;
    return z;
}

char* String::GetPointer(){
    return s;
}

int String::Compare(String a){
    String b1;
    b1.s = s;
    if (b1.length() == a.length()){
        for (int i = 0; i < b1.length(); i++){
            if (*(s + i) != (*(a.s + i))) return 0;
        }
        return 1;
    }
    return 0;
}

int String::Find(String a, String b, int k){
    bool check = true;
    for (int i = k; i < a.length(); i++){
        if (a.s[i] == b.s[0]){
            for (int j = 0; j < b.length(); j++){
                if (a.s[i+j] != b.s[j]){
                check = false;
                break;
                }
            }
            if (check == true) return i;
            check = true;
        }
    }
    return 0;
}

void String::Del (int begin, int quant) {
		if(begin > 0 && begin + quant <= this->length ()+1) {
			char* res = new char[this->length() - quant + 1];
			int i = 0;
			for(; i < begin - 1; i++) {
				res[i] = this->s[i];
			}
			if(begin + quant - 1 < this->length ()) {
				for(int j = quant + begin - 1; j < this->length (); j++, i++) {
					res[i] = this->s[j];
				}
			}
			res[strlen(this->s) - quant] = '\0';
			this->s = res;
		}
	}

void String::Insert (int begin, String string1) {
		if(this->s != NULL) {
			char* res = new char[this->length () + string1.length() + 1];
			int i = 0;
			for(; i < begin - 1; i++) {
				res[i] = this->s[i];
			}
			for(int j = 0; j < string1.length (); j++, i++) {
				res[i] = string1.s[j];
			}
			for(int j = begin - 1; j < this->length (); j++, i++) {
				res[i] = this->s[j];
			}
			res[this->length () + string1.length()] = '\0';
			this->s = res;
		}
	}

void String::Replace (String string1, String string2, int mode = 0) {
		if(mode == 1) {
			while(this->Find (this->s, string1, 0) > 0) {
				int pos = this->Find (this->s, string1, 0);
				this->Del (pos, string1.length ());
				this->Insert (pos, string2);
			}
		}
		else {
			int pos = this->Find (this->s, string1, 0);
			if(pos > 0) {
				this->Del (pos, string1.length ());
				this->Insert (pos, string2);
			}
		}
	}

String String::Substring(int Start, int Count){
    String x(Count+1); char *px=x.s;
    int i;
    for(i=0; i<Count; i++)*px++=*(this->s+Start+i);
    *px=0;this->length()+1;
    return x;
}

String String::Concate (String x) {
		int i, n1=length(), n2=x.length();
    String z(n1+n2); char *t = z.s, *v=t;
    char *a=s;   for(i=0; i<n1; i++)*v++=*(a+i);
    a=x.s;       for(i=0; i<n2; i++)*v++=*(a+i);
    *v=0;
    z.s=t;
    return z;
	}

String String::Trim(){
    String b1;
    b1.s = s;
    while (*s == ' ')s++;
    int i = b1.length(), k = 0;
    while (*(s + i - 1) == ' '){
        i--;
        k++;
    }
    char d[100];
    for (int j = 0; j < b1.length() - k; j++) d[j] = s[j];
    String s4;
    s4.s = d;
    return s4;
}

void String::Clear(){this->s = "";}

void String::Print() {
    char a[100];
    for(int i = 0; i < this->length(); i++)
    {
        a[i] = s[i];
        cout << a[i];
    }
    cout << '\n';
	}

int main()
{
    String A("Hello");
    String B("World!");
    cout << A.length() << '\n';
    A.Print();
    A + B;
    A.Print();
    B.Print();
    String C = A.Concate(B);
    A.Print();
    B.Print();
    C.Print();

    cout << "\nCompare: " << A.Compare(B);
    cout << "\nFind: " << C.Find(A,B,0);
    cout << "\nSubstring: " ; C = A.Substring(0,4); C.Print();
    cout << "\nReplase: "; A.Replace(B,C,1);
}