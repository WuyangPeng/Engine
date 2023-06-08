///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:16)

#ifndef MATHEMATICS_OBJECTS_2D_TRIANGLE2_H
#define MATHEMATICS_OBJECTS_2D_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Triangle2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Triangle2<Real>;

        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using ContainerType = std::vector<Vector2>;

    public:
        // 三角形表示为三个顶点数组：
        Triangle2(const Vector2& vector0, const Vector2& vector1, const Vector2& vector2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 从点point到三角形的距离。
        NODISCARD Real DistanceTo(const Vector2& point) const;

        NODISCARD ContainerType GetVertex() const;
        NODISCARD Vector2 GetVertex(int index) const;

    private:
        constexpr static auto vertexSize = 3;

        using ArrayType = std::array<Vector2, vertexSize>;

    private:
        ArrayType vertex;
    };

    using Triangle2F = Triangle2<float>;
    using Triangle2D = Triangle2<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_TRIANGLE2_H
