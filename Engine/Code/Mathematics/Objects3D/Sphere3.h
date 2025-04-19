/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_SPHERE3_H
#define MATHEMATICS_OBJECTS_3D_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Sphere3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Sphere3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;

    public:
        // 球体被表示为|X-C| = Real，其中C为中心，Real为半径。
        Sphere3(const Vector3Type& center, Real radius) noexcept;
        Sphere3() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

        void SetSphere(const Vector3Type& aCenter, Real aRadius) noexcept;

    private:
        Vector3Type center;
        Real radius;
    };

    using Sphere3F = Sphere3<float>;
    using Sphere3D = Sphere3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_SPHERE3_H
