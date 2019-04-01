#include <iostream>
#include <queue>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int n, m;
char nFiled[101][101];
int nvisit[101][101];
int nRet;

int dirx[] = { 0, 0, 1, -1 };
int diry[] = { 1, -1, 0, 0 };

typedef struct inf{
	int x, y, ct;
};

void bfs()
{
	queue <inf> que;
	que.push({ 0, 0, 1 });

	nvisit[0][0] = 1;

	while (!que.empty()){
		inf crt = que.front();
		que.pop();

		if (crt.x == n - 1 && crt.y == m - 1){
			nRet = crt.ct;
			return;
		}
		
		for (int i = 0; i < 4; i++){
			inf next;
			next.x = crt.x + dirx[i];
			next.y = crt.y + diry[i];
			next.ct = crt.ct + 1;

			if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m
				&& !nvisit[next.y][next.x] && nFiled[next.y][next.x] == '1'){
				nvisit[next.y][next.x] = 1;
				que.push(next);
			}


		}





	}




}



void dfs(int crtx, int crty, int cnt)
{
	if (nRet <= cnt){
		return;
	}

	if (crtx == n - 1 && crty == m - 1){
		if (nRet > cnt)
			nRet = cnt;
		return;
	}

	for (int i = 0; i < 4; i++){
		int nextx = crtx + dirx[i];
		int nexty = crty + diry[i];

		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m
			&& !nvisit[nexty][nextx] && nFiled[nexty][nextx] == '1'){
			nvisit[nexty][nextx] = 1;
			dfs(nextx, nexty, cnt + 1);
			nvisit[nexty][nextx] = 0;
		}
	}
}


int main()
{
	freopen("sample_input.txt", "r", stdin);
	
	int t;
	int test_case;
	cin >> t;

	for (test_case = 1; test_case <= t; ++test_case)
	{
		cin >> m >> n;

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> nFiled[i][j];
				nvisit[i][j] = 0;
			}
		}

		//nRet = 987654321;
		//nvisit[0][0] = 1;
		//dfs(0, 0, 1);
		//nvisit[0][0] = 0;
		bfs();

		cout << nRet << endl;
	}

	return 0;
}