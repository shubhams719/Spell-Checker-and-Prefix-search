#include <iostream>
#include <unordered_map>
#include<string.h>
using namespace std;
 
struct Trie {
    bool isEndOfWord;
    unordered_map<char, Trie*> map;
};
Trie* my_temp;
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isEndOfWord = false;
    return node;
}
void insert(Trie*& root, const string& str)
{
    if (root == nullptr)
        root = getNewTrieNode();
 
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
 
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();
 
        temp = temp->map[x];
    }
 
    temp->isEndOfWord = true;
}
bool search(Trie* root, const string& str)
{
    if (root == nullptr)
        return false;
 
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
 
        temp = temp->map[str[i]];
 
        if (temp == nullptr)
            return false;
    }
 
    return temp->isEndOfWord;
}

bool search1(Trie* root, const string& str)
{
    if (root == nullptr)
        return NULL;
 
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
 
        temp = temp->map[str[i]];
 
        if (temp == nullptr)
            return NULL;
	my_temp = temp;
    }
    return true; 
 
}
void traverse(Trie* root,const string& str)
{
	Trie* temp = root;
	Trie* temp1 = NULL;
	string str2;
	string str1;
	int i;
	unordered_map<char,Trie*>::iterator it;
	for(i=1;i<=str.length();i++)
	{
		if(!search1(temp,str.substr(0,i)));
		{
			it = my_temp->map.begin();
			while(it != my_temp->map.end())
			{
				str1 = it->first;
				str2  = str.substr(0,i)+str1;
				if(search(root,str2))
				{		
					cout <<str.substr(0,i);
					cout << it->first;
					cout <<'\n';
					my_temp=NULL;
				}
				++it;
			}

		}
	}
	return;
}
void my_spellchecker(Trie* root,const string& str)
{
	int n = str.length();
	char s[n+1];
	strcpy(s,str.c_str());
	char* s1 = strtok(s," ");
	string s2;
	while(s1 != NULL)
	{
		s2 = s1;
		if(!search(root,s2))
		{
			cout << "wrong word is " << s2;
			cout << "following words may exist" << '\n';
			traverse(root,s2);
		}
		s1 = strtok(NULL," ");
	}
	return ;
}
int main()
{
    Trie* root = nullptr;
 
    insert(root, "geeks");
    cout << search(root, "geeks") << " ";
 
    insert(root, "for");
    cout << search(root, "for") << " ";
 
    cout << search(root, "geekk") << " ";
 
    insert(root, "gel");
    insert(root, "gem");
    cout << search(root, "gee") << " ";
 
    insert(root, "science");
    cout << search(root, "science") << endl;
    my_spellchecker(root,"gek geek");
    return 0;
}
