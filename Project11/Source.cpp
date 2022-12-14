#include <iostream>
using namespace std;
class MyString
{
    char* str; // ????????? ?? ??????
    int length; // ????? ??????
    static int count;
public:
    // ?????? ??????
    MyString();
    MyString(const MyString& obj);
    MyString(const char* s);
    MyString(MyString&& obj2);
    ~MyString();
    void InputMyString();
    void PrintMyString()const; 
    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* str)const;
    int  MyChr(char c)const;
    int MyStrLen()const;
    void MyStrCat(MyString& b)const; 
    void MyDelChr(char c)const; 
    int MyStrCmp(MyString& b)const; 
    static int GetCount();
    void operator()();
    operator char* ();
    operator int();
    char operator[](int index);
    MyString& operator=(const MyString& obj);
    MyString& operator=(MyString&& obj2);
    MyString(initializer_list<char> a);
};

int MyString::count = 0;

MyString::MyString(initializer_list<char> a)
{
    cout << "Initializer_list constructor\n";
    length = a.size(); // ???????? ?????? 
    str = new char[length];
    for (auto x = a.begin(); x != a.end(); x++)
    {
        *str = *x;
        str++;
    }
    str -= length;// ???????? ????????? ?? ?????? ??????? 


}

MyString::MyString(MyString&& obj2) // move constructor
{
    str = obj2.str;
    obj2.str = nullptr;

    length = obj2.length;
    obj2.length = 0;
}

MyString& MyString::operator=(MyString&& obj2)
{
    if (str != nullptr)
    {
        delete[] str;
    }
    str = obj2.str; // 
    obj2.str = nullptr;

    length = obj2.length;
    obj2.length = 0;

    return *this;
}

void MyString::operator()()
{
    cout << str;
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    if (str != nullptr)
    {
        this->~MyString();
    }
    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    length = obj.length;

    return *this;
}

char MyString::operator[](int index)
{
    if (index >= 0 && index < strlen(str))
    {
        return str[index];
    }
    return '\0';
}

MyString::operator int()
{
    return length;
}
MyString::operator char* ()
{
    return str;
}

MyString::MyString()
{
    str = nullptr;
    length = 81;
    count++;
}

MyString::MyString(const MyString& obj)
{
    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    length = obj.length;
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

void MyString::PrintMyString()const 
{
    cout << str;
}

void MyString::MyStrCat(MyString& b)const 
{
    int buffsize = 81;
   strcat_s(str, buffsize , b.str);
}
void MyString::MyDelChr(char c)const 
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


int MyString::MyStrLen()const
{
    int counter = 0;
    for (int i = 0; i < length; i++) {
        counter++;
    }
    return counter;
}
int MyString::MyStrCmp(MyString& b)const
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
int MyString::MyChr(char c)const 
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
bool MyString::MyStrStr(const char* str)const
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
    MyString obj{ 'H','e','l','l','o','\0'};
    obj.PrintMyString();
    cout << endl << endl;
    MyString string1("Hello");
    MyString string2("World");
    char* str1 = string1;
    cout << str1 << endl;
    string1();
    cout << endl;
    cout<<string1[0];
    cout << endl;
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