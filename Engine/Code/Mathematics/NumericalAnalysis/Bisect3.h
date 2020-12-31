///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 17:15)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect3Root.h"
#include "NumericalAnalysisInternalFwd.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3<Real>;
        using Function = Real (*)(Real, Real, Real);
        using Bisect3Root = Bisect3Root<Real>;
        using Math = Math<Real>;

    public:
        Bisect3(Function function0, Function function1, Function function2, int maxLevel, Real tolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Bisect3Root Bisect(Real beginPointX, Real beginPointY, Real beginPointZ,
                                               Real endPointX, Real endPointY, Real endPointZ) const;

        [[nodiscard]] Real GetFunction0Value(Real x, Real y, Real z) const noexcept;
        [[nodiscard]] Real GetFunction1Value(Real x, Real y, Real z) const noexcept;
        [[nodiscard]] Real GetFunction2Value(Real x, Real y, Real z) const noexcept;
        [[nodiscard]] int GetMaxLevel() const noexcept;
        [[nodiscard]] Real GetTolerance() const noexcept;

    private:
        using Bisect3Calculate = Bisect3Calculate<Real>;

    private:
        // 输入数据和函数。
        Function m_Function0;
        Function m_Function1;
        Function m_Function2;
        int m_MaxLevel;
        Real m_Tolerance;
    };

    using FloatBisect3 = Bisect3<float>;
    using DoubleBisect3 = Bisect3<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H
