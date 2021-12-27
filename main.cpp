#include <iostream>
#include <sstream>
#include <cctype>
#include <deque>
#include <queue>
#include <list>
#include <iterator>
#include <stack>
#include <cstring>

using namespace std;
void split(deque<string> &tokens,const string& s)
{
    std::stringstream ss(s);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
}
void split(priority_queue<string> &tokens,const string& s)
{
    std::stringstream ss(s);
    string word;
    while (ss >> word) {
        tokens.push(word);
    }
}


void exercise_1_deque_list(){
    string a;
    deque<string> dq;
    list<string> liste;

    getline(std::cin, a);
    // Takes only space separated C++ strings.
    split(dq,a);
    std::copy(dq.begin(), dq.end(), std::back_inserter(liste));
    for(auto & it : liste)
    {
        cout << it << endl;
    }
    cout << endl;
}
void exercise_1_priority_list(){
    priority_queue<string> mots;
    string a;
    getline(std::cin, a);
    split(mots, a);
    while (! mots.empty() ) {
        cout << mots.top() << "\n";
        mots.pop();
    }
}

void exercise_1_palindrome(){
    string a;
    cin.clear();

    int compteur;
    getline(std::cin, a);
    cout << a.length() <<endl;
    compteur=std::count_if(a.begin(), a.end(),
                           [](unsigned char c){ return (!std::isspace(c)); } // correct
    );
    auto atab = new char[compteur];
    cout << compteur<<endl;
    stack<char> pile;
    int i=0,j=0;
    while( i<a.length()){
        if(isspace(a[i])){
            cout << a[i] <<endl;
            cout <<i<<endl;
            i++;
            continue;
        }else{
            atab[j] = a[i];
            pile.push(atab[j]);
            j++;
            i++;
        }
    }

    auto btab = new char[compteur];
    for (int y=0; y<compteur; y++){
        btab[y] =pile.top();
        cout << pile.top() << endl;
        pile.pop();
    }


    cout << atab<<endl;
    cout << btab<< endl;
    if(strcmp(btab,atab)==0){
        cout << "Il s'agit d'un palindrome" << endl;
    }else{
        cout << "Il s'agit pas d'un palindrome"<<endl;
    }
    delete[] atab;
    delete[] btab;
}
int main(int argc, char const* argv[])
{

    return 0;
}