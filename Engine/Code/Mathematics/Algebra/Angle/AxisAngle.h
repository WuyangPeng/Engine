/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/02 12:37)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// N=3��N=4����Ƕȱ�ʾ��
/// ��N=4ʱ�����������ʽΪ(x,y,z,0)[��Ԫ�鷽��ķ����ʾ]��������
namespace Mathematics::Algebra
{
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class AxisAngle
    {
    public:
        using ClassType = AxisAngle<N, Real>;

        using Vector = Vector<N, Real>;

    public:
        AxisAngle() noexcept;
        AxisAngle(const Vector& axis, Real angle) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetAxis() const noexcept;
        NODISCARD Real GetAngle() const noexcept;

        void SetAxis(const Vector& aAxis) noexcept;
        void SetAngle(Real aAngle) noexcept;

    private:
        Vector axis;
        Real angle;
    };

}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_H
