///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 14:09)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Polygon2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polygon2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polygon2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polygon2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Polygon2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Polygon2Impl = Polygon2Impl<Real>;
        COPY_UNSHARE_CLASSES_BASE_TYPE_DECLARE(Polygon2, DESTRUCTOR_DEFAULT);

        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using VerticesType = std::vector<Vector2D>;

    public:
        // 调用方负责确保顶点数组逆时针，代表一个简单的多边形。
        explicit Polygon2(const VerticesType& vertices);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 只读成员访问。
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType& GetVertices() const noexcept;
        [[nodiscard]] const Vector2D& GetVertex(int index) const;

        // 允许顶点修改。调用者必须确保多边形仍然是简单多边形。
        virtual void SetVertex(int index, const Vector2D& vertex);

        // 计算关于所述多边形的各种信息。
        [[nodiscard]] const Vector2D ComputeVertexAverage() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real ComputePerimeterLength() const;
        [[nodiscard]] Real ComputeArea() const;

    private:
        IMPL_TYPE_DECLARE(Polygon2);
    };

    using FloatPolygon2 = Polygon2<float>;
    using DoublePolygon2 = Polygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_H
