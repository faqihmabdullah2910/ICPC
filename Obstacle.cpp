#include <bits/stdc++.h>

int main() {
	int amount = 0, data[100005];
	scanf("%d", &amount);
	memset(data, 0, sizeof(data));
	for(int i = 0; i < amount; i++) {
		scanf(" %d", &data[i]);
	}
	int count = 2, tempcount = 1;
	for(int i = 1; i < amount; i += 2) {
		if(abs(data[i - 1] - data[i + 1]) == 0 || abs(data[i - 1] - data[i + 1]) == 2) {
			if(data[i - 1] > data[i + 1]) {
				data[i] = data[i - 1] - 1;
			}
			else {
				data[i] = data[i + 1] - 1;
			}
			tempcount += 2;
		}
		else {
			if(data[i - 1] > data[i + 1]) {
				data[i] = data[i - 1] - 1;
			}
			else {
				data[i] = data[i + 1] - 1;
			}
			tempcount++;
			if(count < tempcount) {
				count = tempcount;
			}
			tempcount = 2;
		}
	}
	if(count < tempcount) {
		count = tempcount;
	}
	printf("%d\n", count);
	return 0;
}
