///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 11:39)

#ifndef MATHEMATICS_OBJECTS2D_BOX2_H
#define MATHEMATICS_OBJECTS2D_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Box2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Box2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Box2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Box2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Box2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Box2Impl = Box2Impl<Real>;
         
        TYPE_DECLARE(Box2);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ClassType = Box2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using VerticesType = std::vector<Vector2D>;

    public:
        // 一个盒子有中心点C，轴方向U[0]和U[1]（垂直和单位长度的向量），
        // 和范围e[0]和e[1]（非负数）。
        // A point X = C + y[0] * U[0] + y[1] * U[1]是在内部或在盒子上，
        // 每当|y[i]| <= e[i]对于所有的i
        Box2();
        Box2(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1, const Real extent0, const Real extent1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const VerticesType ComputeVertices() const;
        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] const Vector2D GetAxis0() const noexcept;
        [[nodiscard]] const Vector2D GetAxis1() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetEpsilon() const noexcept;

        [[nodiscard]] const Box2 GetMove(Real t, const Vector2D& velocity) const;

    private:
        PackageType impl;
    };

    using FloatBox2 = Box2<float>;
    using DoubleBox2 = Box2<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Box2<Real>& box);
}

#endif  // MATHEMATICS_OBJECTS2D_BOX2_H
