// pf[i] = longest proper prefix of s[0..i] which is also a suffix of it
vi  prefix_function(string &s) {
    int n = s.size();
    vi pf(n);
    pf[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) j = pf[j-1];
        if (s[i] == s[j]) j++;
        pf[i] = j;
    }
    return pf;
}

// numero de ocurrencias de p en s
int kmp(string &s, string &p) {
    int n = s.size(), m = p.size(), cnt = 0;
    vector<int> pf = prefix_function(p);
    for(int i = 0, j = 0; i < n; i++) {
        while(j && s[i] != p[j]) j = pf[j-1];
        if(s[i] == p[j]) j++;
        if(j == m) {
            cnt++;
            j = pf[j-1];
        }
    }
    return cnt;
}

// nodo 0 es el nodo inicial, significa que no matcheo nada
// nodo s.size() es el nodo final, significa que matcheo todo
const int MAXN = 1e5 + 5, alpha = 26;
const char L = 'A'; // ojo aqui es el elementos más bajo del alfabeto
int go[MAXN][alpha]; // go[i][j] = a donde vuelvo si estoy en i y pongo una j
void build(string &s) {
    int lps = 0;
    go[0][s[0]-L] = 1;
    int n = s.size();
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < alpha; j++) go[i][j] = go[lps][j];
        if (i < n) {
            go[i][s[i]-L] = i + 1;
            lps = go[lps][s[i]-L];
        }
    }
}
