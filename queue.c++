#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	queue <int> q;
	for(int i =0;i<10;i++)
		q.push(i*i);

	while(!q.empty())
	{
		cout<<q.front()<<endl;
		q.pop();
	}


}