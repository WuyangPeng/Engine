///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 11:31)

#ifndef MATHEMATICS_OBJECTS2D_SEGMENT2_H
#define MATHEMATICS_OBJECTS2D_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Segment2<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // �߶α���ʾΪ(1-s) * P0 + s * P1������P0��P1���߶εĶ˵��0 <= s <= 1��
        //
        // һЩ�㷨�漰�߶ο��ܸ�ϲ������һ���е�ı�ʾ�������Χ�еķ���
        // �˱�ʾΪC + t * D������C = (P0 + P1) / 2�Ǹ��߶ε����ģ�
        // D = (P1-P0)/Length(P1-P0)��һ����λ���ȷ����ʸ����
        // ��|t| <= e��ֵ e = Length(P1-P0)/2�Ǹ��߶εġ���Χ�����뾶��볤����

        // ���캯������center��direction��extent��beginPoint��endPoint
        Segment2(const Vector2& beginPoint, const Vector2& endPoint, const Real epsilon = Math::GetZeroTolerance());

        // ���캯������beginPoint��endPoint��center��direction��extent
        Segment2(Real extent, const Vector2& center, const Vector2& direction, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetBeginPoint() const noexcept;
        NODISCARD Vector2 GetEndPoint() const noexcept;
        NODISCARD Vector2 GetCenterPoint() const noexcept;
        NODISCARD Vector2 GetDirection() const noexcept;
        NODISCARD Real GetExtent() const noexcept;

        NODISCARD Segment2 GetMove(Real t, const Vector2& velocity) const;

    private:
        // ����ı�beginPoint��endPointʱ����
        void ComputeCenterDirectionExtent();

        // ����ı�center��direction��extentʱ����
        void ComputeEndPoints();

    private:
        // �յ��ʾ��
        Vector2 beginPoint;
        Vector2 endPoint;

        // ���ġ����򡪷�Χ��ʾ��
        Vector2 center;
        Vector2 direction;
        Real extent;

        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Segment2<Real>& lhs, const Segment2<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment2<Real>& segment);

    using Segment2F = Segment2<float>;
    using Segment2D = Segment2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_SEGMENT2_H
