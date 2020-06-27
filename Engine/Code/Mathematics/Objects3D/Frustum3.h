// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:22)

#ifndef MATHEMATICS_OBJECTS3D_FRUSTUM3_H
#define MATHEMATICS_OBJECTS3D_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Frustum3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Frustum3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;		

	public:
		// 正交视锥体。
		// 设E是原点，D为方向向量，U是向上向量，而Real是右方向向量。
		// 设u > 0 且 r > 0分别是在U和Real方向的长度。
		// 设n和f是D的方向上的范围0 < n < f。
		// 四个角，在近的平面截锥是E + n*D + s0*u*U + s1*r*Real，
		// 其中|s0| =|s1| = 1（四个选项）。
		// 四个角的远平面的截锥是 E + f*D + (f/n)*(s0*u*U + s1*r*Real)，
		// 其中|s0| = |s1| = 1（四项选择）
		Frustum3(const Vector3D& origin, const Vector3D& directionVector, const Vector3D& upVector, const Vector3D& rightVector, Real directionMin,
				 Real directionMax, Real upBound, Real rightBound, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetOrigin() const;
		const Vector3D GetDirectionVector() const;
		const Vector3D GetUpVector() const;
		const Vector3D GetRightVector() const;
		Real GetDirectionMin() const;
		Real GetDirectionMax() const;
		Real GetUpBound() const;
		Real GetRightBound() const;

		Real GetDirectionRatio() const;
		Real GetMTwoUF() const;
		Real GetMTwoRF() const;

		// 返回8个顶点
		const std::vector<Vector3D> ComputeVertices() const;

	private:
		// Update()函数必须被调用在更改了m_DirectionMin，m_DirectionMax，
		// m_UpBound，或m_RightBound时。
		// 该值m_DirectionRatio，m_MTwoUF和m_MTwoRF都依赖于这些值的变化。
		void Update();

	private:
		Vector3D m_Origin;
		Vector3D m_DirectionVector;
		Vector3D m_UpVector;
		Vector3D m_RightVector;
		Real m_DirectionMin;
		Real m_DirectionMax;
		Real m_UpBound;
		Real m_RightBound;

		// 数值从构造函数的输入得到的。
		Real m_DirectionRatio;
		Real m_MTwoUF;
		Real m_MTwoRF;

		Real m_Epsilon;
	};

	using Frustum3f = Frustum3<float>;
	using Frustum3d = Frustum3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_FRUSTUM3_H
