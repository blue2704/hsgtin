#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

//log to file
void LogToFile(string answer, ios_base::openmode mode)
{
    ofstream output;
    output.open("dapan.txt", mode);
    output << answer << endl;
    output.close();
}

//cau a
void FindText(string text, string input)
{
    string answer;
    int appearTime = 0;
    for (int i = 0; i < input.length() - text.length() + 1; i++)
    {
        if (input.substr(i, text.length()) == text)
        {
            appearTime++;
            cout << text.length();
        }
    }
    answer = "a. so lan co cum \"Chuyen Tran Phu\" la : " + to_string(appearTime) + " lan.";
    LogToFile(answer, ios_base::out);
}

//cau b
void replaceAll(string &str, const string &from, const string &to)
{
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) < str.length())
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

void ReplaceText(string input, string word_to_be_replaced, string word_to_replace)
{
    string changed = input;
    replaceAll(changed, word_to_be_replaced, word_to_replace);
    string answer = "b. " + changed;
    LogToFile(answer, ios_base::app);
}

//cau c
void check_if_mirror(string input)
{
    string answer = "c. chuoi doi xung.";
    for (int i = 0; i < input.length() / 2; i++)
    {
        if (!(input[i] == input[input.length() - i - 1]))
        {

            answer = "c. chuoi khong doi xung.";
            LogToFile(answer, ios_base::app);
            return;
        }
    }
    LogToFile(answer, ios_base::app);
}

//cau d 
void Palindromic_sub(string input)
{
    string answer ;
    int maxLength = 1;
    int start = 0;
    int n = input.length();
 
    int low, high;

    for (int i = 1; i < n; ++i)
    {
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < n && input[low] == input[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        //even
        low = i - 1;
        high = i;
        while (low >= 0 && high < n && input[low] == input[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    //ket qua 
    int end = start + maxLength - 1; 
    answer = "d. chuoi doi xung dai nhat la : " ;
    for( int i = start; i <= end; ++i )
    {
        answer += input[i] ;
    }
    answer += (" xuat hien tu vi tri thu " + to_string(start+1)) ;
    LogToFile(answer, ios_base::app);
}

int main()
{
    string tenfile;
    cout << "ten file : ";
    cin >> tenfile;
    ifstream file;
    file.open(tenfile);
    string du_lieu((istreambuf_iterator<char>(file)),
                   (istreambuf_iterator<char>()));

    //cau a
    FindText("Chuyen Tran Phu", du_lieu);
    //cau b
    ReplaceText(du_lieu, "Chuyen Tran Phu", "TPC");
    //cau c
    check_if_mirror(du_lieu);
    //cau d 
    Palindromic_sub(du_lieu);

    return 0;
}