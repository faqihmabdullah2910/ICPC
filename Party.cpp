#include <bits/stdc++.h>

int main() {
	int amount = 0, maxdiff = 0, data[205] = {};
	scanf("%d %d", &amount, &maxdiff);
	for(int i = 0; i < amount; i++) {
		scanf(" %d", &data[i]);
	}
	for(int i = 0; i < amount - 1; i++) {
		for(int j = 0; j < amount - i - 1; j++) {
			if(data[j] > data[j + 1]) {
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	int count = 0, maxrating = 0;
	for(int i = 0; i < amount - 2; i++) {
		for(int j = i + 1; j < amount - 1; j++) {
			for(int k = j + 1; k < amount; k++) {
				int temp = data[k] - data[i];
				if(temp <= maxdiff) {
					count++;
					int temprating = data[i] + data[j] + data[k];
					if(temprating > maxrating) {
						maxrating = temprating;
					}
				}
			}
		}
	}
	if(count == 0) {
		printf("-1\n");
	}
	else {
		printf("%d %d\n", count, maxrating);
	}
	return 0;
}
