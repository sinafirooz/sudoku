#include <iostream>
using namespace std;

#define N 10

const int n = 3;
const int n2 = n * n; // number of numbers

int sdk[N * N + 1] [N * N + 1];
int ans[N * N + 1] [N * N + 1];
bool finish = false;

void printans() {
	for (int i = 1; i <= n2; i++, printf("\n"))
		for (int j = 1; j <= n2; j++)
			printf("%d ",ans[i] [j]);
	printf("\n");
}
bool isanswer() {
	bool check[N * N + 1];
	for (int i = 1; i <= n2; i++) {
		memset(check, false, n2 + 1);
		check[0] = true;
		for (int j = 1; j <= n2; j++)
			if (check[ans[i] [j]])
				return false;
			else
				check[ans[i] [j]] = true;
	}
	for (int j = 1; j <= n2; j++) {
		memset(check, false, n2 + 1);
		check[0] = true;
		for (int i = 1; i <= n2; i++)
			if (check[ans[i] [j]])
				return false;
			else
				check[ans[i] [j]] = true;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0;j < n; j++) {
			memset(check, false, n2 + 1);
			check[0] = true;
			for (int k = 0; k < n; k++)
				for (int l = 0; l < n; l++) {
					int x = n * i + 1 + k;
					int y= n * j + 1 + l;
					if (check[ans[x] [y]])
						return false;
					else
						check[ans[x] [y]] = true;
				}
	}
	return true;
}
bool promissing(int x, int y) {
	bool check[n2 + 1];
	memset(check,false, n2 + 1);
	for (int i = 1; i <= n2; i++)
		if (check[ans[x] [i]])
			return false;
		else if (ans[x] [i] != 0)
			check[ans[x] [i]] = true;
	memset(check, false, n2 + 1);
	for (int i = 1; i <= n2; i++)
		if (check[ans[i] [y]])
			return false;
		else if (ans[i] [y] != 0)
			check[ans[i] [y]] = true;
	memset(check, false, n2 + 1);
	int xt = ((x - 1) / n) * n + 1;
	int yt = ((y - 1) / n) * n + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (check[ans[xt + i] [yt + j]])
				return false;
			else if (ans[xt + i] [yt + j] != 0)
				check[ans[xt + i] [yt + j]] = true;
		}
	return true;
}
int solve(int x, int y) {
	static int solutions = 0;
	int x2 = (y < n2) ? x : x + 1;
	int y2 = (y < n2) ? y + 1 : 1;
	if (isanswer()) {
		solutions++;
		if( !finish)
			printans();
		finish = true;
		return solutions;
	}
	if( sdk[x] [y])
		solve(x2, y2);
	else {
		for (int i = 1; i <= n2; i++) {
			ans[x] [y] = i;
			if( promissing(x, y))
				solve(x2, y2);
		}
		ans[x] [y] = 0;
	}
	return solutions;
}

int main() {
	for (int i = 1; i <= n2; i++)
		for (int j = 1; j <= n2; j++) {
			scanf("%d", &sdk[i] [j]);
			ans[i] [j] = sdk[i] [j];
		}
	printf("%d\n", solve(1, 1));
	return 0;
}
