#include <iostream>

using namespace std;
#define M 100000

typedef struct {
    int l,r;
    long long int num;
}Element;


class segmentTree {
    public:
    	Element tree[4*M+10];
        void build(int size);
        void Xor(int l, int r, int i, int from, int to, long long int x);
        int find(int num, int i, int from, int to);
};

void segmentTree::build(int size)
{
	for (int i = 0; i < size; ++i)
		tree[i].num = 0;
}
void segmentTree::Xor(int l, int r, int i, int from, int to, long long int x)
{
	if (from >= l && to <= r)
	{
		tree[i].l = from;
		tree[i].r = to;
		tree[i].num ^= x;
		return;
	}
	if (from > r || to < l)
		return;

	int mid = (from + to) / 2;
	Xor(l, r, i * 2 + 1, from, mid, x);
	Xor(l, r, i * 2 + 2, mid + 1, to, x);
}

int segmentTree::find(int num, int i, int from, int to)
{
	if (from > num || to < num)
		return 0;
	if (from == to)
		return tree[i].num;
	int mid = (from + to) / 2;
	return find(num, i * 2 + 1,from, mid) ^ find(num, i * 2 + 2, mid + 1, to) ^ tree[i].num;
}

int main()
{
	segmentTree seg;
    int n;
    cin >> n;

    seg.build(n);

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r;
            long long int x;
            cin >> l >> r >> x;
            r-=1;
            l-=1;
            seg.Xor(l,r,0,0,n - 1,x);
        }
        else
        {
        	int num;
            cin >> num;
            num -= 1;
            long long ans = (long long)seg.find(num,0,0,n-1);
            cout << ans << endl;
        }
    }
return 0;
}