#include "DispCompIeqcJecO.h"
#include "EndFrameqc.h"

using namespace MbD;

DispCompIeqcJecO::DispCompIeqcJecO()
{
}

DispCompIeqcJecO::DispCompIeqcJecO(EndFrmcptr frmi, EndFrmcptr frmj, int axis) : DispCompIecJecO(frmi, frmj, axis)
{
}

void DispCompIeqcJecO::initializeGlobally()
{
	priIeJeOpXI = std::make_shared<FullRow<double>>(3, 0.0);
	priIeJeOpXI->at(axis) = -1.0;
	ppriIeJeOpEIpEI = std::static_pointer_cast<EndFrameqc>(frmI)->ppriOeOpEpE(axis)->negated();
}

FMatDsptr MbD::DispCompIeqcJecO::ppvaluepEIpEI()
{
	return ppriIeJeOpEIpEI;
}

FRowDsptr MbD::DispCompIeqcJecO::pvaluepEI()
{
	return priIeJeOpEI;
}

FRowDsptr MbD::DispCompIeqcJecO::pvaluepXI()
{
	return priIeJeOpXI;
}

void DispCompIeqcJecO::calcPostDynCorrectorIteration()
{
	DispCompIecJecO::calcPostDynCorrectorIteration();
	priIeJeOpEI = std::static_pointer_cast<EndFrameqc>(frmI)->priOeOpE(axis)->negated();
}
