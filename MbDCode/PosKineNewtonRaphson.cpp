#include "PosKineNewtonRaphson.h"
#include "SystemSolver.h"
#include "Part.h"
#include "NotKinematicError.h"
#include "Constraint.h"

using namespace MbD;

void MbD::PosKineNewtonRaphson::initializeGlobally()
{
	SystemNewtonRaphson::initializeGlobally();
	system->partsJointsMotionsDo([&](std::shared_ptr<Item> item) { item->fillqsu(x); });
	iterMax = system->iterMaxPosKine;
	dxTol = system->errorTolPosKine;
}

void MbD::PosKineNewtonRaphson::fillPyPx()
{
	pypx->zeroSelf();
	system->partsJointsMotionsDo([&](std::shared_ptr<Item> item) {
		item->fillPosKineJacob(pypx);
		});
}

void MbD::PosKineNewtonRaphson::passRootToSystem()
{
	system->partsJointsMotionsDo([&](std::shared_ptr<Item> item) { item->setqsu(x); });
}

void MbD::PosKineNewtonRaphson::assignEquationNumbers()
{
	//"Equation order is q,s,u."
	auto parts = system->parts();
	//auto contactEndFrames = system->contactEndFrames();
	//auto uHolders = system->uHolders();
	auto constraints = system->allConstraints();
	int varNo = 0;
	for (auto& part : *parts) {
		part->iqX(varNo);
		varNo = varNo + 3;
		part->iqE(varNo);
		varNo = varNo + 4;
	}
	//for (auto& endFrm : *contactEndFrames) {
	//	endFrm->is(varNo);
	//	varNo = varNo + endFrm->sSize();
	//}
	//for (auto& uHolder : *uHolders) {
	//	uHolder->iu(varNo);
	//	varNo += 1;
	//}
	auto eqnNo = 0;
	for (auto& con : *constraints) {
		con->iG = eqnNo;
		eqnNo += 1;
	}
	n = eqnNo;	//C++ uses index 0.
	if (varNo != eqnNo) {
		std::string str = "MbD: SYSTEM IS NOT PURE KINEMATIC.";
		system->logString(str);
		throw NotKinematicError("");
	}
}

void MbD::PosKineNewtonRaphson::preRun()
{
	std::string str = "MbD: Solving for kinematic position.";
	system->logString(str);
	system->partsJointsMotionsDo([](std::shared_ptr<Item> item) { item->prePosKine(); });
}

void MbD::PosKineNewtonRaphson::fillY()
{
	y->zeroSelf();
	system->partsJointsMotionsDo([&](std::shared_ptr<Item> item) { item->fillPosKineError(y); });
}