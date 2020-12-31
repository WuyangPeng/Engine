///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/30 11:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Minimize1Data final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Minimize1Data<Real>;
        using Math = Math<Real>;

    public:
        Minimize1Data() noexcept;
        Minimize1Data(Real minLocation, Real minValue) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetMinLocation() const noexcept;
        [[nodiscard]] Real GetMinValue() const noexcept;

        void SetMinLocation(Real minLocation) noexcept;
        void SetMinValue(Real minValue) noexcept;
        void SetInitValue() noexcept;
        void CompareData(Real minLocation, Real minValue) noexcept;

    private:
        Real m_MinLocation;
        Real m_MinValue;
    };

    using FloatMinimize1Data = Minimize1Data<float>;
    using DoubleMinimize1Data = Minimize1Data<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H
