/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/22 16:38)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"

namespace Mathematics::Algebra
{
    /// Բ������|X-C|^2 = r^2��ƽ��Dot(N,X-C) = 0�Ľ��㣬
    /// ����C��Բ�ģ�r�ǰ뾶��N�ǵ�λ���ȵ�ƽ�淨�ߡ�
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Circle3
    {
    public:
        using ClassType = Circle3<Real>;

        using Vector3Type = Vector3<Real>;
        using MathType = Math<Real>;

    public:
        /// Ĭ�Ϲ��캯������������Ϊ(0,0,0)����������Ϊ(0,0,1)���뾶����Ϊ1��
        Circle3() noexcept;

        Circle3(const Vector3Type& inCenter, const Vector3Type& inNormal, Real inRadius) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetCenter() const noexcept;
        NODISCARD Vector3Type GetNormal() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

        NODISCARD void SetCenter(const Vector3Type& aCenter) noexcept;
        NODISCARD void SetNormal(const Vector3Type& aNormal) noexcept;
        NODISCARD void SetRadius(Real aRadius) noexcept;

    private:
        Vector3Type center;
        Vector3Type normal;
        Real radius;
    };

    /// ��֧�����������ıȽϡ�
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Circle3<Real>& lhs, const Circle3<Real>& rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_H
