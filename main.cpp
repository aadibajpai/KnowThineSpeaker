#include<bits/stdc++.h>
#include "srtparser.h"
#include<windows.h>
using namespace std;


string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
int main(){
string subfile, speakername;
set<string> spnames;
set<string>fset;
int n=0;

cout<<"Enter path to subtitle file."<<endl;
cin>>subfile;
SubtitleParserFactory *subParserFactory = new SubtitleParserFactory(subfile);
SubtitleParser *parser = subParserFactory->getParser();

//to get subtitles

std::vector<SubtitleItem*> sub = parser->getSubtitles();

for(SubtitleItem * element : sub)
    { 
        if(element->getSpeakerCount())
        {
            //cout<<"speakers: ";
            std::vector<std::string> name = element->getSpeakerNames();
  
  			spnames.insert(name.begin(),name.end());
  			for(auto x:spnames) fset.insert(trim(x));
         } 
        }
cout<<"The speakers are--> ";        
cout << *fset.begin();
fset.erase(fset.begin());
for(auto x:fset) cout << ", "<< x;
cout<<endl<<"Which speaker do you want to know about? (Enter without spaces ;))"<<endl;
cin>>speakername;
speakername = "http://www.google.com/search?as_q="+speakername;
ShellExecute(NULL, "open", speakername.c_str(), NULL, NULL, SW_SHOWNORMAL);
return 0;
}