// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 17:22)

#ifndef MATHEMATICS_OBJECTS3D_LINE3_H
#define MATHEMATICS_OBJECTS3D_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/Math.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Line3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line3<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        // �߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t������ʵ����
        // �û�����ȷ��D�ǵ�λ���ȡ�
        Line3(const Vector3D& origin, const Vector3D& direction, const Real epsilon = Math::sm_ZeroTolerance) noexcept;

        CLASS_INVARIANT_DECLARE;

        const Vector3D GetOrigin() const noexcept;
        const Vector3D GetDirection() const noexcept;

        const ClassType GetMove(Real t, const Vector3D& velocity) const;

    private:
        Vector3D m_Origin;
        Vector3D m_Direction;
        Real m_Epsilon;
    };

    template <typename Real>
    bool Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line3<Real>& line);

    using Line3f = Line3<float>;
    using Line3d = Line3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_LINE3_H
