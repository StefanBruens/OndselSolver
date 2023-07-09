#pragma once

#include "OrbitAnglezIeqcJec.h"

namespace MbD {
    class OrbitAnglezIeqcJeqc : public OrbitAnglezIeqcJec
    {
        //pthezpXJ pthezpEJ ppthezpXIpXJ ppthezpXIpEJ ppthezpEIpXJ ppthezpEIpEJ ppthezpXJpXJ ppthezpXJpEJ ppthezpEJpEJ 
    public:
			void calc_ppthezpEIpEJ();
			void calc_ppthezpEIpXJ();
			void calc_ppthezpEJpEJ();
			void calc_ppthezpXIpEJ();
			void calc_ppthezpXIpXJ();
			void calc_ppthezpXJpEJ();
			void calc_ppthezpXJpXJ();
			void calc_pthezpEJ();
			void calc_pthezpXJ();
			void calcPostDynCorrectorIteration() override;
			void initialize() override;
			FMatDsptr ppvaluepEIpEJ() override;
			FMatDsptr ppvaluepEIpXJ() override;
			FMatDsptr ppvaluepEJpEJ() override;
			FMatDsptr ppvaluepXIpEJ() override;
			FMatDsptr ppvaluepXIpXJ() override;
			FMatDsptr ppvaluepXJpEJ() override;
			FMatDsptr ppvaluepXJpXJ() override;
			FRowDsptr pvaluepEJ() override;
			FRowDsptr pvaluepXJ() override;


        FRowDsptr pthezpXJ, pthezpEJ;
        FMatDsptr ppthezpXIpXJ, ppthezpXIpEJ, ppthezpEIpXJ, ppthezpEIpEJ, ppthezpXJpXJ, ppthezpXJpEJ, ppthezpEJpEJ;
    };
}

