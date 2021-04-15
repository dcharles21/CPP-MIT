#include <iostream>
#include <string>
using namespace std;

char* v = "aeiou";
string VOWELS = v;

string Pig_Latin_Translator(string s)
{
    // string starts with a vowel
    if(VOWELS.find(s[0]) < VOWELS.length())
    {
        s.append("-way"); 
    }
    
    // string starts with a consonant
    // Assuming all english words that begin with 'q' contain a following 'u'   
    else
    {
        string syl;
        syl = "-ay";     

        if (s[0] == 'q') 
        {
            syl.insert(1, "qu", 2);
            s.erase(0,2);       
        } 

        else 
        {
            syl.insert(1, 1, s[0]);
            s.erase(0,1);
        }
        
        s.append(syl); 
    }
    
    return s;    
}

int main()
{   
    // Vowel Example 
    string s0 = "aim";
    string p0 = Pig_Latin_Translator(s0);
    cout << p0 << endl;

    // Consanant Example 
    string s1 = "banana";
    string p1 = Pig_Latin_Translator(s1);
    cout << p1 << endl;

    // Consanant Example 2     
    string s2 = "queen";
    string p2 = Pig_Latin_Translator(s2);
    cout << p2 << endl;
}