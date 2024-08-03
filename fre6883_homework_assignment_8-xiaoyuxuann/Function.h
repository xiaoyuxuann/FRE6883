#pragma once
namespace fre {
    class Function{
        public:
            virtual double Value(double y) = 0;
            virtual double Deriv(double y) = 0;
            virtual~Function() {}
    };
}