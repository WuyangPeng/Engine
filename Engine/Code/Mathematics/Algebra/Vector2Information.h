///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 18:43)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Vector2Information final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2Information<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using AxesAlignBoundingBox2D = AxesAlignBoundingBox2<Real>;
        using ContainerType = std::vector<Vector2>;

    public:
        // 值epsilon被使用在计算点集的维度时，作为相对误差。
        explicit Vector2Information(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox2D GetAABB() const noexcept;
        NODISCARD Real GetMaxRange() const noexcept;
        NODISCARD Vector2 GetOrigin() const noexcept;
        NODISCARD Vector2 GetDirectionX() const noexcept;
        NODISCARD Vector2 GetDirectionY() const noexcept;
        NODISCARD Vector2 GetMinExtreme() const;
        NODISCARD Vector2 GetMaxExtreme() const;
        NODISCARD Vector2 GetPerpendicularExtreme() const;
        NODISCARD bool IsExtremeCCW() const noexcept;
        NODISCARD int GetMinExtremeIndex() const noexcept;
        NODISCARD int GetPerpendicularExtremeIndex() const noexcept;
        NODISCARD int GetMaxExtremeIndex() const noexcept;
        NODISCARD int GetIndexMin(int index) const;

    private:
        using IndexContainerType = std::array<int, Vector2::pointSize>;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange() noexcept;
        NODISCARD bool TestPointSetIsNearlyAPoint() noexcept;
        NODISCARD bool TestPointSetIsNearlyALineSegment();

    private:
        ContainerType points;
        Real epsilon;

        // 输入集的固有维度。其中，参数“epsilon”被用于确定尺寸时提供容差。
        int dimension;

        // 输入集的轴对齐包围盒。
        // 最大范围是aabb.max.x - aabb.min.x 和 aabb.max.y - aabb.min.y的最大值。
        AxesAlignBoundingBox2D aabb;
        Real maxRange;

        // 坐标系。原点是对任何维度d都有效。
        // 单位长度的方向向量只适用于0 <= i < d。
        // 末端的索引是相对于输入的点的数组，并且也只适用于0 <= i < d。
        // 如果d = 0，所有的点实际上是相同的，
        // 但使用一个epsilon的可能会导致末端的索引不为零。
        // 如果d = 1，所有点的位置在一条线段上。
        // 当d = 2时，所有点不共线。
        Vector2 origin;
        Vector2 directionX;
        Vector2 directionY;

        // 定义最大空间范围的索引。
        // 值m_MinExtreme和m_MaxExtreme是用于定义在坐标轴各个方向中的一个最大范围的索引数。
        // 如果维度是2，则m_PerpendicularExtreme是
        // 垂直于相应的m_MinExtreme和m_MaxExtreme
        // 最大范围生成的点的索引。
        // 由点V[m_MinExtreme], V[m_MaxExtreme],
        // 和 V[m_PerpendicularExtreme]所形成的三角形，
        // 是顺时针或逆时针，存储在m_ExtremeCCW。
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;
        bool extremeCCW;  // 是否是逆时针

        // 最小点和最大点索引
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using Vector2InformationF = Vector2Information<float>;
    using Vector2InformationD = Vector2Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_INFORMATION_H
