///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect2Root.h"
#include "NumericalAnalysisInternalFwd.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2<Real>;
        using Function = Real (*)(Real, Real);
        using Bisect2Calculate = Bisect2Calculate<Real>;
        using Bisect2Root = Bisect2Root<Real>;
        using Math = Math<Real>;

    public:
        Bisect2(Function function0, Function function1, int maxLevel, Real tolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Bisect2Root Bisect(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY) const;

        [[nodiscard]] Real GetFunction0Value(Real x, Real y) const noexcept;
        [[nodiscard]] Real GetFunction1Value(Real x, Real y) const noexcept;
        [[nodiscard]] int GetMaxLevel() const noexcept;
        [[nodiscard]] Real GetTolerance() const noexcept;

    private:
        // 输入数据和函数。
        Function m_Function0;
        Function m_Function1;
        int m_MaxLevel;
        Real m_Tolerance;
    };

    using FloatBisect2 = Bisect2<float>;
    using DoubleBisect2 = Bisect2<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H
