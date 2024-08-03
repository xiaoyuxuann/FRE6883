#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
namespace fre {
    template<typename Type>
    class BinLattice02 {
        private:
            int N;
            vector< vector<Type> > Lattice;
        public:
            BinLattice02():N(0) {}
            BinLattice02(int N_) :N(N_) {
                Lattice.resize(N + 1);
                for (int n = 0; n <= N; n++) Lattice[n].resize(n + 1);
            }
            ~BinLattice02() {}
            void SetN(int N_) { 
                N=N_;
                Lattice.resize(N + 1);
                for (int n = 0; n <= N; n++) Lattice[n].resize(n + 1); 
            }
            void SetNode(int n, int i, Type x) { Lattice[n][i] = x; } 
            Type GetNode(int n, int i) { return Lattice[n][i]; }
            void Display(ofstream& f)
            { 
                f << setiosflags(ios::fixed) << setprecision(3);
                for (int n = 0; n <= N; n++) {
                    for (int i = 0; i <= n; i++)
                        f << setw(15) << GetNode(n, i);
                    f << endl; 
                }
                f << endl;
            }
    };
}