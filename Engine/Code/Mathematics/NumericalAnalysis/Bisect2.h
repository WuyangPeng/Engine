///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 11:23)

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

        using Math = Math<Real>;
        using Function = Real (*)(Real, Real);
        using Bisect2Root = Bisect2Root<Real>;
        using Bisect2Calculate = Bisect2Calculate<Real>;

    public:
        Bisect2(Function function0, Function function1, int maxLevel, Real tolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Bisect2Root Bisect(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY) const;

        NODISCARD Real GetFunction0Value(Real x, Real y) const;
        NODISCARD Real GetFunction1Value(Real x, Real y) const;
        NODISCARD int GetMaxLevel() const noexcept;
        NODISCARD Real GetTolerance() const noexcept;

    private:
        // 输入数据和函数。
        Function function0;
        Function function1;
        int maxLevel;
        Real tolerance;
    };

    using Bisect2F = Bisect2<float>;
    using Bisect2D = Bisect2<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_H
