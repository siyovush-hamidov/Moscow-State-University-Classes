#include <iostream>
#include <fstream>
using namespace std;

class CFile
{
    private:
        string FileName; int FileSize; bool IsOpened;
        ifstream ifs; ofstream ofs;
    public:
        CFile();
        CFile(string);
        bool Opened(int);
        bool Opened(string, int);
        bool Closed();
        bool Closed(string);
        void Read(string, string);
        void Write(string, string);
        int GetPosition(string);
        int GetLength(string);
        int Size(string);
        bool CursorEOF(string);
        bool CursorEOLn(string);
        DeleteFile(string);
        RenameFile(string, string);
        string GetFullFileName();
        string GetFileDirective(string);
        string GetFileDrive(string);
        string GetExtentionOfFile(string);
        string GetFileName(string);
        string GetFilePath(string);
        bool ExistenceOfFile(string);
};
CFile :: CFile()
{
    const char a[256] = "C:\\Users\\User\\Default.txt";
    FileName = "Default.txt"; FileSize = 0; IsOpened = true;
    ofs.open("C:\\Users\\User\\Default.txt", ofs.in);
}

CFile :: CFile(string NameOfFile)
{
    FileName = NameOfFile; FileSize = 0; IsOpened = true;
    ofs.open("C:\\Users\\User\\" + FileName, ios::in|ios::out|ios::app);
}

bool CFile :: Opened(int OpenFor)
{
    cout << ofs.is_open() << endl;
    return(IsOpened);
}

bool CFile :: Opened(string NameOfFile, int OpenFor)
{
    FileName = "C:\\Users\\User\\" + NameOfFile;
    // switch (OpenFor)
    // {
    // case 0:
    //     ofs.open(FileName, ifs.in);
    //     OpenFor1 = "reading (0)";
    //     // input || File open for reading: the internal stream buffer supports input operations.
    //     break;
    // case 1:
    //     ifs.open(FileName, ifs.out);
    //     OpenFor1 = "writing (1)";
    //     // output || File open for writing
    //     break;
    // case 2:
    //     ifs.open(FileName, ifs.ate);
    //     OpenFor1 = "appending (2)";
    //     // at end || The output position starts at the end of the file.
    //     break;
    // case 3:
    //     ifs.open(FileName, ifs.trunc);
    //     OpenFor1 = "discarding the file (3)";
    //     // truncate || Any contents that existed in the file before it is open are discarded.
    //     break;
    // default:
    //     ifs.open(FileName, ifs.in);
    //     break;
    // }
    
    // if(ifs.is_open()) IsOpened = true;
    // if(IsOpened)
    // {
    //     cout << "The file is opened for " + OpenFor1 << '\n';
    // }
    // else cout<<"The file is not opened\n";
    // return(IsOpened);
}

bool CFile :: Closed()
{
    cout << ifs.is_open();
    return(IsOpened);
}

bool CFile :: Closed(string NameOfFile)
{
    cout << ifs.is_open();
    return(IsOpened);
}

void CFile :: Read(string x, string NameOfFile)
{

}

void CFile :: Write(string x, string NameOfFile)
{
    string PathName = "C:\\Users\\User\\" + NameOfFile;
    ofs.open(PathName);
    ofs << x;
    ofs.close();
}
int main()
{   
    CFile MainFile;
    MainFile.Opened(2);
    MainFile.Closed();

    MainFile.Write("Hello", "Hello.txt");
}