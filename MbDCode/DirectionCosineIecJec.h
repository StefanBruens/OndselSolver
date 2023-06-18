#pragma once
#include <memory>

#include "KinematicIeJe.h"

namespace MbD {
    template<typename T>
    class FullColumn;

    class DirectionCosineIecJec : public KinematicIeJe
    {
        //aAijIeJe axisI axisJ aAjOIe aAjOJe 
    public:
        DirectionCosineIecJec();
        DirectionCosineIecJec(EndFrmcptr frmi, EndFrmcptr frmj, int axisi, int axisj);
        void calcPostDynCorrectorIteration() override;
        FRowDsptr pvaluepXJ() override;
        FRowDsptr pvaluepEJ() override;
        FMatDsptr ppvaluepXJpEK() override;
        FMatDsptr ppvaluepEJpEK() override;
        FMatDsptr ppvaluepEJpEJ() override;

        int axisI, axisJ;   //0, 1, 2 = x, y, z
        double aAijIeJe;
        std::shared_ptr<FullColumn<double>> aAjOIe, aAjOJe;
    };
}
