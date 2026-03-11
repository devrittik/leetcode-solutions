class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,int cStart) {
        int rs = rStart, re = rStart + 1, cs = cStart, ce = cStart + 1;
        vector<vector<int>> matrixMF;
        int x, y, z;
        int lap = 0;
        int k1 = 1, k2 = -1;

        while (true) {

            if (lap % 2 == 0) {
                x = rs;
                y = cs;
                z = ce;
            } else {
                x = cs;
                y = rs;
                z = re;
            }

            if (z >= y) {
                for (int i = y; i <= z; i++) {
                    if (lap % 2 == 0) {
                        if (i >= 0 && i < cols && x >= 0 && x < rows) {
                            matrixMF.push_back({x, i});
                        }
                    } else {
                        if (i >= 0 && i < rows && x >= 0 && x < cols) {
                            matrixMF.push_back({i, x});
                        }
                    }

                    if(matrixMF.size()==rows*cols){
                        break;
                    }
                }
            } else {
                for (int i = y; i >= z; i--) {
                    if (lap % 2 == 0) {
                        if (i >= 0 && i < cols && x >= 0 && x < rows) {
                            matrixMF.push_back({x, i});
                        }
                    } else {
                        if (i >= 0 && i < rows && x >= 0 && x < cols) {
                            matrixMF.push_back({i, x});
                        }
                    }

                    if(matrixMF.size()==rows*cols){
                        break;
                    }
                }
            }

            if(matrixMF.size()==rows*cols){
                break;
            }

            if (lap != 0) {
                switch (lap % 4) {
                    case 0:
                        k1 = 1;
                        k2 = -2;
                        break;
                    case 1:
                        k1 = -1;
                        k2 = -2;
                        break;
                    case 2:
                        k1 = -1;
                        k2 = 2;
                        break;
                    case 3:
                        k1 = 1;
                        k2 = 2;
                        break;
                }
            }

            switch (lap % 2) {
                case 0:
                    rs += k1;
                    swap(cs, ce);
                    ce += k2;
                    break;
                case 1:
                    cs += k1;
                    swap(rs, re);
                    re += k2;
                    break;
            }

            lap++;
        }
        return matrixMF;
    }
};