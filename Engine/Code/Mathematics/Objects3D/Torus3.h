/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_TORUS3_H
#define MATHEMATICS_OBJECTS_3D_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Torus3Parameters.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Torus3<Real>;

        using Vector3 = Vector3<Real>;
        using MathType = Math<Real>;
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

        NODISCARD Real GetOuterRadius() const noexcept;
        NODISCARD Real GetInnerRadius() const noexcept;

        NODISCARD Vector3 GetPosition(Real s, Real t) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Vector3 GetNormal(Real s, Real t) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // ����ֵ��һ����Ϊs���ڶ�����Ϊt
        NODISCARD Torus3Parameters GetParameters(const Vector3& position) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        Real outerRadius;
        Real innerRadius;
    };

    using Torus3F = Torus3<float>;
    using Torus3D = Torus3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_TORUS3_H
