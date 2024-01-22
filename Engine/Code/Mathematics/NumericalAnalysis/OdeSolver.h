/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:44)

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

        // ��ϵͳ��dx/dt = F(t,x)��
        // x��ά�ȴ��ݸ�OdeSolver�Ĺ��캯����Ҫ��x��F(t,x) ��Сһ�¡�
        // ����ֵF(t,x)
        using Function = Container (*)(Real,  // t
                                       const Container&,  // x
                                       const UserDataType*);  // �û���������

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
