///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:15)

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
        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;

    public:
        // ���߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t >= 0��
        // �û�����ȷ��D�ǵ�λ���ȡ�

        Ray2(const Vector2& origin, const Vector2& direction, Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetOrigin() const noexcept;
        NODISCARD Vector2 GetDirection() const noexcept;

        NODISCARD Ray2 GetMove(Real t, const Vector2& velocity) const;

    private:
        Vector2 origin;
        Vector2 direction;
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
