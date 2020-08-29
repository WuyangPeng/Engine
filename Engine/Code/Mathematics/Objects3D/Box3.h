// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:16)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_H
#define MATHEMATICS_OBJECTS3D_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Box3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Box3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		// 一个盒子有中心点C，轴方向U[0]、U[1]和U[2]（垂直和单位长度的向量），
		// 和范围e[0]、e[1]和e[2]（非负数）。 
		// A point X = C+y[0]*U[0]+y[1]*U[1]+y[2]*U[2]是在内部或在盒子上，
		// 每当|y[i]| <= e[i]对于所有的i
		Box3();
		Box3(const Vector3D& center, const Vector3D& firstAxis, const Vector3D& secondAxis, const Vector3D& thirdAxis,
			 const Real firstExtent, const Real secondExtent, const Real thirdExtent, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		// 返回的顶点数为8
		const std::vector<Vector3D> ComputeVertices() const;
		const Vector3D GetCenter() const noexcept;
		const Vector3D GetFirstAxis() const noexcept;
		const Vector3D GetSecondAxis() const noexcept;
		const Vector3D GetThirdAxis() const noexcept;
		Real GetFirstExtent() const noexcept;
		Real GetSecondExtent() const noexcept;
		Real GetThirdExtent() const noexcept;
		const Vector3D GetAxis(int index) const;
		Real GetExtent(int index) const;

		Real GetEpsilon() const noexcept;

		const ClassType GetMove(Real t, const Vector3D& velocity) const;

		void Set(const Vector3D& center, const Vector3D& firstAxis, const Vector3D& secondAxis, const Vector3D& thirdAxis,
				 const Real firstExtent, const Real secondExtent, const Real thirdExtent);

	private:
		Vector3D m_Center;
		Vector3D m_Axis[3];
		Real m_Extent[3];
		Real m_Epsilon;
	};

	using Box3f = Box3<float>;
	using Box3d = Box3<double>;

	template <typename Real>
	bool Approximate(const Box3<Real>& lhs, const Box3<Real>& rhs, const Real epsilon);

	// 调试输出
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Box3<Real>& box);
}

#endif // MATHEMATICS_OBJECTS3D_BOX3_H
