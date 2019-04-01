/* Author - Ajay Somani */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<iterator>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<cassert>
#include<deque>
#include<stack>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<string>
#include<cmath>
#include<ctime>
using namespace std;

#define Debug 0
#define LET(x,a) 	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define FOR(i,a,b)  	for(int i=(int)(a) ; i < (int)(b);++i)
#define	REP(i,n)    	FOR(i,0,n)
#define SZ		size()
#define PB		push_back
#define PF		push_front

#define V(x) vector< x >
typedef V(int)		VI;
typedef V(VI)		VII;
typedef V(string) 	VS;
typedef long long	LL;
typedef pair<int,int>	PI;

#define INF 100000000

#define BUFSIZE (10000)
char outputbuffer[BUFSIZE<<1],inputbuffer[BUFSIZE];
char *outptr=outputbuffer,*ioptr=inputbuffer+BUFSIZE,*ioend=inputbuffer+BUFSIZE;
int input_eof=0;

#define putchar(c) (*outptr++=(c))
#define getchar() ({if(ioptr>=ioend)init_input();*ioptr++;})
#define eof() (ioptr>=ioend&&input_eof)
#define eoln() ({if(ioptr>=ioend)init_input();*ioptr=='\n';})

void init_input(){
	if(input_eof)
		return;
	int existing=BUFSIZE-(ioend-inputbuffer);
	memcpy(inputbuffer,ioend,existing);
	int wanted=ioend-inputbuffer;
	int count=fread(inputbuffer+existing,1,wanted,stdin);
	if(count<wanted)
		input_eof=1;
	ioend=inputbuffer+BUFSIZE-(wanted-count);
	while(*--ioend>' ');
	ioend++;
	ioptr=inputbuffer;
}
inline void non_whitespace(){
	for(;;){
		if(ioptr>=ioend)
			init_input();
		if(*ioptr>' ')
			return;
		ioptr++;
	}
}
inline int getInt(){
	non_whitespace();
	int n=0;
	while(*ioptr>' ')
		n=(n<<3)+(n<<1)+*ioptr++-'0';
	ioptr++;
	return n;
}

int main() {
	int c = 0,N = getInt(),r;
	int k = getInt();
	while(N--){
		if(getInt()%k == 0){
			c++;
		}
	}
	printf("%d\n",c);
}

