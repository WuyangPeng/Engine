///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 11:15)

#ifndef MATHEMATICS_OBJECTS2D_ARC2_H
#define MATHEMATICS_OBJECTS2D_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Arc2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Arc2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // Բ���Ƕ�����Բ�ϵ�����end0��end1��
        // �Ա�end1ͨ��end0��ʱ�뷽�������á�
        // Ӧ�ó�����ȷ��end0��end1��Բ���ϣ���������ȷ������

        Arc2(const Vector2D& center, Real radius, const Vector2D& end0, const Vector2D& end1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ����point�Ƿ��ڻ��ϡ�Ӧ�ó������ȷ��point��Բ�ϣ�Ҳ����˵��|P-C| = Real��
        // �ò�����������B-C �� A-C���κνǶȣ�����������0 �� pi����֮�䡣
        [[nodiscard]] bool Contains(const Vector2D& point) const;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;
        [[nodiscard]] const Vector2D GetEnd0() const noexcept;
        [[nodiscard]] const Vector2D GetEnd1() const noexcept;

    private:
        Vector2D m_Center;
        Real m_Radius;
        Vector2D m_End0;
        Vector2D m_End1;
        Real m_Epsilon;
    };

    using FloatArc2 = Arc2<float>;
    using DoubleArc2 = Arc2<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Arc2<Real>& arc2);
}

#endif  // MATHEMATICS_OBJECTS2D_ARC2_H
