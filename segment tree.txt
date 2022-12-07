#include <bits/stdc++.h>

using namespace std;
// suma en rango
int arr[]={1,2,3,4,5,6,7,8};
int ST[20];

void build(int nodo, int p, int q){
	if(p==q){
		ST[nodo]=arr[p];
	}
	else{
		build(2*nodo+1, p, (p+q)/2);
		build(2*nodo+2, (p+q)/2+1, q);
		ST[nodo]=ST[2*nodo+1]+ST[2*nodo+2];

	}
}

void update(int nodo, int p, int q, int act){
	if(p==q){
		ST[nodo]=arr[act];
	}
	else{
		if(act>=p && act<=(p+q)/2){
			update(2*nodo+1, p, (p+q)/2, act);
		}
		if(act>=(p+q)/2+1 && act<=q){
			update(2*nodo+2, (p+q)/2+1, q, act);
		}
		ST[nodo]=ST[2*nodo+1]+ST[2*nodo+2];
	}
}

int query(int nodo, int p, int q, int buscadop, int buscadoq){
	if(p>=buscadop && q<=buscadoq){
		return ST[nodo];
	}
	if(p>buscadoq || q<buscadop)return 0;
	return query(2*nodo+1, p, (p+q)/2, buscadop, buscadoq)+query(2*nodo+2, (p+q)/2+1, q, buscadop, buscadoq);
}

int main(){
	build(0, 0, 7);
	cout<<query(0,0,7,3,4)<<endl;
	return 0;
}
