#pragma once

#include "DistIecJec.h"

namespace MbD {
    class DistIeqcJec : public DistIecJec
    {
        //prIeJepXI prIeJepEI pprIeJepXIpXI pprIeJepXIpEI pprIeJepEIpEI mprIeJeOpEIT 
    public:
        DistIeqcJec();
        DistIeqcJec(EndFrmcptr frmi, EndFrmcptr frmj);

        void calcPrivate() override;
        void initialize() override;
        FMatDsptr ppvaluepEIpEI();
        FMatDsptr ppvaluepXIpEI();
        FMatDsptr ppvaluepXIpXI();
        FRowDsptr pvaluepEI();
        FRowDsptr pvaluepXI();

        FRowDsptr prIeJepXI, prIeJepEI;
        FMatDsptr pprIeJepXIpXI, pprIeJepXIpEI, pprIeJepEIpEI, mprIeJeOpEIT;
    };
}

