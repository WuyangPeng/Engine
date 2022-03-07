///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/13 14:42)

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
