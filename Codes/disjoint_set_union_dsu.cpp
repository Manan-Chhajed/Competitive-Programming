class DisjointSet {
private:
    vector<int> parent;
    vector<int> size1;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size1.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            make_set(i);
    }

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
                std::swap(a, b);
            parent[b] = a;
            size1[a] += size1[b];
        }
        return true;
    }

    bool union_sets_rank(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) {
            return false;
        }
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    DisjointSet ds(n);

    ds.union_sets(1, 2);
    ds.union_sets(3, 4);
    ds.union_sets(1, 4);

    return 0;
}
