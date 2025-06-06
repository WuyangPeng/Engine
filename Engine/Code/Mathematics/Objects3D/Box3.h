/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:27)

#ifndef MATHEMATICS_OBJECTS_3D_BOX3_H
#define MATHEMATICS_OBJECTS_3D_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Box3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Box3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using VerticesType = std::vector<Vector3Type>;

    public:
        // 一个盒子有中心点C，轴方向U[0]、U[1]和U[2]（垂直和单位长度的向量），
        // 和范围e[0]、e[1]和e[2]（非负数）。
        // A point X = C + y[0] * U[0] + y[1] * U[1] + y[2] * U[2]是在内部或在盒子上，
        // 每当|y[i]| <= e[i]对于所有的i
        Box3() noexcept;
        Box3(const Vector3Type& center,
             const Vector3Type& axis0,
             const Vector3Type& axis1,
             const Vector3Type& axis2,
             const Real extent0,
             const Real extent1,
             const Real extent2,
             const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 返回的顶点数为8
        NODISCARD VerticesType ComputeVertices() const;
        NODISCARD Vector3Type GetCenter() const noexcept;

        NODISCARD Vector3Type GetAxis0() const noexcept;
        NODISCARD Vector3Type GetAxis1() const noexcept;
        NODISCARD Vector3Type GetAxis2() const noexcept;
        NODISCARD Vector3Type GetAxis(int index) const;

        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;
        NODISCARD Real GetExtent2() const noexcept;
        NODISCARD Real GetExtent(int index) const;

        NODISCARD Real GetEpsilon() const noexcept;

        NODISCARD Box3 GetMove(Real t, const Vector3Type& velocity) const;

        void Set(const Vector3Type& newCenter,
                 const Vector3Type& axis0,
                 const Vector3Type& axis1,
                 const Vector3Type& axis2,
                 Real extent0,
                 Real extent1,
                 Real extent2) noexcept;

    private:
        static constexpr auto axisSize = 3;

        using AxisType = std::array<Vector3Type, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector3Type center;
        AxisType axis;
        ExtentType extent;
        Real epsilon;
    };

    using Box3F = Box3<float>;
    using Box3D = Box3<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Box3<Real>& lhs, const Box3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Box3<Real>& box);
}

#endif  // MATHEMATICS_OBJECTS_3D_BOX3_H
