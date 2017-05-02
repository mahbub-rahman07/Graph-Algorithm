#include <iostream>
#include <vector>
#include <list>

using namespace std;
const int N=4;

class edge{
	private:
		double wt;
		int vertex_id;

public:
	edge(double w, int id){
		wt= w;
		vertex_id = id;
	}

	double getWeight() const {
		return wt;
	}
	int getVertexId() const {
		return vertex_id;
	}

};

int main() {

	std::vector <std::list<edge> > adjList(N);
	adjList[0].push_back(edge(4,1));
	adjList[0].push_back(edge(2,2));

	adjList[1].push_back(edge(4,0));
	adjList[1].push_back(edge(5,2));

	adjList[2].push_back(edge(2,0));
	adjList[2].push_back(edge(5,1));
	adjList[2].push_back(edge(1,3));

	adjList[3].push_back(edge(1,2));

	std::vector<std::list<edge> >::iterator i;
	 int c=0;
	for (std::vector<std::list<edge> >::iterator i=adjList.begin(); i !=adjList.end(); ++i){


		cout<<"vertices connected to node "<<c <<" are ";
		//cout<<*i;

		std::list<edge> li = *i;
		for(std::list<edge>::iterator iter = li.begin(); iter!= li.end(); ++iter){

			cout<<"(V= "<<(*iter).getVertexId()<<" wt= "<<(*iter).getWeight()<<") ";
		}
		cout<<endl;
		c++;
	}

}
