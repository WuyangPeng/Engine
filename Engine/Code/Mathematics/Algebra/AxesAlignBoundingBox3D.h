// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 10:26)

// 轴对齐包围盒3D类的声明
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class AxesAlignBoundingBox3D
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AxesAlignBoundingBox3D<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		explicit AxesAlignBoundingBox3D(const Vector3D& minPoint,const Vector3D& maxPoint);

		// 调用者必须确保xMin <= xMax 、 yMin <= yMax和zMin <= zMax。
		AxesAlignBoundingBox3D (Real xMin, Real xMax, Real yMin, Real yMax,Real zMin, Real zMax);

		template <typename RhsType>
		AxesAlignBoundingBox3D(const AxesAlignBoundingBox3D<RhsType>& aabb);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetMinPoint() const; 
		const Vector3D GetMaxPoint() const;	

		// 计算盒子的中心点和盒子中心到盒子边缘（半径）的长度。
		const Vector3D GetCenter() const;
		Real GetExtentX() const;
		Real GetExtentY() const;
		Real GetExtentZ() const;

	private:
		void Recalculate();

	private:
		Vector3D m_MinPoint;
		Vector3D m_MaxPoint;
	};	

	// 重叠的测试是在严格意义上。
	// 如果两个盒子沿公共边刚好接触，盒子被报告为重叠。
	template <typename Real>
	bool HasXOverlap (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	template <typename Real>
	bool HasYOverlap (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	template <typename Real>
	bool HasZOverlap (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	template <typename Real>
	bool IsIntersection(const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);
	
	// 如果有重叠。在这种情况下，交点被返回。
	// 如果没有重叠，则抛出异常
	template <typename Real>
	const AxesAlignBoundingBox3D<Real> FindIntersection (const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs);

	using AxesAlignBoundingBox3Df = AxesAlignBoundingBox3D<float>;
	using AxesAlignBoundingBox3Dd = AxesAlignBoundingBox3D<double>;
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H