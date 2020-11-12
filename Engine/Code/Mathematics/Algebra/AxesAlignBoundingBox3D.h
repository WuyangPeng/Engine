///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 10:38)

// ������Χ��3D�������
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H

#include "Mathematics/MathematicsDll.h"

#include "Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3D final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AxesAlignBoundingBox3D<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;

    public:
        constexpr AxesAlignBoundingBox3D() noexcept
            : m_MinPoint{}, m_MaxPoint{}
        {
        }

        explicit AxesAlignBoundingBox3D(const Vector3D& minPoint, const Vector3D& maxPoint);

        // �����߱���ȷ��xMin <= xMax �� yMin <= yMax��zMin <= zMax��
        AxesAlignBoundingBox3D(Real xMin, Real xMax, Real yMin, Real yMax, Real zMin, Real zMax);

        template <typename RhsType>
        AxesAlignBoundingBox3D(const AxesAlignBoundingBox3D<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetMinPoint() const noexcept;
        [[nodiscard]] const Vector3D GetMaxPoint() const noexcept;

        // ������ӵ����ĵ�ͺ������ĵ����ӱ�Ե���뾶���ĳ��ȡ�
        [[nodiscard]] const Vector3D GetCenter() const;
        [[nodiscard]] Real GetExtentX() const noexcept;
        [[nodiscard]] Real GetExtentY() const noexcept;
        [[nodiscard]] Real GetExtentZ() const noexcept;

    private:
        void Recalculate();

    private:
        Vector3D m_MinPoint;
        Vector3D m_MaxPoint;
    };

    // �ص��Ĳ��������ϸ������ϡ�
    // ������������ع����߸պýӴ������ӱ�����Ϊ�ص���
    template <typename Real>
    [[nodiscard]] bool HasXOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool HasYOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool HasZOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool IsIntersection(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    // ������ص�������������£����㱻���ء�
    // ���û���ص������׳��쳣
    template <typename Real>
    [[nodiscard]] const AxesAlignBoundingBox3D<Real> FindIntersection(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    using FloatAxesAlignBoundingBox3D = AxesAlignBoundingBox3D<float>;
    using DoubleAxesAlignBoundingBox3D = AxesAlignBoundingBox3D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H