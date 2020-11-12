///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 17:50)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_IMPL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Vector3DInformationImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3DInformationImpl<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3D<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // 值epsilon被使用在计算点集的维度时，作为相对误差。
        explicit Vector3DInformationImpl(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetDimension() const noexcept;
        [[nodiscard]] AxesAlignBoundingBox3D GetAABB() const noexcept;
        [[nodiscard]] Real GetMaxRange() const noexcept;
        [[nodiscard]] const Vector3D GetOrigin() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionX() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionY() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionZ() const noexcept;
        [[nodiscard]] const Vector3D GetMinExtreme() const;
        [[nodiscard]] const Vector3D GetMaxExtreme() const;
        [[nodiscard]] const Vector3D GetPerpendicularExtreme() const;
        [[nodiscard]] const Vector3D GetTetrahedronExtreme() const;
        [[nodiscard]] bool IsExtremeCCW() const noexcept;

        [[nodiscard]] int GetMinExtremeIndex() const noexcept;
        [[nodiscard]] int GetMaxExtremeIndex() const noexcept;
        [[nodiscard]] int GetPerpendicularExtremeIndex() const noexcept;
        [[nodiscard]] int GetTetrahedronExtremeIndex() const noexcept;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange();
        [[nodiscard]] bool TestPointSetIsNearlyAPoint() noexcept;
        [[nodiscard]] bool TestPointSetIsNearlyALineSegment();
        [[nodiscard]] bool TestPointSetIsNearlyAPlanarPolygon();

    private:
        using IndexContainerType = std::array<int, Vector3D::sm_PointSize>;

    private:
        ContainerType m_Points;
        Real m_Epsilon;

        // 输入集的固有维度。
        // 其中，参数“epsilon”被用于确定尺寸时提供容差。
        int m_Dimension;

        // 输入集的轴对齐包围盒。
        // 最大范围是aabb.max.x - aabb.min.x 、 aabb.max.y - aabb.min.y
        // 和aabb.max.z - aabb.min.z的最大值。
        AxesAlignBoundingBox3D m_AABB;
        Real m_MaxRange;

        // 坐标系。原点是对任何维度d都有效。
        // 单位长度的方向向量只适用于0 <= i < d。
        // 末端的索引是相对于输入的点的数组，并且也只适用于0 <= i < d。
        // 如果d = 0，所有的点实际上是相同的，
        // 但使用一个epsilon的可能会导致末端的索引不为零。
        // 如果d = 1，所有点的位置在一条线段上。
        // 当d = 2时，所有点不共线但在一个平面上。
        // 当d = 3时，所有点是不共面的。
        Vector3D m_Origin;
        Vector3D m_DirectionX;
        Vector3D m_DirectionY;
        Vector3D m_DirectionZ;

        // 定义最大空间范围的索引。
        // 值m_MinExtreme和m_MaxExtreme是用于定义在坐标轴各个方向中
        // 的一个最大范围的索引数。
        // 如果维度是2，则m_PerpendicularExtreme是
        // 垂直于相应的m_MinExtreme和m_MaxExtreme
        // 最大范围生成的点的索引。
        // 此外，如果维度是3，
        // 则m_TetrahedronExtreme是垂直于由
        // 其他末端点所定义的三角形方向上的最大范围的点。
        // 由点V[m_MinExtreme], V[m_MaxExtreme],
        // V[m_PerpendicularExtreme]和V[m_TetrahedronExtreme]所形成的四面体，
        // 是顺时针或逆时针，条件存储在m_ExtremeCCW。
        int m_MinExtreme;
        int m_MaxExtreme;
        int m_PerpendicularExtreme;
        int m_TetrahedronExtreme;
        bool m_ExtremeCCW;  // 是否是逆时针

        // 最小点和最大点索引
        IndexContainerType m_IndexMin;
        IndexContainerType m_IndexMax;
    };

    using FloatVector3DInformation = Vector3DInformation<float>;
    using DoubleVector3DInformation = Vector3DInformation<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_INFORMATION_IMPL_H
