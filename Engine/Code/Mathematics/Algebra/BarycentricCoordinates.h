///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/31 3:39)

#ifndef MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H
#define MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, int WindowSize>
    class BarycentricCoordinates final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");
        static_assert((WindowSize == 3 || WindowSize == 4), "WindowSize must be 3 or 4.");

        using ClassType = BarycentricCoordinates<Real, WindowSize>;
        using Tuple = CoreTools::Tuple<WindowSize, Real>;
        using Math = Math<Real>;

    public:
        BarycentricCoordinates(bool isValid, const Tuple& tuple) noexcept;
        BarycentricCoordinates() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        NODISCARD Real operator[](int index) const;
        NODISCARD bool IsBarycentricCoordinatesValid() const noexcept;

    private:
        bool isValid;
        Tuple tuple;
    };
}

#endif  // MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H
