// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 17:24)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_H
#define MATHEMATICS_OBJECTS3D_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Torus3Parameters.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Torus3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Torus3Parameters = Torus3Parameters<Real>;

    public:
        // ��z��Ϊ�Գ��ᣬ�����ڣ�0,0,0��Բ����ʵ��
        // ����ΪȦ��ת���Բ������棩��
        //
        // ������ʽ��
        //      Ro > 0 Ϊ�뾶��Բ�����⾶��������
        //      Ri > 0 Ϊ�뾶��Բ�����ھ���������
        //      p^2 = x^2 + y^2 + z^2
        //      p^4 - 2 * (Ro^2 + Ri^2) * p^2 + 4 * Ro^2 * z^2 + (Ro^2 - Ri^2)^2 = 0
        //
        // ������
        //      0 <= s <= 1, 0 <= t <= 1
        //      Rc = Ro + Ri * cos(2 * PI * t)
        //      x = Rc * cos(2 * PI * s)
        //      y = Rc * sin(2 * PI * s)
        //      z = Ri * sin(2 * PI * t)
        Torus3(Real outerRadius, Real innerRadius) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetOuterRadius() const noexcept;
        [[nodiscard]] Real GetInnerRadius() const noexcept;

        [[nodiscard]] const Vector3D GetPosition(Real s, Real t) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const Vector3D GetNormal(Real s, Real t) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // ����ֵ��һ����Ϊs���ڶ�����Ϊt
        [[nodiscard]] const Torus3Parameters GetParameters(const Vector3D& position) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    private:
        Real m_OuterRadius;
        Real m_InnerRadius;
    };

    using FloatTorus3 = Torus3<float>;
    using DoubleTorus3 = Torus3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_TORUS3_H
