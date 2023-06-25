#pragma once

#include "DirectionCosineIeqcJeqc.h"

namespace MbD {
    class DirectionCosineIeqctJeqc : public DirectionCosineIeqcJeqc
    {
        //pAijIeJept ppAijIeJepEIpt ppAijIeJepEJpt ppAijIeJeptpt 
    public:
        DirectionCosineIeqctJeqc();
        DirectionCosineIeqctJeqc(EndFrmcptr frmi, EndFrmcptr frmj, int axisi, int axisj);
        void initialize() override;
        void initializeGlobally();
        void calcPostDynCorrectorIteration() override;
        void preVelIC() override;
        double pvaluept();
        void preAccIC() override;

        double pAijIeJept;
        FRowDsptr ppAijIeJepEIpt;
        FRowDsptr ppAijIeJepEJpt;
        double ppAijIeJeptpt;
    };
}

