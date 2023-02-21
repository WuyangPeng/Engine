///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 11:00)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Polygon2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polygon2;

        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using VerticesType = std::vector<Vector2>;

    public:
        // 调用方负责确保顶点数组逆时针，代表一个简单的多边形。
        explicit Polygon2(const VerticesType& vertices);

        virtual ~Polygon2() noexcept = default;
        Polygon2(const Polygon2& rhs) = default;
        Polygon2& operator=(const Polygon2& rhs) = default;
        Polygon2(Polygon2&& rhs) noexcept = default;
        Polygon2& operator=(Polygon2&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 只读成员访问。
        NODISCARD int GetNumVertices() const;
        NODISCARD const VerticesType& GetVertices() const noexcept;
        NODISCARD const Vector2& GetVertex(int index) const;

        // 允许顶点修改。调用者必须确保多边形仍然是简单多边形。
        virtual void SetVertex(int index, const Vector2& vertex);

        // 计算关于所述多边形的各种信息。
        NODISCARD Vector2 ComputeVertexAverage() const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Real ComputePerimeterLength() const;
        NODISCARD Real ComputeArea() const;

    private:
        static constexpr auto minSize = 4;

    private:
        VerticesType vertices;
    };

    using Polygon2F = Polygon2<float>;
    using Polygon2D = Polygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_H
