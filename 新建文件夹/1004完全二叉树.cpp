#include <stdio.h>
inline int father(int n1, int n2) {
	if (n1 > n2) {
			int temp = n1 / n2;
			temp /= 2;
			n1 <<= temp;
		}
		while (1) {
			if (n1 > n2) {
				n1 >>= 1;
			} else if (n1 < n2) {
				n2 >>= 1;
			} else if ((n1^n2) == 0) {
				return n1;
			}
		}
}

int data[1001][1001];

void init() {
	for (int i = 0; i < 1001; ++i) {
		for (int j = i; j < 1001; ++j) {
			data[i][j] = father(i, j);
			data[j][i] = data[i][j]; 
		}
	}
}
int main() {
	init();
	int T;
	int n1, n2;
	scanf("%d", &T);
	while ((scanf("%d%d", &n1, &n2)) != EOF) {
		printf("%d\n", data[n1][n2]);
	}
}
