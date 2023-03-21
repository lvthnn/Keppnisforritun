#include <iostream>
#include <algorithm>

using namespace std;
typedef struct{ int u, v, w; } ii;       // fjöldi hnúta og leggja

int cmp(const void* p1, const void* p2)  // bera saman leggi eftir
{ return ((ii*)p1)->w - ((ii*)p2)->w; }  //           þyngd þeirra

bool cmp_lg(ii x, ii y) {
  return (x.u == y.u) ?
    x.v < y.v :
    x.u < y.u ;
}

/**
 * Finnur samhengisþáttinn sem stak tilheyrir.
 *
 * @param p fylki sammengisleitarinnar
 * @param x stakið sem á að finna
 * @return samhengisþátturinn sem x tilheyrir
 */
int uf_find(int *p, int x) 
{
  return p[x] < 0 ? x : (p[x] = uf_find(p, p[x]));
}

/**
 * Sameinar tvo samhengisþætti í sammengisleit
 *
 * @param p fylki sammengisleitarinnar
 * @param x fyrri samhengisþáttur
 * @param y seinni samhengisþáttur
 */
void uf_join(int *p, int x, int y)
{
  int rx = uf_find(p, x), ry = uf_find(p, y);
  if (rx == ry) return;
  if (p[rx] > p[ry]) {
    p[ry] += p[rx]; p[rx] = ry;
  }
  else {
    p[rx] += p[ry]; p[ry] = rx; 
  } 
}

/**
 * Upphafsstillir sammengisleit.
 *
 * @param p fylkið sem á að nota
 * @param n fjöldi samhengisþátta í upphafi
 */
void uf_init(int *p, int n)
{
  for (int i = 0; i < n; i++) p[i] = -1;
}

/**
 * Reiknirit Kruskals. (1956)
 * Finnur minnsta spantré út frá sammengisleit
 *
 * @param e upprunalega tréð
 * @param t minnsta spantréð
 * @param n fjöldi hnúta
 * @param m fjöldi leggja
 * @return minnsta spantré e
 */
int kruskal(ii* e, ii* t, int n, int m)
{
	int i, j = 0, r = 0, p[n];
	uf_init(p, n);
	qsort(e, m, sizeof(e[0]), cmp);
	for (i = 0; i < m; i++)
	{
		if (uf_find(p, e[i].u) == uf_find(p, e[i].v)) continue;
		r += e[i].w;
		uf_join(p, e[i].u, e[i].v);
		t[j++] = e[i];
	}
  if (j != n - 1) return -1;
	return r;
}

int main() 
{
  int n, m, u, v, w, i;

  while(true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    ii  a[n], t[n - 1];
    for (i = 0; i < m; i++)
      cin >> a[i].u >> a[i].v >> a[i].w;

    int res = kruskal(a, t, n, m);
    sort(t, t + n - 1, cmp_lg);
    if (res == -1) cout << "Impossible" << endl;
    else {
      cout << res << endl;
      for (i = 0; i < n - 1; i++) 
        cout << t[i].u << " " << t[i].v << endl;
    }
  }
}
