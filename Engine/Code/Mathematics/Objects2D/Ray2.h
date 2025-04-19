/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_RAY2_H
#define MATHEMATICS_OBJECTS_2D_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ray2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ray2<Real>;

        using Vector2Type = Vector2<Real>;
        using MathType = Math<Real>;

    public:
        // ���߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t >= 0��
        // �û�����ȷ��D�ǵ�λ���ȡ�

        Ray2(const Vector2Type& origin, const Vector2Type& direction, Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2Type GetOrigin() const noexcept;
        NODISCARD Vector2Type GetDirection() const noexcept;

        NODISCARD Ray2 GetMove(Real t, const Vector2Type& velocity) const;

    private:
        Vector2Type origin;
        Vector2Type direction;
        Real epsilon;
    };

    using Ray2F = Ray2<float>;
    using Ray2D = Ray2<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Ray2<Real>& lhs, const Ray2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ray2<Real>& ray);
}

#endif  // MATHEMATICS_OBJECTS_2D_RAY2_H
