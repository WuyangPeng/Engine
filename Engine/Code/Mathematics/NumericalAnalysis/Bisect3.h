///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/14 13:36)

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

        NODISCARD Bisect3Root Bisect(Real beginPointX,
                                     Real beginPointY,
                                     Real beginPointZ,
                                     Real endPointX,
                                     Real endPointY,
                                     Real endPointZ) const;

        NODISCARD Real GetFunction0Value(Real x, Real y, Real z) const;
        NODISCARD Real GetFunction1Value(Real x, Real y, Real z) const;
        NODISCARD Real GetFunction2Value(Real x, Real y, Real z) const;
        NODISCARD int GetMaxLevel() const noexcept;
        NODISCARD Real GetTolerance() const noexcept;

    private:
        using Bisect3Calculate = Bisect3Calculate<Real>;

    private:
        // 输入数据和函数。
        Function function0;
        Function function1;
        Function function2;
        int maxLevel;
        Real tolerance;
    };

    using Bisect3F = Bisect3<float>;
    using Bisect3D = Bisect3<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_H
