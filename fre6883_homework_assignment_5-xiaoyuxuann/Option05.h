#pragma once
#include "BinomialTreeModel.h"
namespace fre {
    class EurOption {
        private:
            EurOption() : N(0) {}
            EurOption(const EurOption& option) : N(option.N) {}
        protected:
            int N;
        public:
            EurOption(int N_) : N(N_) {}
            int GetN() const { return N; }
            virtual double Payoff(double z) const = 0;
            virtual ~EurOption() = 0;
    };
    
    class OptionCalculation {
        private:
            EurOption* pOption;
            OptionCalculation() : pOption(0) {}
            OptionCalculation(const OptionCalculation& optionCalculation): pOption(optionCalculation.pOption) {}
        public:
            OptionCalculation(EurOption* pOption_) : pOption(pOption_){}
            ~OptionCalculation() {}
            double PriceByCRR(const BinomialTreeModel& model);
    };
}