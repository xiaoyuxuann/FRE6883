#pragma once
#include "BinomialTreeModel.h"
namespace fre {
    class Option {
        private:
            Option() : N(0) {}
            Option(const Option& option) : N(option.N) {}
        protected:
            int N;
        public:
            Option(int N_) : N(N_) {}
            int GetN() const { return N; }
            virtual double Payoff(double z) const = 0;
            virtual ~Option() = 0;
    };
    
    class Call : public Option {
        private:
            double K;
        public:
            Call(int N_, double K_) : Option(N_), K(K_) {} ~Call() {}
            double Payoff(double z) const;
    };
    
    class OptionCalculation {
        private:
            Option* pOption;
            OptionCalculation() : pOption(0) {}
            OptionCalculation(const OptionCalculation& optionCalculation): pOption(optionCalculation.pOption) {}
        public:
            OptionCalculation(Option* pOption_) : pOption(pOption_){}
            ~OptionCalculation() {}
            double PriceBySnell(const BinomialTreeModel& Model);
    };
}