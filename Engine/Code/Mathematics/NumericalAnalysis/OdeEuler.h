/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "OdeSolver.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class OdeEuler : public OdeSolver<Real, UserDataType>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = OdeEuler<Real, UserDataType>;
        using ParentType = OdeSolver<Real, UserDataType>;

        using Data = typename ParentType::Data;
        using Function = typename ParentType::Function;
        using Container = typename ParentType::Container;

    public:
        OdeEuler(int dimension, Real step, Function function, const UserDataType* userData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Data Update(Real tIn, const Container& xIn) override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H
