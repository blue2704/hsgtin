#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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
    for (int i = 0; i < input.length() - text.length() - 1; i++)
    {
        if (input.substr(i, text.length()))
        {
            appearTime++;
        }
    }
    answer = 'a. so lan co cum "ChuyenTran Phu" la : ' + appearTime +" lan.";
    LogToFile(answer, ios_base::out);
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

    return 0;
}