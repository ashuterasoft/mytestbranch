#include<iostream>
#include<unordered_map>

using namespace std;

struct key
{
  std::string first;
  std::string second;
  int  third;

  bool operator==(const key &other) const
  { return (first == other.first
            && second == other.second
            && third == other.third);
  }
};
struct keyhasher

{
	size_t operator()(const key &k) const
	{
		return ((hash<string>()(k.first)
  			^(hash<string>()(k.second) <<1)) >>1)
			^(hash<int>()(k.third)<<1);
	}
};
int main()
{
  std::unordered_map<key,std::string,keyhasher> m6 = {
    { {"John", "Doe", 12}, "example"},
    { {"Mary", "Sue", 21}, "another"}
  };
  for(auto & x:m6)
  cout<<x.first.first<<":"<<x.second<<endl;
}
