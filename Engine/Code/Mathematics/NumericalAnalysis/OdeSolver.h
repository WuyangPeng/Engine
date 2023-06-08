///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class OdeSolver
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = OdeSolver<Real, UserDataType>;
        using Container = std::vector<Real>;

        struct Data
        {
            Real t;
            Container x;

            Data(Real t, const Container& x);
        };

        // 该系统是dx/dt = F(t,x)。
        // x的维度传递给OdeSolver的构造函数，要和x和F(t,x) 大小一致。
        // 返回值F(t,x)
        using Function = Container (*)(Real,  // t
                                       const Container&,  // x
                                       const UserDataType*);  // 用户定义数据

    public:
        OdeSolver(int dimension, Real step, Function function, const UserDataType* userData);
        virtual ~OdeSolver() = default;
        OdeSolver(const OdeSolver& rhs) = default;
        OdeSolver& operator=(const OdeSolver& rhs) = default;
        OdeSolver(OdeSolver&& rhs) noexcept = default;
        OdeSolver& operator=(OdeSolver&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual Data Update(Real tIn, const Container& xIn) = 0;
        virtual void SetStepSize(Real newStep) noexcept;
        NODISCARD Real GetStepSize() const noexcept;
        void SetUserData(const UserDataType* newUserData) noexcept;
        NODISCARD const UserDataType* GetUserData() const noexcept;
        NODISCARD int GetDimension() const noexcept;

    protected:
        void CalculateFunctionValue(Real tIn, const Container& xIn);

        NODISCARD Real GetStepFunctionValue(int index) const;
        NODISCARD Real GetFunctionValue(int index) const;
        NODISCARD Container GetFunctionValue() const;
        void SetFunctionValue(const Container& newFunctionValue);

    private:
        int dimension;
        Function function;
        const UserDataType* userData;
        Real step;
        Container functionValue;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H
