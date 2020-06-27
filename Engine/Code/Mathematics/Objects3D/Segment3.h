// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:24)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Segment3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Segment3<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		// 线段被表示为(1-s) * P0 + s * P1，其中P0和P1是线段的端点和0 <= s <= 1。
		//		
		// 一些算法涉及线段可能更喜欢定义一个中点的表示和面向包围盒的方向。
		// 此表示为C + t * D，其中C = (P0 + P1) / 2是该线段的中心，
		// D = (P1-P0)/Length(P1-P0)是一个单位长度方向的矢量，
		// 且|t| <= e。值 e = Length(P1-P0)/2是该线段的“范围”（半径或半长）。

		// 构造函数计算center、direction和extent从beginPoint和endPoint
		Segment3(const Vector3D& beginPoint, const Vector3D& endPoint, const Real epsilon = Math::sm_ZeroTolerance);

		// 构造函数计算beginPoint和endPoint从center、direction和extent
		Segment3(Real extent, const Vector3D& center, const Vector3D& direction, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetBeginPoint() const;
		const Vector3D GetEndPoint() const;
		const Vector3D GetCenterPoint() const;
		const Vector3D GetDirection() const;
		Real GetExtent() const;

		const ClassType GetMove(Real t, const Vector3D& velocity) const;

	private:
		// 当你改变beginPoint或endPoint时调用 
		void ComputeCenterDirectionExtent();

		// 当你改变center或direction或extent时调用 
		void ComputeEndPoints();

	private:
		// 终点表示。
		Vector3D m_BeginPoint;
		Vector3D m_EndPoint;

		// 中心—方向—范围表示。
		Vector3D m_Center;
		Vector3D m_Direction;
		Real m_Extent;

		Real m_Epsilon;
	};

	using Segment3f = Segment3<float>;
	using Segment3d = Segment3<double>;

	template <typename Real>
	bool Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, const Real epsilon);

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Segment3<Real>& segment);
}

#endif // MATHEMATICS_OBJECTS3D_SEGMENT3_H
