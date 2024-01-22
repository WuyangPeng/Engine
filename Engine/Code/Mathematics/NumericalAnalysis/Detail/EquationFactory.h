/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:53)

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
