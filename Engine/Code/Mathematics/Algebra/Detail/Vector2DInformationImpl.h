///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 18:54)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_IMPL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Vector2DInformationImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2DInformationImpl<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = Math<Real>;
        using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        // 值epsilon被使用在计算点集的维度时，作为相对误差。
        explicit Vector2DInformationImpl(const ContainerType& points, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetDimension() const noexcept;
        [[nodiscard]] AxesAlignBoundingBox2D GetAABB() const noexcept;
        [[nodiscard]] Real GetMaxRange() const noexcept; 
        [[nodiscard]] const Vector2D GetOrigin() const noexcept;
        [[nodiscard]] const Vector2D GetDirectionX() const noexcept;
        [[nodiscard]] const Vector2D GetDirectionY() const noexcept;
        [[nodiscard]] const Vector2D GetMinExtreme() const; 
        [[nodiscard]] const Vector2D GetMaxExtreme() const;
        [[nodiscard]] const Vector2D GetPerpendicularExtreme() const;
        [[nodiscard]] bool IsExtremeCCW() const noexcept;
        [[nodiscard]] int GetMinExtremeIndex() const noexcept;
        [[nodiscard]] int GetPerpendicularExtremeIndex() const noexcept;
        [[nodiscard]] int GetMaxExtremeIndex() const noexcept;
        [[nodiscard]] int GetIndexMin(int index) const;

    private:      
        using IndexContainerType = std::array<int, Vector2D::sm_PointSize>;

    private:
        void Init();
        void ComputeAxisAlignedBoundingBox();
        void DetermineMaximumRange() noexcept;
        [[nodiscard]] bool TestPointSetIsNearlyAPoint() noexcept;
        [[nodiscard]] bool TestPointSetIsNearlyALineSegment();

    private:
        ContainerType m_Points;
        Real m_Epsilon;

        // 输入集的固有维度。其中，参数“epsilon”被用于确定尺寸时提供容差。
        int m_Dimension;

        // 输入集的轴对齐包围盒。
        // 最大范围是aabb.max.x - aabb.min.x 和 aabb.max.y - aabb.min.y的最大值。
        AxesAlignBoundingBox2D m_AABB;
        Real m_MaxRange;

        // 坐标系。原点是对任何维度d都有效。
        // 单位长度的方向向量只适用于0 <= i < d。
        // 末端的索引是相对于输入的点的数组，并且也只适用于0 <= i < d。
        // 如果d = 0，所有的点实际上是相同的，
        // 但使用一个epsilon的可能会导致末端的索引不为零。
        // 如果d = 1，所有点的位置在一条线段上。
        // 当d = 2时，所有点不共线。
        Vector2D m_Origin;
        Vector2D m_DirectionX;
        Vector2D m_DirectionY;

        // 定义最大空间范围的索引。
        // 值m_MinExtreme和m_MaxExtreme是用于定义在坐标轴各个方向中的一个最大范围的索引数。
        // 如果维度是2，则m_PerpendicularExtreme是
        // 垂直于相应的m_MinExtreme和m_MaxExtreme
        // 最大范围生成的点的索引。
        // 由点V[m_MinExtreme], V[m_MaxExtreme],
        // 和 V[m_PerpendicularExtreme]所形成的三角形，
        // 是顺时针或逆时针，存储在m_ExtremeCCW。
        int m_MinExtreme;
        int m_MaxExtreme;
        int m_PerpendicularExtreme;
        bool m_ExtremeCCW;  // 是否是逆时针

        // 最小点和最大点索引
        IndexContainerType m_IndexMin;
        IndexContainerType m_IndexMax;
    };
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_IMPL_H
