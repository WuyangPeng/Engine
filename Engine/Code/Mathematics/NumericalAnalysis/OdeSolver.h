///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 10:03)

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
            Real m_T;
            Container m_X;

            Data(Real t, const Container& x);
        };     

        // ��ϵͳ��dx/dt = F(t,x)��
        // x��ά�ȴ��ݸ�OdeSolver�Ĺ��캯����Ҫ��x��F(t,x) ��Сһ�¡�
        // ����ֵF(t,x)
        using Function = const Container (*)(Real,  // t
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

        virtual Data Update(Real tIn, const Container& xIn) = 0;
        virtual void SetStepSize(Real step) noexcept;
        [[nodiscard]] Real GetStepSize() const noexcept;
        void SetUserData(const UserDataType* UserData) noexcept;
        [[nodiscard]] const UserDataType* GetUserData() const noexcept;
        [[nodiscard]] int GetDimension() const noexcept;

    protected:
        void CalculateFunctionValue(Real tIn, const Container& xIn);

        [[nodiscard]] Real GetStepFunctionValue(int index) const;
        [[nodiscard]] Real GetFunctionValue(int index) const;
        [[nodiscard]] const Container GetFunctionValue() const;
        void SetFunctionValue(const Container& functionValue);

    private:
        int m_Dimension;
        Function m_Function;
        const UserDataType* m_UserData;
        Real m_Step;
        Container m_FunctionValue;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ODE_SOLVER_H
