#include "DispCompIeqcJeqcO.h"
#include "EndFrameqc.h"

using namespace MbD;

MbD::DispCompIeqcJeqcO::DispCompIeqcJeqcO()
{
}

MbD::DispCompIeqcJeqcO::DispCompIeqcJeqcO(EndFrmcptr frmi, EndFrmcptr frmj, int axis) : DispCompIeqcJecO(frmi, frmj, axis)
{
}

void MbD::DispCompIeqcJeqcO::initializeGlobally()
{
	DispCompIeqcJecO::initializeGlobally();
	priIeJeOpXJ = std::make_shared<FullRow<double>>(3, 0.0);
	priIeJeOpXJ->at(axis) = 1.0;
	ppriIeJeOpEJpEJ = std::static_pointer_cast<EndFrameqc>(frmJ)->ppriOeOpEpE(axis);
}

void MbD::DispCompIeqcJeqcO::calcPostDynCorrectorIteration()
{
	DispCompIeqcJecO::calcPostDynCorrectorIteration();
	priIeJeOpEJ = std::static_pointer_cast<EndFrameqc>(frmJ)->priOeOpE(axis);
}

FRowDsptr MbD::DispCompIeqcJeqcO::pvaluepXJ()
{
	return priIeJeOpXJ;
}

FRowDsptr MbD::DispCompIeqcJeqcO::pvaluepEJ()
{
	return priIeJeOpEJ;
}

FMatDsptr MbD::DispCompIeqcJeqcO::ppvaluepEJpEJ()
{
	return ppriIeJeOpEJpEJ;
}