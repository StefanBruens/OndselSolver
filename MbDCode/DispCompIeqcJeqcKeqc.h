#pragma once

#include "DispCompIeqcJecKeqc.h"

namespace MbD {
    class DispCompIeqcJeqcKeqc : public DispCompIeqcJecKeqc
    {
        //priIeJeKepXJ priIeJeKepEJ ppriIeJeKepXJpEK ppriIeJeKepEJpEJ ppriIeJeKepEJpEK 
    public:
        DispCompIeqcJeqcKeqc();
        DispCompIeqcJeqcKeqc(EndFrmcptr frmi, EndFrmcptr frmj, EndFrmcptr frmk, int axisk);
        void initialize() override;
        void calcPostDynCorrectorIteration() override;
        FRowDsptr pvaluepXJ() override;
        FRowDsptr pvaluepEJ() override;
        FMatDsptr ppvaluepXJpEK();
        FMatDsptr ppvaluepEJpEK();
        FMatDsptr ppvaluepEJpEJ() override;

        FRowDsptr priIeJeKepXJ;
        FRowDsptr priIeJeKepEJ;
        FMatDsptr ppriIeJeKepXJpEK;
        FMatDsptr ppriIeJeKepEJpEJ;
        FMatDsptr ppriIeJeKepEJpEK;
    };
}
