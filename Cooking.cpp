#include <bits/stdc++.h>

int main() {
	long long int amount = 0, time[100005] = {}, currsteak[100005] = {}, order[100005] = {};
	scanf("%lld", &amount);
	for(int i = 0; i < amount - 1; i++) {
		scanf(" %lld", &time[i]);
	}
	for(int i = 0; i < amount; i++) {
		scanf(" %lld", &currsteak[i]);
	}
	for(int i = 0; i < amount; i++) {
		scanf(" %lld", &order[i]);
	}
	long long int totaltime = 0;
	for(int i = amount - 1; i > 0; i--) {
		if(order[i] > currsteak[i]) {
			long long int diff = order[i] - currsteak[i];
			currsteak[i - 1] -= diff;
			currsteak[i] += diff;
			totaltime += time[i - 1] * diff;
		}
	}
	if(order[0] > currsteak[0]) {
		printf("-1\n");
	}
	else {
		printf("%lld\n", totaltime);
	}
	return 0;
}
