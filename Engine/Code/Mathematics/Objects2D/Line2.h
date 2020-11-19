///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 16:14)

#ifndef MATHEMATICS_OBJECTS2D_LINE2_H
#define MATHEMATICS_OBJECTS2D_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // �߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t������ʵ����
        // �û�����ȷ��D�ǵ�λ���ȡ�

        Line2(const Vector2D& origin, const Vector2D& direction, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetOrigin() const noexcept;
        [[nodiscard]] const Vector2D GetDirection() const noexcept;

        [[nodiscard]] const Line2 GetMove(Real t, const Vector2D& velocity) const;

        void SetOrigin(const Vector2D& origin) noexcept;
        void SetDirection(const Vector2D& direction) noexcept;

        // Line��ʾDot(N,X) = c��N��ʾ��λ���ߣ�c��ʾ�ߵĳ���c��X�����ϵ�����㡣
        [[nodiscard]] Real DotProduct() const noexcept;

    private:
        Vector2D m_Origin;
        Vector2D m_Direction;
        Real m_Epsilon;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Line2<Real>& lhs, const Line2<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line2<Real>& line);

    using FloatLine2 = Line2<float>;
    using DoubleLine2 = Line2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_LINE2_H
