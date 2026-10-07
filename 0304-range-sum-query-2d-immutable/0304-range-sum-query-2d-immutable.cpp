class Segment {
public:
	int n,m;
	vector<vector<int>>tree;
	Segment(int n,int m,vector<vector<int>>&grid) {
		this -> n = n;
        this -> m = m;
		tree.resize(4 * n, vector<int>(4 * m));
		buildRows(0,0,n-1,grid);
	}
	void buildCol(int xInd,int x, int y,int yInd,int l,int r, vector<vector<int>>& grid) {
		if(l == r) {
			if(x == y) {
				tree[xInd][yInd] = grid[x][l];
			}
			else {
				tree[xInd][yInd] = tree[xInd * 2 + 1][yInd] + tree[xInd * 2 + 2][yInd];
			}
			return;
		}
		int mid = l + ( r - l) / 2;
		buildCol(xInd, x, y,yInd * 2 + 1, l, mid, grid);
		buildCol(xInd, x, y,yInd * 2 + 2, mid + 1, r, grid);
		tree[xInd][yInd] = tree[xInd][yInd * 2 + 1] + tree[xInd][yInd * 2 + 2];

	}
	void buildRows(int ind,int l,int r,vector<vector<int>>&grid) {
		if(l != r) {
			int mid = l + (r - l) / 2 ;
			buildRows(ind * 2 + 1, l, mid, grid);
			buildRows(ind * 2 + 2, mid + 1, r, grid);
		}
		buildCol(ind,l, r, 0, 0, m - 1, grid);
	}
	int queryCol(int xInd,int x1,int y1,int yInd,int x2, int y2, int lx, int ly, int rx, int ry) {
		if(ry < x2 || y2 < ly)
			return 0;
		if(ly <= x2 && y2 <= ry) {
			return tree[xInd][yInd];
		}
		int mid = x2 + (y2 - x2) / 2;
		int left = queryCol(xInd, x1, y1, yInd * 2 + 1, x2, mid,lx, ly, rx, ry);
		int right = queryCol(xInd, x1, y1, yInd * 2 + 2, mid + 1, y2, lx, ly, rx, ry);
		return left + right;
	}
	int queryRow(int ind,int x,int y,int lx,int ly,int rx,int ry) {
		if(rx < x || y < lx)
			return 0;

		if(lx <= x && y <= rx) {
			return queryCol(ind, x, y, 0, 0, m - 1, lx, ly, rx, ry);
		}
		int mid = x + (y - x) / 2;
		int left = queryRow(ind * 2 + 1, x,mid, lx, ly, rx, ry);
		int right = queryRow(ind * 2 + 2, mid + 1, y, lx, ly, rx, ry);
		return left + right;
	}
	int query(int x1,int y1,int x2,int y2) {
		return queryRow(0, 0, n - 1, x1, y1, x2, y2);
	}
	void updateCol(int xInd,int xl,int xr,int yInd,int yl,int yr,int x1,int x2,int val) {
		if(yl == yr) {
			if(xl == xr) {
				tree[xInd][yInd] = 1 - tree[xInd][yInd];
			}
			else {
				tree[xInd][yInd] = tree[xInd * 2 + 1][yInd] + tree[xInd * 2 + 2][yInd];
			}
			return;
		}
		int mid = yl + (yr - yl) / 2;
		if(x2 <= mid) {
			updateCol(xInd, xl, xr, yInd * 2 + 1, yl, mid, x1, x2, val);
		}
		else {
			updateCol(xInd, xl, xr, yInd * 2 + 2, mid + 1, yr, x1, x2, val);
		}
		tree[xInd][yInd] = tree[xInd][yInd * 2 + 1] + tree[xInd][yInd * 2 + 2];
	}
	void updateRow(int ind,int l,int r,int x1,int y1, int val) {
		if(l != r) {
			int mid = l + (r - l) / 2;
			if(x1 <= mid) {
				updateRow(ind * 2 + 1, l, mid, x1, y1, val);
			}
			else {
				updateRow(ind * 2 + 2,mid + 1, r, x1, y1, val);
			}
		}
		updateCol(ind, l, r, 0, 0, m - 1, x1, y1, val);
	}

	void update(int x,int y,int val) {
		updateRow(0, 0, n - 1, x, y, val);
	}

};
class NumMatrix {
public:
    Segment* seg;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        seg = new Segment(n,m,matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return seg->query(row1,col1,row2,col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */