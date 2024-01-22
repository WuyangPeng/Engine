/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_FACTORY_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_FACTORY_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/NumericalAnalysisInternalFwd.h"

#include <memory>

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE EquationFactory final
    {
    public:
        using ClassType = EquationFactory;

        using EquationImplSharedPtr = std::shared_ptr<EquationImpl>;

    public:
        NODISCARD static EquationImplSharedPtr Create(double constant, double once, double secondary = 0.0, double thrice = 0.0, double quartic = 0.0, double epsilon = MathD::GetZeroTolerance());
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EQUATION_FACTORY_H
