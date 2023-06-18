#include "IndependentVariable.h"
#include "Constant.h"

using namespace MbD;

MbD::IndependentVariable::IndependentVariable()
{
}

Symsptr MbD::IndependentVariable::differentiateWRT(Symsptr sptr, Symsptr var)
{
	if (this == var.get()) {
		return std::make_shared<Constant>(1.0);
	}
	else {
		return std::make_shared<Constant>(0.0);
	}
}