/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/26 15:32)

#ifndef MATHEMATICS_OBJECTS_3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS_3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"
#include "Mathematics/Primitives/Rectangle.h"

namespace Mathematics
{
    /// ������һ���ǵȾ�ľ��εĵ㣬��ͬ�ľ����Ϊ�뾶��
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Lozenge3 final
    {
    public:
        using ClassType = Lozenge3<Real>;

        using Math = Math<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using AlgebraRectangle3 = Algebra::Rectangle3<Real>;

    public:
        /// Ĭ�Ϲ��캯������������Ϊԭ��(0,0,0)��
        /// ��(1,0,0)�� (0,1,0)�Լ���Χ��Ϊ1��
        /// Ĭ�ϰ뾶Ϊ1��
        Lozenge3() noexcept;
        Lozenge3(const Rectangle3& rectangle, Real radius) noexcept;
        Lozenge3(const AlgebraRectangle3& rectangle, Real radius);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Rectangle3 GetRectangle() const noexcept;
        NODISCARD AlgebraRectangle3 GetAlgebraRectangle() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

    private:
        Rectangle3 rectangle;
        Real radius;
    };

    /// ��֧�����������ıȽϡ�
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    using Lozenge3F = Lozenge3<float>;
    using Lozenge3D = Lozenge3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_LOZENGE3_H
