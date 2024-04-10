const int M = 2e5 + 7;
int parent[M];
int size1[M];

void make_set(int v) {
    parent[v] = v;
    size1[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) {
        return false;
    }
    if (a != b) {
        if (size1[a] < size1[b])
            swap(a, b);
        parent[b] = a;
        size1[a] += size1[b];
    }
    return true;
}
