#pragma GCC optimisize(2)
#include<cstdio>
#include<algorithm>
#define maxn 500010
using namespace std;
int n,m,s,k,head[maxn],dep[maxn],fa[maxn][21];
bool vis[maxn];
struct node{
    int to,next;
}e[maxn*2];
inline int read(){
	int fl=1,sum=0;char w=getchar();
	while(w>'9'||w<'0'){if(w=='-')fl=-1;w=getchar();}
	while(w>='0'&&w<='9'){sum=(sum<<1)+(sum<<3)+w-'0';w=getchar();}
	return fl*sum;
}
inline void add(int u,int v){
	e[++k].next=head[u];e[k].to=v;head[u]=k;
}
inline void dfs(int u){
	vis[u]=true;
	for(int i=1;(1<<i)<=dep[u];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(!vis[v]){
			fa[v][0]=u;
            vis[v]=true;
			dep[v]=dep[u]+1;
            dfs(v);
		}
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y];
	for(int i=0;(1<<i)<=t;i++) if(t&(1<<i)) x=fa[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
    n=read(),m=read(),s=read();
    for(int i=1;i<n;i++){
    	int u=read(),v=read();add(u,v);add(v,u);
	}
	dfs(s);
	for(int i=1;i<=m;i++) printf("%d\n",lca(read(),read()));
    return 0;
}