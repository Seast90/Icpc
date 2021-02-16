vector<int>Pos;
void deal(char *x, int n) {
    int i = 0;

    while (i < n) {
        int j = i, k = i + 1;

        while (k < n && x[j] <= x[k]) {
            if (x[j] == x[k])
                j++;
            else
                j = i;

            k++;
        }

        while (i <= j) {
            i += k - j;
            Pos.push_back(i);
        }
    }
}
