#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <iterator>

using namespace std;
class history
        {
            using Pages = list<string>;
            using Location = unordered_map<string,Pages::iterator>;
            Pages m_pages;
            Location m_location;

        public:
            void visit(const std::string & url)
            {
                auto res = m_location.find(url);
                if(res != m_location.end())
                {
                    cout<<"url:"<<url<<" found\n";
                    m_pages.erase(res->second);
                }
                cout<<"visited:"<<url<<"\n";
                m_pages.push_front(url);
                m_location.insert({url,m_pages.begin()});
            }
            vector<string> getRecentlyVisited()
            {
                vector<string> vr;
                auto itr = m_pages.begin();
                for(int i =0 ; itr!= m_pages.end() && i < 5; ++i)
                {
                    cout<<"Recent:"<<*itr<<"\n";
                    vr.push_back(*itr);
                    ++itr;

                }
                return vr;
            }


        };
int main() {
    std::cout << "Hello, World!" << std::endl;
    history browser;
    browser.visit("google.com");
    browser.visit("amazon.com");
    browser.visit("msn.com");
    browser.visit("flipkart.com");
    browser.visit("argos.com");
    browser.visit("apple.com");
    browser.visit("google.com");


    cout<<"\n";
    //browser.visit("argos.com");
    browser.getRecentlyVisited();

    

    return 0;
}
