const int tam=200005;
vi G[tam];
int del[tam],sz[tam];
int n;

void init(int nodo, int ant){
    sz[nodo]=1;
    for(auto it:G[nodo]){
        if(it==ant || del[it]) continue;
        init(it,nodo);
        sz[nodo]+=sz[it];
    }
}

int centroid(int nodo, int ant, int desired){
    for(auto it : G[nodo]){
        if(it==ant || del[it]) continue;
        if(sz[it]*2>=desired) return centroid(it,nodo,desired);
    }
    return nodo;
}

int get_centroid(int nodo){
    init(nodo,-1);
    int desired=sz[nodo];
    return centroid(nodo,-1,desired);
}

void DC(int nodo){
    int c=get_centroid(nodo);
    del[c]=1;
    // aqui haces pre/calculo ?
    // update dfs(nodo)
    for(auto it : G[c]){
        if(del[it])continue;
        // sigues con calculo, a veces si tienes que contar para cada nodo caminos que pasan sobre él
        // y no solamente cantidad de caminos puedes hacer
        // delete dfs(it)
        // contar (it)
        // update dfs(it)
    }
    // * reinicias tus arreglos *
    for(auto it : G[c]){
        if(del[it])continue;
        DC(it,c);
    }
}
