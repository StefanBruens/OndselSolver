#include "MarkerFrame.h"
#include "EndFramec.h"
#include "EndFrameqc.h"

using namespace MbD;

MarkerFrame::MarkerFrame()
{
	partFrame = nullptr;
	auto endFrm = std::make_shared<EndFrameqc>();
	std::string str = "EndFrame1";
	endFrm->setName(str);
	this->addEndFrame(endFrm);
}

void MarkerFrame::setPartFrame(PartFrame* partFrm)
{
	partFrame = partFrm;
}

void MarkerFrame::setrpmp(FullColDptr x)
{
	rpmp->copy(x);
}

void MarkerFrame::setaApm(FullMatDptr x)
{
	aApm->copy(x);
}
void MarkerFrame::addEndFrame(std::shared_ptr<EndFramec> endFrm)
{
	endFrm->setMarkerFrame(this);
	endFrames.push_back(endFrm);
}
