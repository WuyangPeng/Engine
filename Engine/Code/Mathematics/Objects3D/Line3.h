// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 09:09)
#ifndef MATHEMATICS_OBJECTS3D_LINE3_H
#define MATHEMATICS_OBJECTS3D_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/Math.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Line3
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Line3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;

	public:
		// 线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t是任意实数。
		// 用户必须确保D是单位长度。
		Line3 (const Vector3D& origin, const Vector3D& direction,const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetOrigin() const;
		const Vector3D GetDirection() const;

		const ClassType GetMove(Real t, const Vector3D& velocity) const;

	private:
		Vector3D m_Origin;
		Vector3D m_Direction;
		Real m_Epsilon;
	};

	template <typename Real>
	bool Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, const Real epsilon);

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Line3<Real>& line);

	using Line3f = Line3<float>;
	using Line3d = Line3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_LINE3_H
