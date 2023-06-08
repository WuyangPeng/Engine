///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect1Root.h"
#include "Mathematics/Base/MathDetail.h"

// 二分法解方程
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect1 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect1<Real>;
        using Math = Math<Real>;
        using Function = Real (*)(Real);
        using Bisect1Root = Bisect1Root<Real>;

    public:
        Bisect1(Function function, int maxLevel, Real tolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 通过根的求解区间端点来解方程
        NODISCARD Bisect1Root Bisect(Real beginPoint, Real endPoint);

    private:
        // 输入数据和函数。
        Function function;
        int maxLevel;
        Real tolerance;
    };

    using Bisect1F = Bisect1<float>;
    using Bisect1D = Bisect1<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H
