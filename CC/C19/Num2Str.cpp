#include <iostream>
#include <string>

using namespace std;

const unsigned N = 11;

string numName1[N] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};  //0 is a special case
string numName11[N] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string numName10s[N] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string processLessThousand(int num)
{
    string result = "";
    if(num / 100 >= 1)
    {
        result += numName1[num/100];
        result += " Hundred and ";
    }
    num = num % 100;
    if(num >= 11 && num <=19)
    {
        result += numName11[num];
    }
    else
    {
        result += numName10s[num/10];
        result += " ";
        result += numName1[num%10];
    }

    return result;
}

string num2Str(int num)
{
    string result = "";
    if(num > 999999)
    {
        return result;
    }

    if(num == 0)
    {
        result.append("Zero");
        return result;
    }

    if(num/1000 >= 1)
    {
        result += processLessThousand(num/1000);
        result += " Thousand, ";
    }
    num = num % 1000;
    result += processLessThousand(num);

    return result;
}

int main()
{
    int num = 999823;
    cout<<num<<" is "<<num2Str(num)<<endl;
}

