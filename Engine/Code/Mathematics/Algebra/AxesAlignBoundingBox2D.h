// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 10:23)

// 轴对齐包围盒2D类的声明
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"

namespace Mathematics
{
	template <typename Real>
	class AxesAlignBoundingBox2D
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AxesAlignBoundingBox2D<Real>;
		using Vector2D = Vector2D<Real>;

	public:
		AxesAlignBoundingBox2D(const Vector2D& minPoint,const Vector2D& maxPoint);

		template <typename RhsType>
		AxesAlignBoundingBox2D(const AxesAlignBoundingBox2D<RhsType>& aabb);

		// 调用者必须确保xMin <= xMax 和 yMin <= yMax。
		AxesAlignBoundingBox2D (Real xMin, Real xMax, Real yMin, Real yMax);

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetMinPoint() const; 
		const Vector2D GetMaxPoint() const;	
		
		// 计算盒子的中心点和盒子中心到盒子边缘（半径）的长度。
		const Vector2D GetCenter() const;
		Real GetExtentX() const;
		Real GetExtentY() const;		

	private:
		void Recalculate();

	private:
		Vector2D m_MinPoint;
		Vector2D m_MaxPoint;
	};	
		
	// 重叠的测试是在严格意义上。
	// 如果两个盒子沿公共边刚好接触，盒子被报告为重叠。
	template <typename Real>
	bool HasXOverlap (const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);

	template <typename Real>
	bool HasYOverlap (const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);

	template <typename Real>
	bool IsIntersection(const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);
	
	// 如果有重叠。在这种情况下，交点被返回。
	// 如果没有重叠，则抛出异常
	template <typename Real>
	const AxesAlignBoundingBox2D<Real> FindIntersection (const AxesAlignBoundingBox2D<Real>& lhs,const AxesAlignBoundingBox2D<Real>& rhs);

	typedef AxesAlignBoundingBox2D<float> AxesAlignBoundingBox2Df;
	typedef AxesAlignBoundingBox2D<double> AxesAlignBoundingBox2Dd;
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H