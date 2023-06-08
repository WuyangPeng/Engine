///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:11)

#ifndef MATHEMATICS_OBJECTS_2D_ARC2_H
#define MATHEMATICS_OBJECTS_2D_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
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
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // Բ���Ƕ�����Բ�ϵ�����end0��end1��
        // �Ա�end1ͨ��end0��ʱ�뷽�������á�
        // Ӧ�ó�����ȷ��end0��end1��Բ���ϣ���������ȷ������

        Arc2(const Vector2& center, Real radius, const Vector2& end0, const Vector2& end1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ����point�Ƿ��ڻ��ϡ�Ӧ�ó������ȷ��point��Բ�ϣ�Ҳ����˵��|P-C| = Real��
        // �ò�����������B-C �� A-C���κνǶȣ�����������0 �� pi����֮�䡣
        NODISCARD bool Contains(const Vector2& point) const;

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

    template <typename Real>
    NODISCARD bool Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Arc2<Real>& arc2);
}

#endif  // MATHEMATICS_OBJECTS_2D_ARC2_H
