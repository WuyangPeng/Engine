///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/02 22:12)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AxesAlignBoundingBox2<Real>;
        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;
        using PointIndex = typename Vector2::PointIndex;

    public:
        constexpr AxesAlignBoundingBox2() noexcept
            : minPoint{ Math::maxReal, Math::maxReal }, maxPoint{ Math::minReal, Math::minReal }
        {
        }

        AxesAlignBoundingBox2(const Vector2& minPoint, const Vector2& maxPoint) noexcept;

        template <typename RhsType>
        AxesAlignBoundingBox2(const AxesAlignBoundingBox2<RhsType>& aabb);

        // �����߱���ȷ��xMin <= xMax �� yMin <= yMax��
        AxesAlignBoundingBox2(Real xMin, Real xMax, Real yMin, Real yMax) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector2 GetMinPoint() const noexcept;
        NODISCARD Vector2 GetMaxPoint() const noexcept;

        NODISCARD Real GetMinPoint(int index) const;
        NODISCARD Real GetMaxPoint(int index) const;
        NODISCARD Real GetMinPoint(PointIndex index) const;
        NODISCARD Real GetMaxPoint(PointIndex index) const;

        // ������ӵ����ĵ�ͺ������ĵ����ӱ�Ե���뾶���ĳ��ȡ�
        NODISCARD Vector2 GetCenter() const;
        NODISCARD Real GetExtentX() const noexcept;
        NODISCARD Real GetExtentY() const noexcept;

    private:
        Vector2 minPoint;
        Vector2 maxPoint;
    };

    // �ص��Ĳ��������ϸ������ϡ�
    // ������������ع����߸պýӴ������ӱ�����Ϊ�ص���
    template <typename Real>
    NODISCARD bool HasXOverlap(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    template <typename Real>
    NODISCARD bool HasYOverlap(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    template <typename Real>
    NODISCARD bool IsIntersection(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    // ������ص�������������£����㱻���ء�
    // ���û���ص����򷵻ص�AxesAlignBoundingBox2����Ч�ġ�
    template <typename Real>
    NODISCARD AxesAlignBoundingBox2<Real> FindIntersection(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    using AxesAlignBoundingBox2F = AxesAlignBoundingBox2<float>;
    using AxesAlignBoundingBox2D = AxesAlignBoundingBox2<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H