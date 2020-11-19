///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 16:47)

#ifndef MATHEMATICS_OBJECTS2D_SEGMENT2_H
#define MATHEMATICS_OBJECTS2D_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
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
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // �߶α���ʾΪ(1-s) * P0 + s * P1������P0��P1���߶εĶ˵��0 <= s <= 1��
        //
        // һЩ�㷨�漰�߶ο��ܸ�ϲ������һ���е�ı�ʾ�������Χ�еķ���
        // �˱�ʾΪC + t * D������C = (P0 + P1) / 2�Ǹ��߶ε����ģ�
        // D = (P1-P0)/Length(P1-P0)��һ����λ���ȷ����ʸ����
        // ��|t| <= e��ֵ e = Length(P1-P0)/2�Ǹ��߶εġ���Χ�����뾶��볤����

        // ���캯������center��direction��extent��beginPoint��endPoint
        Segment2(const Vector2D& beginPoint, const Vector2D& endPoint, const Real epsilon = Math::GetZeroTolerance());

        // ���캯������beginPoint��endPoint��center��direction��extent
        Segment2(Real extent, const Vector2D& center, const Vector2D& direction, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetBeginPoint() const noexcept;
        [[nodiscard]] const Vector2D GetEndPoint() const noexcept;
        [[nodiscard]] const Vector2D GetCenterPoint() const noexcept;
        [[nodiscard]] const Vector2D GetDirection() const noexcept;
        [[nodiscard]] Real GetExtent() const noexcept;

        [[nodiscard]] const Segment2 GetMove(Real t, const Vector2D& velocity) const;

    private:
        // ����ı�beginPoint��endPointʱ����
        void ComputeCenterDirectionExtent();

        // ����ı�center��direction��extentʱ����
        void ComputeEndPoints();

    private:
        // �յ��ʾ��
        Vector2D m_BeginPoint;
        Vector2D m_EndPoint;

        // ���ġ����򡪷�Χ��ʾ��
        Vector2D m_Center;
        Vector2D m_Direction;
        Real m_Extent;

        Real m_Epsilon;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Segment2<Real>& lhs, const Segment2<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment2<Real>& segment);

    using FloatSegment2 = Segment2<float>;
    using DoubleSegment2 = Segment2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_SEGMENT2_H
