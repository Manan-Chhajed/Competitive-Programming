  /* 
    - Insert
    - Seach
    - Delete

    - Count of string s --> then maintain a cnt variable with the Node structure
    - Count words whose prefix is s --> maintain another variable scnt.a

    - Trie on numbers
      - Convert to binary string
      - Now same as before
  */
struct Node
{
    Node* arr[26]; // gets auto initialized by null
    bool flag = false;
};

class Trie
{
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string &s)
    {
        int n = s.size();
        Node* node = root; // root needs to be stored, ofcourse
        for (int i = 0; i < n; i++)
        {
            if (node->arr[s[i] - 'a'] == NULL)
                node->arr[s[i] - 'a'] = new Node();
            node = node->arr[s[i] - 'a'];
        }
        node->flag = true; // a string ended here
    }
    bool search(string &s)
    {
        int n = s.size();
        Node* node = root;
        for (int i = 0; i < n; i++)
        {
            if (node->arr[s[i] - 'a'] == NULL)
                return false;
            node = node->arr[s[i] - 'a'];
        }
        return node->flag; // true if string ends here
    }
    bool startswith(string &s)
    {
        int n = s.size();
        Node* node = root;
        for (int i = 0; i < n; i++)
        {
            if (node->arr[s[i] - 'a'] == NULL)
                return false;
            node = node->arr[s[i] - 'a'];
        }
        return true; // prefix found
    }
};

void solve()
{
    int q;
    cin >> q;
    Trie t;
    while (q--)
    {
        int type;
        cin >> type;
        string s;
        cin >> s;
        if (type == 1)
        {
            t.insert(s);
        }
        else if (type == 2)
        {
            if (t.search(s)) cout << "Yes\n";
            else cout << "No\n";
        }
        else
        {
            if (t.startswith(s)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
/* 
  - Given arr[] and x, find the max value of x ^ arr[i]
*/
struct Node
{
    Node* arr[2];
};

class Trie
{
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(int x)
    {
        Node* node = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = ((x >> i) & 1);
            if (node->arr[bit] == NULL)
                node->arr[bit] = new Node();
            node = node->arr[bit];
        }
    }
    int getMaxXor(int x)
    {
        Node* node = root;
        int max_xor = 0;
        for (int i = 30; i >= 0; i--)
        {
            int bit = ((x >> i) & 1);
            int required_bit = 1 - bit;
            if (node->arr[required_bit] == NULL)
            {
                node = node->arr[bit];
            }
            else
            {
                node = node->arr[required_bit];
                max_xor += (1 << i);
            }
        }
        return max_xor;
    }
};

void solve()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    Trie t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        t.insert(arr[i]);
    }
    cout << t.getMaxXor(x) << "\n";
}
