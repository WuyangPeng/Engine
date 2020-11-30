///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 14:16)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
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

        [[nodiscard]] const ConstIter GetMinLocationBegin() const noexcept;
        [[nodiscard]] const ConstIter GetMinLocationEnd() const noexcept;
        [[nodiscard]] Real GetMinLocation(int index) const;
        [[nodiscard]] Real GetMinValue() const noexcept;
        [[nodiscard]] int GetDimensions() const;

        void Set(Real minValue, Real minLocation, const Container& direction, int directionCurrent);

        [[nodiscard]] const Container& GetMinLocation() const noexcept;

    private:
        Container m_MinLocation;
        Real m_MinValue;
    };

    using FloatMinimizeNData = MinimizeNData<float>;
    using DoubleMinimizeNData = MinimizeNData<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DATA_H
