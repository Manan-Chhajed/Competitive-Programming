void solve()
{
    int i, n, m;
    cin >> n >> m;
    multiset<int> price_of_ticket;
    fo(i, n)
    {
        int price;
        cin >> price;
        price_of_ticket.insert(price);
    }
    fo(i, m)
    {
        int price_paid_by_customer;
        cin >> price_paid_by_customer;

        auto it = price_of_ticket.upper_bound(price_paid_by_customer);
        if (it == price_of_ticket.begin())
        {
            cout << -1 << nl;
            continue;
        }
        else
        {
            cout << *(--it) << nl;
            price_of_ticket.erase(it);
        }
    }
}
