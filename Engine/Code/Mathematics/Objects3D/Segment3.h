/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_SEGMENT3_H
#define MATHEMATICS_OBJECTS_3D_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Segment3<Real>;

        using MathType = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;

    public:
        // �߶α���ʾΪ(1-s) * P0 + s * P1������P0��P1���߶εĶ˵��0 <= s <= 1��
        //
        // һЩ�㷨�漰�߶ο��ܸ�ϲ������һ���е�ı�ʾ�������Χ�еķ���
        // �˱�ʾΪC + t * D������C = (P0 + P1) / 2�Ǹ��߶ε����ģ�
        // D = (P1-P0)/Length(P1-P0)��һ����λ���ȷ����ʸ����
        // ��|t| <= e��ֵ e = Length(P1-P0)/2�Ǹ��߶εġ���Χ�����뾶��볤����

        // ���캯������center��direction��extent��beginPoint��endPoint
        Segment3(const Vector3& beginPoint, const Vector3& endPoint, Real epsilon = MathType::GetZeroTolerance());

        // ���캯������beginPoint��endPoint��center��direction��extent
        Segment3(Real extent, const Vector3& center, const Vector3& direction, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetBeginPoint() const noexcept;
        NODISCARD Vector3 GetEndPoint() const noexcept;
        NODISCARD Vector3 GetCenterPoint() const noexcept;
        NODISCARD Vector3 GetDirection() const noexcept;
        NODISCARD Real GetExtent() const noexcept;

        NODISCARD Segment3 GetMove(Real t, const Vector3& velocity) const;

    private:
        // ����ı�beginPoint��endPointʱ����
        void ComputeCenterDirectionExtent();

        // ����ı�center��direction��extentʱ����
        void ComputeEndPoints();

    private:
        // �յ��ʾ��
        Vector3 beginPoint;
        Vector3 endPoint;

        // ���ġ����򡪷�Χ��ʾ��
        Vector3 center;
        Vector3 direction;
        Real extent;

        Real epsilon;
    };

    using Segment3F = Segment3<float>;
    using Segment3D = Segment3<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Segment3<Real>& segment);
}

#endif  // MATHEMATICS_OBJECTS_3D_SEGMENT3_H
