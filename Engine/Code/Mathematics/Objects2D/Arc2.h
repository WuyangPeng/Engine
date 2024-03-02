/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/20 19:13)

#ifndef MATHEMATICS_OBJECTS_2D_ARC2_H
#define MATHEMATICS_OBJECTS_2D_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/Math.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    /// ����Բ����Բ��ʾΪ|X-C| = r������C�����ģ�r�ǰ뾶��
    /// Բ���Ƕ�����Բ�ϵ�����end0��end1��
    /// �Ա�end1ͨ��end0��ʱ�뷽�������á�
    /// Ӧ�ó�����ȷ��end0��end1��Բ���ϣ���������ȷ������
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Arc2 final
    {
    public:
        using ClassType = Arc2<Real>;

        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using AlgebraVector2 = Algebra::Vector2<Real>;

    public:
        /// Ĭ�Ϲ��캯������������Ϊ(0,0)�����뾶����Ϊ1�����˵�0����Ϊ(1,0)�����˵�1����Ϊ (0,1)��
        Arc2() noexcept;

        Arc2(const Vector2& center, Real radius, const Vector2& end0, const Vector2& end1, Real epsilon = Math::GetZeroTolerance()) noexcept;
        Arc2(const AlgebraVector2& center, Real radius, const AlgebraVector2& end0, const AlgebraVector2& end1, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        /// ����point�Ƿ��ڻ��ϡ�
        ///
        /// ����ʵ�����㣬|P-C| - r = 0��P�ڻ���Բ�ϵı�Ҫ������
        /// ���P��Բ�ϣ���P�ڰ���E0���ߵı���ʱ��P�ڴ�E0��E1�Ļ��ϣ�����Perp(u,v) = (v,-u)��
        /// �ò���������E0-C��E1-C֮����κνǶȣ���ʹ�ýǶȴ��ڻ����pi���ȡ�
        ///
        /// ���ڸ�����������ͣ��������ᵼ�µ�P��Բ�ϣ����������Ͽ�����ʱ|P-C| - r����Ϊ0��
        /// ���ǵ���һ�㣬ѡ��һ��С�ķǸ�����epsilon��
        /// ���P��Բ�ϣ���epsilon���������ϣ�����||P-C| - r| <= epsilon��
        /// ����P����Բ�ϡ�
        /// ��Ӧ��ǰһ��/������߲���ԡ�
        NODISCARD bool Contains(const Vector2& point) const;
        NODISCARD bool Contains(const AlgebraVector2& point) const;

        /// �˺����ٶ�Pλ�ڰ���Բ����Բ�ϣ����ܴ�������������������
        NODISCARD bool CircleContains(const Vector2& point) const;
        NODISCARD bool CircleContains(const AlgebraVector2& point) const;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Vector2 GetEnd0() const noexcept;
        NODISCARD Vector2 GetEnd1() const noexcept;

    private:
        Vector2 center;
        Real radius;
        Vector2 end0;
        Vector2 end1;
        Real epsilon;
    };

    using Arc2F = Arc2<float>;
    using Arc2D = Arc2<double>;

    // STL
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // �������
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    std::ostream& operator<<(std::ostream& out, const Arc2<Real>& arc2);
}

#endif  // MATHEMATICS_OBJECTS_2D_ARC2_H
