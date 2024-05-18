bitset<100001> posi;
posi[0] = 1;
for (int t : comps) posi |= posi << t;
for (int i = 1; i <= n; ++i) cout << posi[i];
