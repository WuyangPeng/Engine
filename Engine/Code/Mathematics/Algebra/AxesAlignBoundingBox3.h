///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:42)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Vector3.h"

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3 final
    {
    public:
        using ClassType = AxesAlignBoundingBox3<Real>;

        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;
        using PointIndex = typename Vector3::PointIndex;

    public:
        constexpr AxesAlignBoundingBox3() noexcept
            : minPoint{ Math::maxReal, Math::maxReal, Math::maxReal }, maxPoint{ Math::minReal, Math::minReal, Math::minReal }
        {
        }

        AxesAlignBoundingBox3(const Vector3& minPoint, const Vector3& maxPoint) noexcept;

        // �����߱���ȷ��xMin <= xMax �� yMin <= yMax��zMin <= zMax��
        AxesAlignBoundingBox3(Real xMin, Real xMax, Real yMin, Real yMax, Real zMin, Real zMax) noexcept;

        template <typename RhsType>
        explicit AxesAlignBoundingBox3(const AxesAlignBoundingBox3<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector3 GetMinPoint() const noexcept;
        NODISCARD Vector3 GetMaxPoint() const noexcept;
        NODISCARD Real GetMinPoint(int index) const;
        NODISCARD Real GetMaxPoint(int index) const;
        NODISCARD Real GetMinPoint(PointIndex index) const;
        NODISCARD Real GetMaxPoint(PointIndex index) const;

        // ������ӵ����ĵ�ͺ������ĵ����ӱ�Ե���뾶���ĳ��ȡ�
        NODISCARD Vector3 GetCenter() const;
        NODISCARD Real GetExtentX() const noexcept;
        NODISCARD Real GetExtentY() const noexcept;
        NODISCARD Real GetExtentZ() const noexcept;

    private:
        Vector3 minPoint;
        Vector3 maxPoint;
    };

    // �ص��Ĳ��������ϸ������ϡ�
    // ������������ع����߸պýӴ������ӱ�����Ϊ�ص���
    template <typename Real>
    NODISCARD bool HasXOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    template <typename Real>
    NODISCARD bool HasYOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    template <typename Real>
    NODISCARD bool HasZOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    template <typename Real>
    NODISCARD bool IsIntersection(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    // ������ص�������������£����㱻���ء�
    // ���û���ص����򷵻ص�AxesAlignBoundingBox2����Ч�ġ�
    template <typename Real>
    NODISCARD AxesAlignBoundingBox3<Real> FindIntersection(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    using AxesAlignBoundingBox3F = AxesAlignBoundingBox3<float>;
    using AxesAlignBoundingBox3D = AxesAlignBoundingBox3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_H