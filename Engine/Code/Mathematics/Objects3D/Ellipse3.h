///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:44)

#ifndef MATHEMATICS_OBJECTS_3D_ELLIPSE3_H
#define MATHEMATICS_OBJECTS_3D_ELLIPSE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
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
        using Vector3 = Vector3<Real>;

    public:
        // ����Բ������Dot(N,X-C) = 0 ��
        // ����X����ƽ���ϵ�����㡣
        // ����U��V��N�γ�������������ϵ������ [U V N]�������ģ�������ʽΪ1����
        // ��ƽ���ڵ���ԲΪX = C + a*cos(t)*U + b*sin(t)*V��
        // ����tΪ[0,2*pi)�ĽǶȺ����� a >= b > 0��
        // �ڴ����۵ķ��ž������Ա���¡�
        // ��Ա'Center'ΪC����Normal����N��'Major'��U��'Minor'��V��
        // 'MajorLength����a�͡�MinorLength'Ϊb��
        Ellipse3(const Vector3& center,
                 const Vector3& normal,
                 const Vector3& major,
                 const Vector3& minor,
                 Real majorLength,
                 Real minorLength,
                 const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Vector3 GetNormal() const noexcept;
        NODISCARD Vector3 GetMajor() const noexcept;
        NODISCARD Vector3 GetMinor() const noexcept;
        NODISCARD Real GetMajorLength() const noexcept;
        NODISCARD Real GetMinorLength() const noexcept;

    private:
        Vector3 center;
        Vector3 normal;
        Vector3 major;
        Vector3 m_Minor;
        Real majorLength;
        Real minorLength;

        Real epsilon;
    };

    using Ellipse3F = Ellipse3<float>;
    using Ellipse3D = Ellipse3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_ELLIPSE3_H
