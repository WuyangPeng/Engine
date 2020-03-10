// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 13:55)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Vector2DInformation
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector2DInformation<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;
		using AxesAlignBoundingBox2D = AxesAlignBoundingBox2D<Real>;
		using AxesAlignBoundingBox2DPtr = std::shared_ptr<AxesAlignBoundingBox2D>;
	
	public:
		// 值epsilon被使用在计算点集的维度时，作为相对误差。
		Vector2DInformation(const std::vector<Vector2D>& points,Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;
		
		int GetDimension() const;
		AxesAlignBoundingBox2DPtr GetAABBPtr() const;
		Real GetMaxRange() const;
		const Vector2D GetOrigin() const;
		const Vector2D GetDirectionX() const;
		const Vector2D GetDirectionY() const;
		const Vector2D GetMinExtreme() const;
		const Vector2D GetMaxExtreme() const;
		const Vector2D GetPerpendicularExtreme() const;
		bool IsExtremeCCW() const;
		int GetMinExtremeIndex() const;
		int GetPerpendicularExtremeIndex() const;
		int GetMaxExtremeIndex() const;
		int GetIndexMin(int index) const;

	private:
		void Init();
		void ComputeAxisAlignedBoundingBox();
		void DetermineMaximumRange();
		bool TestPointSetIsNearlyAPoint();
		bool TestPointSetIsNearlyALineSegment();

	private:
		std::vector<Vector2D> m_Points;
		Real m_Epsilon;

		// 输入集的固有维度。
		// 其中，参数“epsilon”被用于确定尺寸时提供容差。 
		int m_Dimension;		

		// 输入集的轴对齐包围盒。
		// 最大范围是aabb.max.x - aabb.min.x 和 aabb.max.y - aabb.min.y的最大值。
		AxesAlignBoundingBox2DPtr m_AABBPtr;		
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
		bool m_ExtremeCCW; // 是否是逆时针

        // 最小点和最大点索引
        int m_IndexMin[2];
        int m_IndexMax[2];
	};	

	using Vector2DInformationf = Vector2DInformation<float>;
	using Vector2DInformationd = Vector2DInformation<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_INFORMATION_H
