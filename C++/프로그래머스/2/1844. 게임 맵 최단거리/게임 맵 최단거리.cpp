#include <vector>
#include <queue>
using namespace std;

// BFS -> 큐 이용
// 자료구조 큐: 선입선출, rear에 값을 넣고 front의 값을 꺼냄

int maps[100][100];
bool visited[100][100];

// 상하좌우 이동용
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int n, int m, vector<vector<int>> maps){ // 시작 좌표가 0행 0열로 고정, n과 m은 도착 위치
    queue<pair<int, int>> q;
    q.push({0, 0});     // 1. 큐에 시작점 넣기
    visited[0][0] = true;   // 시작 위치를 방문으로 설정
    
    while(!q.empty()){ // 큐가 비어있지 않은 동안 반복
        int x = q.front().first;
        int y = q.front().second;
        
        if(x==n && y==m) return maps[x][y];
            
        // 2. 현재 위치 꺼내기
        q.pop();
        
        // 3. 상하좌우 확인
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 지도 범위 안이고, 벽이 아니고, 방문한 적 없다면
            if(nx >= 0 && ny >= 0 && nx<maps.size() && ny<maps[0].size() && !visited[nx][ny] && maps[nx][ny]!=0) {
                visited[nx][ny] = true;
                maps[nx][ny] = maps[x][y]+1;
                q.push({nx, ny}); // 4. 다음 갈 곳을 큐에 추가(한 칸 전진)
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    
    return bfs(n, m, maps);
}