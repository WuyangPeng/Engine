// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 17:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Ellipse2Tool
	{
	public:
		using ClassType = DistancePoint2Ellipse2Tool<Real>;
		using Vector2D = Vector2D<Real>;

	public:
		DistancePoint2Ellipse2Tool(Real firstExtent, Real secondExtent, const Vector2D& vector, Real zeroThreshold);

		CLASS_INVARIANT_DECLARE;

		Real GetSquaredDistance() const;
		const Vector2D GetOutputVector() const;

	private:
		// 椭圆是(x0 / e0)^2 + (x1 / e1)^2 = 1且e0 >= e1。
		// 查询点是(y0,y1)与 y0 >= 0 和y1 >= 0
		// 函数返回从查询点到椭圆的平方距离。
		// 它也计算在第一象限最接近(y0,y1)的椭圆点 (x0,x1) 。
		void ComputeSquaredDistance();

		// 椭圆是 (x0 / e0)^2 + (x1 / e1)^2 = 1。
		// 查询点是 (y0,y1)。
		// 函数返回从查询点到椭圆的平方距离。
		// 它也计算最接近(y0,y1)的椭圆点 (x0,x1) 。
		void ComputeSquaredDistanceSpecial(const Vector2D& extent, const Vector2D& queryPoint);

	private:
		Vector2D m_Extent;
		Vector2D m_InputVector;
		Vector2D m_OutputVector;
		Real m_SquaredDistance;
		Real m_ZeroThreshold;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_H
