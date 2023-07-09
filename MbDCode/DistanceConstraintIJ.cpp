#include "DistanceConstraintIJ.h"

using namespace MbD;

MbD::DistanceConstraintIJ::DistanceConstraintIJ(EndFrmcptr frmi, EndFrmcptr frmj) : ConstraintIJ(frmi, frmj)
{
}

void MbD::DistanceConstraintIJ::calcPostDynCorrectorIteration()
{
aG = distIeJe->value() - aConstant;
}

void MbD::DistanceConstraintIJ::initialize()
{
	ConstraintIJ::initialize();
	this->init_distIeJe();
}

void MbD::DistanceConstraintIJ::initializeGlobally()
{
	distIeJe->initializeGlobally();
}

void MbD::DistanceConstraintIJ::initializeLocally()
{
	distIeJe->initializeLocally();
}

void MbD::DistanceConstraintIJ::postInput()
{
	distIeJe->postInput();
	ConstraintIJ::postInput();
}

void MbD::DistanceConstraintIJ::postPosICIteration()
{
	distIeJe->postPosICIteration();
	ConstraintIJ::postPosICIteration();
}

void MbD::DistanceConstraintIJ::preAccIC()
{
	distIeJe->preAccIC();
	ConstraintIJ::preAccIC();
}

void MbD::DistanceConstraintIJ::prePosIC()
{
	distIeJe->prePosIC();
	ConstraintIJ::prePosIC();
}

void MbD::DistanceConstraintIJ::preVelIC()
{
	distIeJe->preVelIC();
	ConstraintIJ::preVelIC();
}

void MbD::DistanceConstraintIJ::simUpdateAll()
{
	distIeJe->simUpdateAll();
	ConstraintIJ::simUpdateAll();
}

ConstraintType MbD::DistanceConstraintIJ::type()
{
	return ConstraintType::displacement;
}
