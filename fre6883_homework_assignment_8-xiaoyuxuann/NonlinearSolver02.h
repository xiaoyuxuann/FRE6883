#pragma once
#include "Function.h" 
namespace fre {
    class NonlinearSolver02 {
        private:
            double Tgt; 
            double LEnd; 
            double REnd; 
            double Acc; 
            double Guess;
        public:
            NonlinearSolver02() : Tgt(0), LEnd(0), REnd(0), Acc(0), Guess(0) {}
            NonlinearSolver02(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_) : Tgt(Tgt_), LEnd(LEnd_), REnd(REnd_), Acc(Acc_), Guess(Guess_) {}
            ~NonlinearSolver02() {}
            void UpdateSolver(double Tgt_, double LEnd_, double REnd_, double Acc_, double Guess_) {
                Tgt = Tgt_;
                LEnd = LEnd_; REnd = REnd_; Acc = Acc_; Guess = Guess_;
            }
            double SolveByBisect(Function* Fct); 
            double SolveByNR(Function* Fct);
    }; 
}
