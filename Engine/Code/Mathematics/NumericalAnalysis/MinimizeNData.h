/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MinimizeNData final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = MinimizeNData<Real>;

        using Math = Math<Real>;
        using Container = std::vector<Real>;
        using ConstIter = typename Container::const_iterator;

    public:
        MinimizeNData() noexcept;
        MinimizeNData(const Container& minLocation, Real minValue);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstIter GetMinLocationBegin() const noexcept;
        NODISCARD ConstIter GetMinLocationEnd() const noexcept;
        NODISCARD Real GetMinLocation(int index) const;
        NODISCARD Real GetMinValue() const noexcept;
        NODISCARD int GetDimensions() const;

        void Set(Real newMinValue, Real newMinLocation, const Container& direction, int directionCurrent);

        NODISCARD const Container& GetMinLocation() const noexcept;

    private:
        Container minLocation;
        Real minValue;
    };

    using MinimizeNDataF = MinimizeNData<float>;
    using MinimizeNDataD = MinimizeNData<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H
