///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 11:06)

#ifndef MATHEMATICS_OBJECTS2D_TRIANGLE2_IMPL_H
#define MATHEMATICS_OBJECTS2D_TRIANGLE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Triangle2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Triangle2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        // 三角形表示为三个顶点数组：
        Triangle2Impl(const Vector2D& vector0, const Vector2D& vector1, const Vector2D& vector2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 从点point到三角形的距离。
        [[nodiscard]] Real DistanceTo(const Vector2D& point) const;

        [[nodiscard]] const ContainerType GetVertex() const;
        [[nodiscard]] const Vector2D GetVertex(int index) const;

    private:
        constexpr static auto sm_VertexSize = 3;

        using ArrayType = std::array<Vector2D, sm_VertexSize>;

    private:
        ArrayType m_Vertex;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_TRIANGLE2_IMPL_H
