//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <sysdefs.h>
#include <string>
#include <set>
#include <map>
#include "Unit1.h"
#include <Windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(OpenDialog1->Execute()){
                String s = OpenDialog1->FileName;
                Memo1->Lines->LoadFromFile(s);
        }
}
//---------------------------------------------------------------------------
//Global
const char punct[] = {'.', ',', ':', ';', '?', '!', '\'',
                        '\"', '<', '>', '`', '~', '@', '#', '$', '%', '^',
                        '&', '*', '//', '+', '¹', '-'};
std::map<String, int> words;
std::map<String, int>::iterator it;
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        std::set<char> pt;
        for(int k = 0; k < sizeof(punct); k++){
                pt.insert(punct[k]);
        }

        int i = 0;
        AnsiString reserve;
        while(i < Memo1->Lines->Count){
                AnsiString s = Memo1->Lines->Strings[i];
                int j = 1;
                while(j <= s.Length()){
                        while(j <= s.Length() && s[j] == ' ') j++;
                        AnsiString temp = reserve;
                        reserve = "";
                        while(j <= s.Length() && s[j] != ' '){
                                temp += s[j];
                                j++;
                        }
                        if(!temp.IsEmpty()){
                                if(pt.find(temp[temp.Length()]) != pt.end()){
                                      if(words.find(temp[temp.Length()]) == words.end()){
                                        ListBox1->Items->Add(temp[temp.Length()]);
                                        words[temp[temp.Length()]] = 1;
                                      }
                                      else words[temp[temp.Length()]]++;
                                      if(temp[temp.Length()]=='-' && j == s.Length() + 1){
                                            temp.Delete(temp.Length(), 1);
                                            reserve = temp;
                                      }
                                      else temp.Delete(temp.Length(), 1);
                                }
                                if(words.find(temp) == words.end() && reserve.IsEmpty() && !temp.IsEmpty()){
                                        words[temp] = 1;
                                        ListBox1->Items->Add(temp);
                                }
                                else if (words.find(temp) != words.end()) words[temp]++;
                        }
                }
                i++;
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
		int total = 0;
       for(int i = 0; i < sizeof(punct); i++){
                if(words.find(punct[i]) != words.end()){
                        AnsiString temp = punct[i]; //
                        AnsiString temp2 = IntToStr(words[punct[i]]);
                        ListBox2->Items->Add(temp + " (" + temp2 + ')');
                        total += words[punct[i]];
                }
       }
       Label1->Caption = Label1->Caption + ' ' +IntToStr(total);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
		int total = 0;
        for(it = words.begin(); it != words.end(); it++){
                AnsiString temp = it->first;
                bool allDigit = true;
                for(int i = 1; i <= temp.Length(); i++){
                        if((temp[i]<'0' || temp[i]>'9') && temp[i]!= '.'){
                                allDigit = false;
                                break;
                        }
                }
                if(allDigit && temp != '.'){

                        AnsiString temp = it->first;
                        AnsiString temp2 = IntToStr(it->second);
                        ListBox3->Items->Add(temp + " (" + temp2 + ')');
                        total += it->second;
                }
        }
        Label2->Caption = Label2->Caption + ' ' + IntToStr(total);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
		int total = 0;
		for(it = words.begin(); it != words.end(); it++){
				AnsiString temp = it->first;
				bool eng = true;
				for(int i = 1; i <= temp.Length(); i++){
						eng = eng && ((temp[i]>='a' && temp[i]<='z') ||
									 (temp[i]>='A' && temp[i]<='Z'));
				}
				if(eng){
						AnsiString temp = it->first;
						AnsiString temp2 = IntToStr(it->second);
						ListBox5->Items->Add(temp + " (" + temp2 + ')');
						total += it->second;
				}
		}
		Label3->Caption = Label3->Caption + ' ' + IntToStr(total);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{

        int total = 0;
        for(it = words.begin(); it != words.end(); it++){
                AnsiString temp = it->first;
                bool rus = true;
                for(int i = 1; i <= temp.Length(); i++){
                        rus = rus && (temp[i]>='А' && (int)temp[i]<='я');
                }
                if(rus){
                        AnsiString temp = it->first;
                        AnsiString temp2 = IntToStr(it->second);
                        ListBox4->Items->Add(temp + " (" + temp2 + ')');
                        total += it->second;
                }
        }
        Label4->Caption = Label4->Caption + ' ' + IntToStr(total);
}
//---------------------------------------------------------------------------

