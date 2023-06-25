#include "TranslationConstraintIqcJqc.h"
#include "DispCompIeqcJeqcKeqc.h"
#include "EndFrameqc.h"
#include "CREATE.h"

using namespace MbD;

TranslationConstraintIqcJqc::TranslationConstraintIqcJqc(EndFrmcptr frmi, EndFrmcptr frmj, int axisi) :
	TranslationConstraintIqcJc(frmi, frmj, axisi)
{
}

void MbD::TranslationConstraintIqcJqc::initriIeJeIe()
{
	riIeJeIe = CREATE<DispCompIeqcJeqcKeqc>::With(frmI, frmJ, frmI, axisI);
}

void MbD::TranslationConstraintIqcJqc::calcPostDynCorrectorIteration()
{
	TranslationConstraintIqcJc::calcPostDynCorrectorIteration();
	pGpXJ = riIeJeIe->pvaluepXJ();
	pGpEJ = riIeJeIe->pvaluepEJ();
	ppGpEIpXJ = riIeJeIe->ppvaluepXJpEK()->transpose();
	ppGpEIpEJ = riIeJeIe->ppvaluepEJpEK()->transpose();
	ppGpEJpEJ = riIeJeIe->ppvaluepEJpEJ();
}

void MbD::TranslationConstraintIqcJqc::useEquationNumbers()
{
	TranslationConstraintIqcJc::useEquationNumbers();
	iqXJ = std::static_pointer_cast<EndFrameqc>(frmJ)->iqX();
	iqEJ = std::static_pointer_cast<EndFrameqc>(frmJ)->iqE();
}

void MbD::TranslationConstraintIqcJqc::fillPosICError(FColDsptr col)
{
	TranslationConstraintIqcJc::fillPosICError(col);
	col->atiplusFullVectortimes(iqXJ, pGpXJ, lam);
	col->atiplusFullVectortimes(iqEJ, pGpEJ, lam);
}

void MbD::TranslationConstraintIqcJqc::fillPosICJacob(SpMatDsptr mat)
{
	TranslationConstraintIqcJc::fillPosICJacob(mat);
	mat->atijplusFullRow(iG, iqXJ, pGpXJ);
	mat->atijplusFullColumn(iqXJ, iG, pGpXJ->transpose());
	mat->atijplusFullRow(iG, iqEJ, pGpEJ);
	mat->atijplusFullColumn(iqEJ, iG, pGpEJ->transpose());
	auto ppGpEIpXJlam = ppGpEIpXJ->times(lam);
	mat->atijplusFullMatrix(iqEI, iqXJ, ppGpEIpXJlam);
	mat->atijplusTransposeFullMatrix(iqXJ, iqEI, ppGpEIpXJlam);
	auto ppGpEIpEJlam = ppGpEIpEJ->times(lam);
	mat->atijplusFullMatrix(iqEI, iqEJ, ppGpEIpEJlam);
	mat->atijplusTransposeFullMatrix(iqEJ, iqEI, ppGpEIpEJlam);
	mat->atijplusFullMatrixtimes(iqEJ, iqEJ, ppGpEJpEJ, lam);
}

void MbD::TranslationConstraintIqcJqc::fillPosKineJacob(SpMatDsptr mat)
{
	TranslationConstraintIqcJc::fillPosKineJacob(mat);
	mat->atijplusFullRow(iG, iqXJ, pGpXJ);
	mat->atijplusFullRow(iG, iqEJ, pGpEJ);
}

void MbD::TranslationConstraintIqcJqc::fillVelICJacob(SpMatDsptr mat)
{
	TranslationConstraintIqcJc::fillVelICJacob(mat);
	mat->atijplusFullRow(iG, iqXJ, pGpXJ);
	mat->atijplusFullColumn(iqXJ, iG, pGpXJ->transpose());
	mat->atijplusFullRow(iG, iqEJ, pGpEJ);
	mat->atijplusFullColumn(iqEJ, iG, pGpEJ->transpose());
}

void MbD::TranslationConstraintIqcJqc::fillAccICIterError(FColDsptr col)
{
	TranslationConstraintIqcJc::fillAccICIterError(col);
	col->atiplusFullVectortimes(iqXJ, pGpXJ, lam);
	col->atiplusFullVectortimes(iqEJ, pGpEJ, lam);
	auto efrmIqc = std::static_pointer_cast<EndFrameqc>(frmI);
	auto efrmJqc = std::static_pointer_cast<EndFrameqc>(frmJ);
	auto qEdotI = efrmIqc->qEdot();
	auto qXdotJ = efrmJqc->qXdot();
	auto qEdotJ = efrmJqc->qEdot();
	double sum = pGpXJ->timesFullColumn(efrmJqc->qXddot());
	sum += pGpEJ->timesFullColumn(efrmJqc->qEddot());
	sum += 2.0 * (qEdotI->transposeTimesFullColumn(ppGpEIpXJ->timesFullColumn(qXdotJ)));
	sum += 2.0 * (qEdotI->transposeTimesFullColumn(ppGpEIpEJ->timesFullColumn(qEdotJ)));
	sum += qEdotJ->transposeTimesFullColumn(ppGpEJpEJ->timesFullColumn(qEdotJ));
	col->atiplusNumber(iG, sum);
}
