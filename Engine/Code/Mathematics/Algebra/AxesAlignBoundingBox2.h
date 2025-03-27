///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:42)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Vector2.h"

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2 final
    {
    public:
        using ClassType = AxesAlignBoundingBox2<Real>;

        using Vector2Type = Vector2<Real>;
        using MathType = Math<Real>;
        using PointIndex = typename Vector2Type::PointIndex;

    public:
        constexpr AxesAlignBoundingBox2() noexcept
            : minPoint{ MathType::maxReal, MathType::maxReal }, maxPoint{ MathType::minReal, MathType::minReal }
        {
        }

        AxesAlignBoundingBox2(const Vector2Type& minPoint, const Vector2Type& maxPoint) noexcept;

        template <typename RhsType>
        explicit AxesAlignBoundingBox2(const AxesAlignBoundingBox2<RhsType>& aabb);

        // �����߱���ȷ��xMin <= xMax �� yMin <= yMax��
        AxesAlignBoundingBox2(Real xMin, Real xMax, Real yMin, Real yMax) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector2Type GetMinPoint() const noexcept;
        NODISCARD Vector2Type GetMaxPoint() const noexcept;

        NODISCARD Real GetMinPoint(int index) const;
        NODISCARD Real GetMaxPoint(int index) const;
        NODISCARD Real GetMinPoint(PointIndex index) const;
        NODISCARD Real GetMaxPoint(PointIndex index) const;

        // ������ӵ����ĵ�ͺ������ĵ����ӱ�Ե���뾶���ĳ��ȡ�
        NODISCARD Vector2Type GetCenter() const;
        NODISCARD Real GetExtentX() const noexcept;
        NODISCARD Real GetExtentY() const noexcept;

    private:
        Vector2Type minPoint;
        Vector2Type maxPoint;
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