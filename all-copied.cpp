#include <cstdio>
#include <vector>
using namespace std;


int main() {
    int N1, N2, D;
    while(~scanf("%d%d%d", &N1, &N2, &D)) {
        int fef[100032];
        if(N1 + N2 + D == 0) {
            break;
        }

        if(D == 0) {
            puts("3");
            continue;
        }

        int N = N1 + N2;
        for(int i = 1; i <= N; ++i) {
            fef[i] = 0;
        }

        vector<int> vec;
        vector< vector<int> > anti_adj(N + 1, vec);
        int X, Y, Z = 0;
        for(int i = 0; i < D; ++i) {
            scanf("%d%d", &X, &Y);
            if((X <= N1 && Y > N1) || (X > N1 && Y <= N1)) {
                anti_adj[Y].push_back(X);
                ++fef[X];
                ++Z;
            }
        }

        if(Z == 0) {
            puts("3");
            continue;
        }

        vector<int> d1, d2;
        for(int i = 1; i <= N1; ++i) {
            if((fef[i] > 0) || (fef[i] == 0 && anti_adj[i].size() > 0)) {
                d1.push_back(i);
            }
        }
        for(int i = N1 + 1; i <= N; ++i) {
            if((fef[i] > 0) || (fef[i] == 0 && anti_adj[i].size() > 0)) {
                d2.push_back(i);
            }
        }

        int Z1 = 0, Z2 = 0;
        if((int)d1.size() < N1) {
            Z1 = 1;
        }
        if((int)d2.size() < N2) {
            Z2 = 1;
        }

        int d_change = 1, d = -1;
        while(!(d1.size() == 0 && d2.size() == 0)) {
            int j, k;
            char conn = 0;
            vector<int> c1, c2, e1, e2;
            if(d <= 1) {
                for(j = 0, k = d1.size(); j < k; ++j) {
                    //printf("1) %d %d\n", d1[j], fef[d1[j]]);
                    if(fef[d1[j]] == 0) {
                        conn = 1;
                        c1.push_back(d1[j]);
                    } else if(fef[d1[j]] > 0) {
                        e1.push_back(d1[j]);
                    }
                }
                if(conn == 0) {
                    for(j = 0, k = d2.size(); j < k; ++j) {
                        //printf("2) %d %d\n", d2[j], fef[d2[j]]);
                        if(fef[d2[j]] == 0) {
                            conn = 2;
                            c2.push_back(d2[j]);
                        } else if(fef[d2[j]] > 0) {
                            e2.push_back(d2[j]);
                        }
                    }
                }
            } else {
                for(j = 0, k = d2.size(); j < k; ++j) {
                    //printf("3) %d %d\n", d2[j], fef[d2[j]]);
                    if(fef[d2[j]] == 0) {
                        conn = 2;
                        c2.push_back(d2[j]);
                    } else if(fef[d2[j]] > 0) {
                        e2.push_back(d2[j]);
                    }
                }
                if(conn == 0) {
                    for(j = 0, k = d1.size(); j < k; ++j) {
                        //printf("4) %d %d\n", d1[j], fef[d1[j]]);
                        if(fef[d1[j]] == 0) {
                            conn = 1;
                            c1.push_back(d1[j]);
                        } else if(fef[d1[j]] > 0) {
                            e1.push_back(d1[j]);
                        }
                    }
                }
            }

            if(conn == 0) {
                break;
            }

            if(conn == 1) {
                if(d != 1) {
                    ++d_change;
                }
                d = 1;
                Z1 = 0;
            } else {
                if(d != 2) {
                    ++d_change;
                }
                d = 2;
                Z2 = 0;
            }
            //printf(">%d %d\n",d, d_change);
            if(conn == 1) {
                for(j = 0, k = c1.size(); j < k; ++j) {
                    for(int p = 0, q = anti_adj[c1[j]].size(); p < q; ++p) {
                        --fef[anti_adj[c1[j]][p]];
                    }
                }
                d1.swap(e1);
            } else {
                for(j = 0, k = c2.size(); j < k; ++j) {
                    for(int p = 0, q = anti_adj[c2[j]].size(); p < q; ++p) {
                        --fef[anti_adj[c2[j]][p]];
                    }
                }
                d2.swap(e2);
            }
        }
        printf("%d\n", d_change + (Z1 > 0) + (Z2 > 0));
    }
    return 0;
}