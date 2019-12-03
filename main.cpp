#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[301][301];
bool check[301][301]; 
int dist[301][301];
int dirx[] = {-1,-2,-2,-1,1,2,2,1};
int diry[] = {-2,-1,1,2,-2,-1,1,2};
queue<pair<int,int>> q;
		int l;

void bfs()
{
	//q.push(make_pair(i,j));
	while(!q.empty()){
		pair<int,int> current = q.front();
		int x = current.first;
		int y = current.second;
		q.pop();
		for(int i=0;i<8;i++){
			int nx = x+dirx[i];
			int ny = y+diry[i];
			if(0<= nx && nx<l && 0<= ny && ny<l){
				if(dist[nx][ny]==-1) { 	// 모든 칸 방문 가능
 					dist[nx][ny] = dist[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin>> test;
	while(test--) {

		cin >> l;
		int start_x,start_y;
		cin>> start_x>> start_y;
		int target_x,target_y;
		cin>>target_x>>target_y;
		memset(dist,-1,sizeof(dist));
		q.push(make_pair(start_x,start_y));
		dist[start_x][start_y]= 0;
		bfs();
		
		int ans = dist[target_x][target_y];
		
		cout << ans<< '\n';
		
	}
	return 0;
}