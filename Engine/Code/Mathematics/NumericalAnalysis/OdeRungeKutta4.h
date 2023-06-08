///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include "OdeSolver.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class OdeRungeKutta4 : public OdeSolver<Real, UserDataType>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = OdeRungeKutta4<Real, UserDataType>;
        using ParentType = OdeSolver<Real, UserDataType>;
        using Math = Math<Real>;
        using Data = typename ParentType::Data;
        using Function = typename ParentType::Function;
        using Container = typename ParentType::Container;

    public:
        OdeRungeKutta4(int dimension, Real step, Function function, const UserDataType* userData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Data Update(Real tIn, const Container& xIn) override;
        void SetStepSize(Real step) noexcept override;

    private:
        Real halfStep;
        Real sixthStep;
        Container stepFunctionValue1;
        Container stepFunctionValue2;
        Container stepFunctionValue3;
        Container stepFunctionValue4;
        Container xIn1;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_RUNGE_KUTTA4_H
