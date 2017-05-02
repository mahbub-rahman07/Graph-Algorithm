#include <iostream>
#include <vector>
#include <list>

using namespace std;
const int N=4;

int main() {

	std::vector <std::list<int> > adjList(N);
	adjList[0].push_back(1);
	adjList[0].push_back(2);

	adjList[1].push_back(2);
	adjList[1].push_back(0);

	adjList[2].push_back(0);
	adjList[2].push_back(1);
	adjList[2].push_back(3);

	adjList[3].push_back(2);

	std::vector<std::list<int> >::iterator i;
	 int c=0;
	for (std::vector<std::list<int> >::iterator i=adjList.begin(); i !=adjList.end(); ++i){


		cout<<"vertices connected to node "<<c <<" are ";
		//cout<<*i;

		std::list<int> li = *i;
		for(std::list<int>::iterator iter = li.begin(); iter!= li.end(); ++iter){

			cout<<*iter<<" ";
		}
		cout<<endl;
		c++;
	}
}