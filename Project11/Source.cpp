#include <iostream>
using namespace std;
class MyString
{
    char* str; // указатель на строку
    int length; // длина строки
    static int count;
public:
    // методы класса
    MyString();
    MyString(MyString& obj);
    MyString(const char* s);
    ~MyString();
    void InputMyString();
    void PrintMyString(); 
    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* str);
    int  MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& b); 
    void MyDelChr(char c); 
    int MyStrCmp(MyString& b); 
    static int GetCount();
};

int MyString::count = 0;

MyString::MyString()
{
    str = nullptr;
    length = 81;
    count++;
}

MyString::MyString(MyString& obj)
{
    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    length = this->MyStrLen();
    count++;
}

MyString::MyString(const char* s)
{
    str = new char[strlen(s) + 1];
    strcpy_s(str, strlen(s) + 1, s);
    length = strlen(s);
    count++;
}

MyString::~MyString()
{
    delete[]str;
}

void MyString::InputMyString()
{
    char buff[81];
    cout << "Enter string -> ";
    cin.getline(buff, 81);
    if (str != nullptr)
    {
        delete[]str;
    }
    str = new char[strlen(buff) + 1];
    strcpy_s(str, strlen(buff) + 1, buff);
}

void MyString::PrintMyString() 
{
    cout << str;
}

void MyString::MyStrCat(MyString& b) 
{
    int buffsize = 81;
   strcat_s(str, buffsize , b.str);
}
void MyString::MyDelChr(char c)
{
    char buff[81];
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] != c)
        {
            buff[j++] = str[i];

        }
    }
    buff[j] = '\0';
    strcpy_s(str, 81, buff);
}


int MyString::MyStrLen()
{
    int counter = 0;
    for (int i = 0; i < length; i++) {
        counter++;
    }
    return counter;
}
int MyString::MyStrCmp(MyString& b)
{
    int string1 = strlen(str);
    int string2 = strlen(b.str);
    if (string1 > string2) {
        return 1;
    }
    else if (string2 > string1) {
        return -1;
    }
    else {
        return 0;
    }
}
int MyString::GetCount()
{
    return count;
}
void MyString::MyStrcpy(MyString& obj) 
{
    if (str != nullptr)
    {
        delete[]str;
    }
    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
}
int MyString::MyChr(char c) 
{
    int counter = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            cout << "Found. Index: " << i + 1 << endl;
            counter++;
            return 1;
        }
    }
    if (counter == 0) {
        return -1;
    }

}
bool MyString::MyStrStr(const char* str)
{
    int i = 0, j = 0;
    int temp;
    for (i = 0; i < strlen(this->str) - strlen(str); i++)
    {
        temp = i;
        for (j = 0; j < strlen(str); j++)
        {

            if (this->str[temp] == str[j])
            {
                if (j == strlen(str) - 1)
                    return 1;
                temp++;
            }
            else
                break;
        }
    }
    return 0;
}

int main() {
    MyString string1("Hello");
    MyString string2("World");
    string1.PrintMyString(); cout << endl;
    string2.PrintMyString();
    cout << endl << "MyStrLen: " << endl;
    cout << string1.MyStrLen();
   
    cout << endl << endl << "MyStrStr: " << endl;
    if (string2.MyStrStr("orl") == 1) {
        cout << "Found";
    }
    else {
        cout << "Not Found";
    }
   
    cout << endl << endl << "MyChr: " << endl;
    string1.MyChr('e');
    
    cout << endl << endl << "MyStrCmp: " << endl;
    cout << string1.MyStrCmp(string2);

    cout << endl << endl << "MyStrCpy: " << endl;
    string1.MyStrcpy(string2);
    string1.PrintMyString();

    cout << endl << endl << "MyStrCat: " << endl;
    string1.MyStrCat(string2);
    string1.PrintMyString();

    cout << endl << endl << "StringInput: " << endl;
   string2.InputMyString();
    string2.PrintMyString();
    
    cout << endl << endl << "MyDelChar: " << endl;
    MyString string3("Blanche");
    string3.PrintMyString();
    string3.MyDelChr('c');
    cout << endl;
    string3.PrintMyString();
    cout << endl <<"Count: " << string1.GetCount();
}