/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/30 10:10)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    /// 获取有关矢量输入数组的内部信息。
    /// 如果输入有效（points不这空，epsilon >= 0），
    /// 在这种情况下，类成员有效。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector3Information final
    {
    public:
        using ClassType = Vector3Information<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using AxesAlignBoundingBox3Type = AxesAlignBoundingBox3<Real>;
        using ContainerType = std::vector<Vector3Type>;
        using AlgebraVector3 = Algebra::Vector<3, Real>;
        using AlgebraContainerType = std::vector<AlgebraVector3>;

    public:
        /// 值epsilon被使用在计算点集的维度时，作为相对误差。
        /// 构造函数根据输入集设置类成员。
        explicit Vector3Information(const ContainerType& points, Real epsilon = MathType::GetZeroTolerance());
        explicit Vector3Information(const AlgebraContainerType& points, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetDimension() const noexcept;
        NODISCARD AxesAlignBoundingBox3Type GetAxesAlignBoundingBox() const noexcept;
        NODISCARD Real GetMaxRange() const noexcept;
        NODISCARD Vector3Type GetOrigin() const noexcept;
        NODISCARD Vector3Type GetDirectionX() const noexcept;
        NODISCARD Vector3Type GetDirectionY() const noexcept;
        NODISCARD Vector3Type GetDirectionZ() const noexcept;
        NODISCARD Vector3Type GetMinExtreme() const;
        NODISCARD Vector3Type GetMaxExtreme() const;
        NODISCARD Vector3Type GetPerpendicularExtreme() const;
        NODISCARD Vector3Type GetTetrahedronExtreme() const;
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
        NODISCARD static ContainerType GetContainer(const AlgebraContainerType& points);

    private:
        using IndexContainerType = std::array<int, Vector3Type::pointSize>;

    private:
        ContainerType points;

        /// 一种非负公差，用于确定集合的内部维数。
        Real epsilon;

        /// 输入集的内部维度。
        /// 其中，参数“epsilon”被用于确定尺寸时提供容差。
        int dimension;

        /// 输入集的轴对齐包围盒。
        /// 最大范围是axesAlignBoundingBox.GetMaxPoint(0) - axesAlignBoundingBox.GetMinPoint(0) 、
        /// axesAlignBoundingBox.GetMaxPoint(1) - axesAlignBoundingBox.GetMinPoint(1)和
        /// axesAlignBoundingBox.GetMaxPoint(2) - axesAlignBoundingBox.GetMinPoint(2)的最大值。
        AxesAlignBoundingBox3Type axesAlignBoundingBox;
        Real maxRange;

        /// 坐标系。原点是对任何维度d都有效。
        /// 单位长度的方向向量只适用于0 <= i < d。
        /// 末端的索引是相对于输入的点的数组，并且也只适用于0 <= i < d。
        /// 如果d = 0，所有的点实际上是相同的，
        /// 但使用一个epsilon的可能会导致末端的索引不为零。
        /// 如果d = 1，所有点的位置在一条线段上。
        /// 当d = 2时，所有点不共线但在一个平面上。
        /// 当d = 3时，所有点是不共面的。
        Vector3Type origin;
        Vector3Type directionX;
        Vector3Type directionY;
        Vector3Type directionZ;

        /// 定义最大空间范围的索引。
        /// 值minExtreme和maxExtreme是用于定义在坐标轴各个方向中
        /// 的一个最大范围的索引数。
        /// 如果维度是2，则perpendicularExtreme是
        /// 垂直于相应的minExtreme和maxExtreme
        /// 最大范围生成的点的索引。
        /// 此外，如果维度是3，
        /// 则tetrahedronExtreme是垂直于由
        /// 其他末端点所定义的三角形方向上的最大范围的点。
        /// 由点V[minExtreme], V[maxExtreme],
        /// V[perpendicularExtreme]和V[tetrahedronExtreme]所形成的四面体，
        /// 是顺时针或逆时针，条件存储在extremeCCW。
        int minExtreme;
        int maxExtreme;
        int perpendicularExtreme;
        int tetrahedronExtreme;

        /// 是否是逆时针
        bool extremeCCW;

        /// 最小点和最大点索引
        IndexContainerType indexMin;
        IndexContainerType indexMax;
    };

    using FloatVector3Information = Vector3Information<float>;
    using DoubleVector3Information = Vector3Information<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_INFORMATION_H
