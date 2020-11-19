///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:56)

#ifndef MATHEMATICS_OBJECTS3D_TRIANGLE3_H
#define MATHEMATICS_OBJECTS3D_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Triangle3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Triangle3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Triangle3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Triangle3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Triangle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Triangle3Impl = Triangle3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(Triangle3);

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // 三角形表示为三个顶点数组：
        Triangle3(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2);

        CLASS_INVARIANT_DECLARE;

        // 从点point到三角形的距离。
        [[nodiscard]] Real DistanceTo(const Vector3D& point) const;

        [[nodiscard]] const ContainerType GetVertex() const;
        [[nodiscard]] const Vector3D GetVertex(int index) const;
        [[nodiscard]] const ContainerType GetEdgeVectors() const;

        [[nodiscard]] const Vector3D GetNormal() const;

    private:
        IMPL_TYPE_DECLARE(Triangle3);
    };

    using FloatTriangle3 = Triangle3<float>;
    using DoubleTriangle3 = Triangle3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_TRIANGLE3_H
