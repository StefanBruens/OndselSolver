#include <cassert>

#include "GESpMatParPvMarko.h"
#include "SingularMatrixError.h"

using namespace MbD;

void MbD::GESpMatParPvMarko::doPivoting(int p)
{
	//"Search from bottom to top."
	//"Check for singular pivot."
	//"Do scaling. Do partial pivoting."
	//"criterion := mag / (2.0d raisedTo: rowiCount)."
	//| lookForFirstNonZeroInPivotCol i rowi aip criterionMax rowPivoti criterion max |
	int i, rowPivoti;
	double aip, mag, max, criterion, criterionMax;
	SpRowDsptr spRowi;
	rowPositionsOfNonZerosInPivotColumn->clear();
	auto lookForFirstNonZeroInPivotCol = true;
	i = m - 1;
	while (lookForFirstNonZeroInPivotCol) {
		spRowi = matrixA->at(i);
		if (spRowi->find(p) == spRowi->end()) {
			if (i <= p) throw SingularMatrixError("");
		}
		else {
			markowitzPivotColCount = 0;
			aip = spRowi->at(p);
			mag = aip * rowScalings->at(i);
			if (mag < 0) mag = -mag;
			max = mag;
			criterionMax = mag / std::pow(2.0, spRowi->size());
			rowPivoti = i;
			lookForFirstNonZeroInPivotCol = false;
		}
		i--;
	}
	while (i >= p) {
		spRowi = matrixA->at(i);
		if (spRowi->find(p) == spRowi->end()) {
			aip = std::numeric_limits<double>::min();
		}
		else {
			aip = spRowi->at(p);
			markowitzPivotColCount++;
			mag = aip * rowScalings->at(i);
			if (mag < 0) mag = -mag;
			criterion = mag / std::pow(2.0, spRowi->size());
			if (criterion > criterionMax) {
				max = mag;
				criterionMax = criterion;
				rowPositionsOfNonZerosInPivotColumn->push_back(rowPivoti);
				rowPivoti = i;
			}
			else {
				rowPositionsOfNonZerosInPivotColumn->push_back(i);
			}
		}
		i--;
	}
	if (p != rowPivoti) {
		matrixA->swapElems(p, rowPivoti);
		rightHandSideB->swapElems(p, rowPivoti);
		rowScalings->swapElems(p, rowPivoti);
		if (aip != std::numeric_limits<double>::min()) rowPositionsOfNonZerosInPivotColumn->at(markowitzPivotColCount - 1) = rowPivoti;
	}
	if (max < singularPivotTolerance) throw SingularMatrixError("");
}

void MbD::GESpMatParPvMarko::preSolvewithsaveOriginal(SpMatDsptr spMat, FColDsptr fullCol, bool saveOriginal)
{
	assert(false);
}