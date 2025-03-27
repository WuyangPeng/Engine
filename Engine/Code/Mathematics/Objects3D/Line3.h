/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_LINE3_H
#define MATHEMATICS_OBJECTS_3D_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Primitives/Line.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using AlgebraLine3 = Algebra::Line3<Real>;

    public:
        // �߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t������ʵ����
        // �û�����ȷ��D�ǵ�λ���ȡ�
        Line3(const Vector3Type& origin, const Vector3Type& direction, Real epsilon = MathType::GetZeroTolerance()) noexcept;
        explicit Line3(const AlgebraLine3& line, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetOrigin() const noexcept;
        NODISCARD Vector3Type GetDirection() const noexcept;

        NODISCARD Line3 GetMove(Real t, const Vector3Type& velocity) const;

    private:
        Vector3Type origin;
        Vector3Type direction;
        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line3<Real>& line);

    using Line3F = Line3<float>;
    using Line3D = Line3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_LINE3_H
