///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/01 10:20)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector3Information final
    {
    public:
        using ClassType = Vector3Information<Real>;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using AxesAlignBoundingBox3D = AxesAlignBoundingBox3<Real>;
        using ContainerType = std::vector<Vector3>;

    public:
        // 值epsilon被使用在计算点集的维度时，作为相对误差。
        explicit Vector3Information(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox3D GetAABB() const noexcept;
        NODISCARD Real GetMaxRange() const noexcept;
        NODISCARD Vector3 GetOrigin() const noexcept;
        NODISCARD Vector3 GetDirectionX() const noexcept;
        NODISCARD Vector3 GetDirectionY() const noexcept;
        NODISCARD Vector3 GetDirectionZ() const noexcept;
        NODISCARD Vector3 GetMinExtreme() const;
        NODISCARD Vector3 GetMaxExtreme() const;
        NODISCARD Vector3 GetPerpendicularExtreme() const;
        NODISCARD Vector3 GetTetrahedronExtreme() const;
        NODISCARD bool IsExtremeCCW() const noexcept;

        NODISCARD int GetMinExtremeIndex() const noexcept;
        NODISCARD int GetMaxExtremeIndex() const noexcept;
        NODISCARD int GetPerpendicularExtremeIndex() const noexcept;
        NODISCARD int GetTetrahedronExtremeIndex() const noexcept;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange();
        NODISCARD bool TestPointSetIsNearlyAPoint() noexcept;
        NODISCARD bool TestPointSetIsNearlyALineSegment();
        NODISCARD bool TestPointSetIsNearlyAPlanarPolygon();

    private:
        using IndexContainerType = std::array<int, Vector3::pointSize>;

    private:
        ContainerType points;
        Real epsilon;

        // 输入集的固有维度。
        // 其中，参数“epsilon”被用于确定尺寸时提供容差。
        int dimension;

        // 输入集的轴对齐包围盒。
        // 最大范围是aabb.max.x - aabb.min.x 、 aabb.max.y - aabb.min.y
        // 和aabb.max.z - aabb.min.z的最大值。
        AxesAlignBoundingBox3D aabb;
        Real maxRange;

        // 坐标系。原点是对任何维度d都有效。
        // 单位长度的方向向量只适用于0 <= i < d。
        // 末端的索引是相对于输入的点的数组，并且也只适用于0 <= i < d。
        // 如果d = 0，所有的点实际上是相同的，
        // 但使用一个epsilon的可能会导致末端的索引不为零。
        // 如果d = 1，所有点的位置在一条线段上。
        // 当d = 2时，所有点不共线但在一个平面上。
        // 当d = 3时，所有点是不共面的。
        Vector3 origin;
        Vector3 directionX;
        Vector3 directionY;
        Vector3 directionZ;

        // 定义最大空间范围的索引。
        // 值m_MinExtreme和m_MaxExtreme是用于定义在坐标轴各个方向中
        // 的一个最大范围的索引数。
        // 如果维度是2，则m_PerpendicularExtreme是
        // 垂直于相应的m_MinExtreme和m_MaxExtreme
        // 最大范围生成的点的索引。
        // 此外，如果维度是3，
        // 则m_TetrahedronExtreme是垂直于由
        // 其他末端点所定义的三角形方向上的最大范围的点。
        // 由点V[minExtreme], V[maxExtreme],
        // V[perpendicularExtreme]和V[tetrahedronExtreme]所形成的四面体，
        // 是顺时针或逆时针，条件存储在m_ExtremeCCW。
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;
        int tetrahedronExtreme;
        bool extremeCCW;  // 是否是逆时针

        // 最小点和最大点索引
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using FloatVector3Information = Vector3Information<float>;
    using DoubleVector3Information = Vector3Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
