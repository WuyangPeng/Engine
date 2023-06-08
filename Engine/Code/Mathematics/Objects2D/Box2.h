///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:11)

#ifndef MATHEMATICS_OBJECTS_2D_BOX2_H
#define MATHEMATICS_OBJECTS_2D_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Vector2.h"

#include <iosfwd>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Box2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Box2<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using VerticesType = std::vector<Vector2>;

    public:
        // һ�����������ĵ�C���᷽��U[0]��U[1]����ֱ�͵�λ���ȵ���������
        // �ͷ�Χe[0]��e[1]���Ǹ�������
        // A point X = C + y[0] * U[0] + y[1] * U[1]�����ڲ����ں����ϣ�
        // ÿ��|y[i]| <= e[i]�������е�i
        Box2() noexcept;
        Box2(const Vector2& center, const Vector2& axis0, const Vector2& axis1, const Real extent0, const Real extent1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VerticesType ComputeVertices() const;
        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Vector2 GetAxis0() const noexcept;
        NODISCARD Vector2 GetAxis1() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;
        NODISCARD Real GetEpsilon() const noexcept;

        NODISCARD Box2 GetMove(Real t, const Vector2& velocity) const;

    private:
        static constexpr auto axisSize = 2;

        using AxisType = std::array<Vector2, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector2 center;
        AxisType axis;
        ExtentType extent;
        Real epsilon;
    };

    using Box2F = Box2<float>;
    using Box2D = Box2<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Box2<Real>& box);
}

#endif  // MATHEMATICS_OBJECTS_2D_BOX2_H
