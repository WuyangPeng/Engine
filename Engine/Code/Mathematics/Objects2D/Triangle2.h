///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 11:14)

#ifndef MATHEMATICS_OBJECTS2D_TRIANGLE2_H
#define MATHEMATICS_OBJECTS2D_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Triangle2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Triangle2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Triangle2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Triangle2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Triangle2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Triangle2Impl = Triangle2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(Triangle2);

        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        // 三角形表示为三个顶点数组：
        Triangle2(const Vector2D& vector0, const Vector2D& vector1, const Vector2D& vector2);

        CLASS_INVARIANT_DECLARE;

        // 从点point到三角形的距离。
        [[nodiscard]] Real DistanceTo(const Vector2D& point) const;

        [[nodiscard]] const ContainerType GetVertex() const;
        [[nodiscard]] const Vector2D GetVertex(int index) const;

    private:
        IMPL_TYPE_DECLARE(Triangle2);
    };

    using FloatTriangle2 = Triangle2<float>;
    using DoubleTriangle2 = Triangle2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_TRIANGLE2_H
