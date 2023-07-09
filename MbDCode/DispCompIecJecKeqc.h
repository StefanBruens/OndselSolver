#pragma once

#include "DispCompIecJecKec.h"

namespace MbD {
    class DispCompIecJecKeqc : public DispCompIecJecKec
    {
        //priIeJeKepEK ppriIeJeKepEKpEK pAjOKepEKT ppAjOKepEKpEK 
    public:
        DispCompIecJecKeqc();
        DispCompIecJecKeqc(EndFrmcptr frmi, EndFrmcptr frmj, EndFrmcptr frmk, int axisk);

        void calcPostDynCorrectorIteration() override;
        void initialize() override;
        void initializeGlobally() override;
        FMatDsptr ppvaluepEKpEK() override;
        FRowDsptr pvaluepEK() override;

        FRowDsptr priIeJeKepEK;
        FMatDsptr ppriIeJeKepEKpEK;
        FMatDsptr pAjOKepEKT;
        FMatFColDsptr ppAjOKepEKpEK;
    };
}

