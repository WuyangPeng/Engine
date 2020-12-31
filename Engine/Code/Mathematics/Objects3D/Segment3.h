///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 14:47)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Segment3<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        // �߶α���ʾΪ(1-s) * P0 + s * P1������P0��P1���߶εĶ˵��0 <= s <= 1��
        //
        // һЩ�㷨�漰�߶ο��ܸ�ϲ������һ���е�ı�ʾ�������Χ�еķ���
        // �˱�ʾΪC + t * D������C = (P0 + P1) / 2�Ǹ��߶ε����ģ�
        // D = (P1-P0)/Length(P1-P0)��һ����λ���ȷ����ʸ����
        // ��|t| <= e��ֵ e = Length(P1-P0)/2�Ǹ��߶εġ���Χ�����뾶��볤����

        // ���캯������center��direction��extent��beginPoint��endPoint
        Segment3(const Vector3D& beginPoint, const Vector3D& endPoint, const Real epsilon = Math::GetZeroTolerance());

        // ���캯������beginPoint��endPoint��center��direction��extent
        Segment3(Real extent, const Vector3D& center, const Vector3D& direction, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetBeginPoint() const noexcept;
        [[nodiscard]] const Vector3D GetEndPoint() const noexcept;
        [[nodiscard]] const Vector3D GetCenterPoint() const noexcept;
        [[nodiscard]] const Vector3D GetDirection() const noexcept;
        [[nodiscard]] Real GetExtent() const noexcept;

        const Segment3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        // ����ı�beginPoint��endPointʱ����
        void ComputeCenterDirectionExtent();

        // ����ı�center��direction��extentʱ����
        void ComputeEndPoints();

    private:
        // �յ��ʾ��
        Vector3D m_BeginPoint;
        Vector3D m_EndPoint;

        // ���ġ����򡪷�Χ��ʾ��
        Vector3D m_Center;
        Vector3D m_Direction;
        Real m_Extent;

        Real m_Epsilon;
    };

    using FloatSegment3 = Segment3<float>;
    using DoubleSegment3 = Segment3<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment3<Real>& segment);
}

#endif  // MATHEMATICS_OBJECTS3D_SEGMENT3_H
