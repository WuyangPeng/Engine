///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 18:24)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSE3_H
#define MATHEMATICS_OBJECTS3D_ELLIPSE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipse3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse3<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        // ����Բ������Dot(N,X-C) = 0 ��
        // ����X����ƽ���ϵ�����㡣
        // ����U��V��N�γ�������������ϵ������ [U V N]�������ģ�������ʽΪ1����
        // ��ƽ���ڵ���ԲΪX = C + a*cos(t)*U + b*sin(t)*V��
        // ����tΪ[0,2*pi)�ĽǶȺ����� a >= b > 0��
        // �ڴ����۵ķ��ž������Ա���¡�
        // ��Ա'Center'ΪC����Normal����N��'Major'��U��'Minor'��V��
        // 'MajorLength����a�͡�MinorLength'Ϊb��
        Ellipse3(const Vector3D& center, const Vector3D& normal, const Vector3D& major, const Vector3D& minor,
                 Real majorLength, Real minorLength, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Vector3D GetNormal() const noexcept;
        [[nodiscard]] const Vector3D GetMajor() const noexcept;
        [[nodiscard]] const Vector3D GetMinor() const noexcept;
        [[nodiscard]] Real GetMajorLength() const noexcept;
        [[nodiscard]] Real GetMinorLength() const noexcept;

    private:
        Vector3D m_Center;
        Vector3D m_Normal;
        Vector3D m_Major;
        Vector3D m_Minor;
        Real m_MajorLength;
        Real m_MinorLength;

        Real m_Epsilon;
    };

    using FloatEllipse3 = Ellipse3<float>;
    using DoubleEllipse3 = Ellipse3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSE3_H
