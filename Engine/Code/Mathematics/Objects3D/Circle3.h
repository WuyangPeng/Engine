///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 15:50)

#ifndef MATHEMATICS_OBJECTS3D_CIRCLE3_H
#define MATHEMATICS_OBJECTS3D_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Circle3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        // ���и�Բ��ƽ����Dot(N,X-C) = 0������X����ƽ���ϵ�����㡣
        // ����U��V��N�γ�������������ϵ���ϡ�
        // ������[U V N]�������ģ���������ʽ1����
        // ��ƽ���ڵ�Բ�ܲ���ΪX = C + Real * (cos(t) * U + sin(t) * V)��
        // ����t����[-pi,pi)�ĽǶȡ�

        // U ���������� 'direction0', V ���������� 'direction1,
        // �� N ���������� 'normal'.
        Circle3(const Vector3D& center, const Vector3D& direction0, const Vector3D& direction1,
                const Vector3D& normal, const Real radius, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Vector3D GetDirection0() const noexcept;
        [[nodiscard]] const Vector3D GetDirection1() const noexcept;
        [[nodiscard]] const Vector3D GetNormal() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;

        [[nodiscard]] const Circle3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        Vector3D m_Center;
        Vector3D m_Direction0;
        Vector3D m_Direction1;
        Vector3D m_Normal;
        Real m_Radius;
        Real m_Epsilon;
    };

    using FloatCircle3 = Circle3<float>;
    using DoubleCircle3 = Circle3<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Circle3<Real>& lhs, const Circle3<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Circle3<Real>& circle);
}

#endif  // MATHEMATICS_OBJECTS3D_CIRCLE3_H
