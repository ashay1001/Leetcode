class Solution {
public:
    int minPartitions(string n) {
	int maxx = 0;
	for (int i=0; i<n.length(); i++) {
		if (n[i] - '0' == 9) return 9;
		maxx = max(maxx, (n[i] - '0'));
	}
	return maxx;
}
};