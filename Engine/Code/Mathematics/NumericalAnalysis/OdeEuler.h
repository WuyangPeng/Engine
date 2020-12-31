///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 10:07)

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
        using Data = ParentType::Data;
        using Function = typename ParentType::Function;
        using Container = typename ParentType::Container;

    public:
        OdeEuler(int dimension, Real step, typename Function function, const UserDataType* userData);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        Data Update(Real tIn, const Container& xIn) override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_EULER_H
