///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/23 16:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H

#include "Mathematics/MathematicsDll.h"

#include "BrentsMethodRoot.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class BrentsMethod final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethod<Real, UserDataType>;
        using Math = Math<Real>;
        using BrentsMethodRoot = BrentsMethodRoot<Real>;

        // 一个函数F(x)，但有一个额外的参数，
        // 让你传递用户定义的数据给需要评估的函数。
        using Function = Real (*)(Real, const UserDataType*);

    public:
        // 这是Brent的方法用于计算一个函数的根的间隔[x0,x1]的量f(x0) * f(x1) < 0的方法，
        // 使用逆二次插值，以产生一个估计根，
        // 如果需要的话，在后面的实施逆线性内插（正割法）。
        // 此外，基于先前迭代中，当它出现内插的估计是不足够质量时，该方法将回退到二分法。

        //  function:
        //  函数，其根是理想的。函数指针必须非空。

        //  maxIterations:
        //  用于定位一个根的最大迭代次数。它应该是正的。
        //  negativeFTolerance, positiveFTolerance:
        //  根估计x被接受时的函数值f(x)满足
        //  negativeFTolerance <= f(x) <= positiveFTolerance。
        //  值必须满足：negativeFTolerance <= 0, positiveFTolerance >= 0。
        //  stepXTolerance:
        //  Brent的方法需要额外的测试之前，内插x值被接受为下一个估计根。
        //  这些测试进行比较的连续迭代的差异，
        //  并要求它比用户指定的x公差较大（制造确保进度）。
        //  此参数是偏差。
        //  convXTolerance:
        //  根被允许搜索时，终止当前子迭代[xsub0,xsub1]是足够小的，
        //  也就是说，|xsub1 - xsub0| <= tolerance。此参数是偏差。
        //  userData:
        //  此参数允许你传递是需要评估的函数专门的数据。
        //  通常情况下，“function”是一个类的静态函数（以获得C风格的函数指针）
        //  和“userData”是'this'（或类数据的一个子集的“this”指针）。

        BrentsMethod(Function function, int maxIterations, Real negativeFTolerance, Real positiveFTolerance,
                     Real stepXTolerance, Real convXTolerance, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetFunction(Function function);
        [[nodiscard]] Function GetFunction() const noexcept;
        void SetMaxIterations(int maxIterations) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] int GetMaxIterations() const noexcept;
        void SetNegativeFTolerance(Real negativeFTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetNegativeFTolerance() const noexcept;
        void SetPositiveFTolerance(Real positiveFTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetPositiveFTolerance() const noexcept;
        void SetStepXTolerance(Real stepXTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetStepXTolerance() const noexcept;
        void SetConvXTolerance(Real convXTolerance) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real GetConvXTolerance() const noexcept;
        void SetUserData(const UserDataType* userData) noexcept;
        [[nodiscard]] const UserDataType* GetUserData() const noexcept;

        [[nodiscard]] Real GetFunctionValue(Real value) const;

        // 当返回的根有解时，x是根和y是根的函数值。
        [[nodiscard]] const BrentsMethodRoot GetRoot(Real begin, Real end);

    private:
        Function m_Function;
        int m_MaxIterations;
        Real m_NegativeFTolerance;
        Real m_PositiveFTolerance;
        Real m_StepXTolerance;
        Real m_ConvXTolerance;
        const UserDataType* m_UserData;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_H
