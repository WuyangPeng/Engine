/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:45)

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

        using MathType = Math<Real>;

    public:
        Minimize1Data() noexcept;
        Minimize1Data(Real minLocation, Real minValue) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetMinLocation() const noexcept;
        NODISCARD Real GetMinValue() const noexcept;

        void SetMinLocation(Real aMinLocation) noexcept;
        void SetMinValue(Real aMinValue) noexcept;
        void SetInitValue() noexcept;
        void CompareData(Real aMinLocation, Real aMinValue) noexcept;

    private:
        Real minLocation;
        Real minValue;
    };

    using Minimize1DataF = Minimize1Data<float>;
    using Minimize1DataD = Minimize1Data<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DATA_H
