///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:43)

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
    requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4)
    class BarycentricCoordinates final
    {
    public:
        using ClassType = BarycentricCoordinates<Real, WindowSize>;

        using TupleType = CoreTools::Tuple<WindowSize, Real>;
        using MathType = Math<Real>;

    public:
        BarycentricCoordinates(bool isValid, const TupleType& tuple) noexcept;
        BarycentricCoordinates() noexcept;

        CLASS_INVARIANT_DECLARE;

        // �������
        NODISCARD Real operator[](int index) const;
        NODISCARD bool IsBarycentricCoordinatesValid() const noexcept;

    private:
        bool isValid;
        TupleType tuple;
    };
}

#endif  // MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H
