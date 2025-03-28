/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:24)

#ifndef MATHEMATICS_OBJECTS_3D_TRIANGLE3_H
#define MATHEMATICS_OBJECTS_3D_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Triangle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Triangle3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using ContainerType = std::vector<Vector3Type>;

    public:
        // 三角形表示为三个顶点数组：
        Triangle3(const Vector3Type& vector0, const Vector3Type& vector1, const Vector3Type& vector2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 从点point到三角形的距离。
        NODISCARD Real DistanceTo(const Vector3Type& point) const;

        NODISCARD ContainerType GetVertex() const;
        NODISCARD Vector3Type GetVertex(int index) const;
        NODISCARD ContainerType GetEdgeVectors() const;

        NODISCARD Vector3Type GetNormal() const;

        NODISCARD Triangle3 GetMove(Real t, const Vector3Type& velocity) const;

    private:
        constexpr static auto vertexSize = 3;

        using ArrayType = std::array<Vector3Type, vertexSize>;

    private:
        ArrayType vertex;
    };

    using Triangle3F = Triangle3<float>;
    using Triangle3D = Triangle3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_TRIANGLE3_H
