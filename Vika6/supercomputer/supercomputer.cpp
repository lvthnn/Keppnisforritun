#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
  private:
    vector<int> st, A; // st is binary tree, A is original array
    int n;
    int left (int p)  { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    /**
     * Constructs the binary tree and calculates initial sums
     *
     * @param p initial element in st array
     * @param L left interval boundary
     * @param R right interval boundary
     */
    void build(int p, int L, int R) {
      if (L == R) 
        st[p] = A[L]; // leaf at bottom of binary tree, element in array
      else {  
        build( left(p),         L, (L+R)/2); // add left and right subinterval of p
        build(right(p), (L+R)/2+1, R      ); // recursively to populate segment tree

        int p1 = st[left(p)], p2 = st[right(p)]; // retrieve sums of L and R subintervals
        st[p] = p1 + p2;                         // assigns sum of inner node
    } } 

    /**
     * Range sum query, i.e. sums over elements of A with indices [i, j].
     * O(log n) implementation.
     *
     * @param p index of current node in st array
     * @param L left interval boundary
     * @param R right interval boundary
     * @param i left subinterval boundary
     * @param j right subinterval boundary
     */
    int rsq(int p, int L, int R, int i, int j) {
      if (i > R  ||  j < L) return -1;
      if (L >= i && R <= j) return st[p];

      int M = (L+R)/2; // middle of segment
      int sum_L  = rsq(left(p),  L,   M, i, j);
      int sum_R  = rsq(right(p), M+1, R, i, j);

      if (sum_L == -1) return sum_R;
      if (sum_R == -1) return sum_L;

      return sum_L + sum_R;
    }

    /**
     * Bit flip query, converts bit in memory from 0 to 1.
     *
     * @param p update target
     * @param u update value
     * @param i query start in st array
     * @param j query end in st array
     */
    void bfq(int p, int i, int j) {
      if (i == j)
        st[p] = st[p] ^ 1;
      else {
        int m = (i + j)/2;
        if (p <= m) bfq(left(p), i, m);
        else bfq(right(p), m+1, j);
        st[p] = st[left(p)] + st[right(p)];
    } }

  public:
    SegmentTree(const vector<int> &_A) {
      A = _A;
      n = (int) A.size();
      st.assign(4 * n, 0); // create roomy vector of zeroes
      build(1, 0, n - 1);  // recursively assemble binary tree
    }

    int rsq(int i, int j) { return rsq(1, 0, n - 1, i - 1, j - 1); } // overload for client use

    void bfq(int p) { return bfq(p, 0, n - 1); }

    void print() { for (int i = 0; i < st.size(); i++) cout << st[i] << endl; }

};

int main() {
  int n, k;
  cin >> n >> k;

  // initialize memory tree
  int arr[n] = {0}; 
  vector<int> A(arr, arr + 7);
  SegmentTree st(A);

  while(k-- > 0) {
    char t;
    cin >> t;

    int p1, p2;

    if (t == 'F') {
      cin >> p1;
      st.bfq(p1);
    }
    else if (t == 'C') {
      cin >> p1 >> p2;
      cout << st.rsq(p1, p2) << endl;
    }

  }

}
