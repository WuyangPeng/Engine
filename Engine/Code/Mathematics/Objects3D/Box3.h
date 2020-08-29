// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:16)

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
		// һ�����������ĵ�C���᷽��U[0]��U[1]��U[2]����ֱ�͵�λ���ȵ���������
		// �ͷ�Χe[0]��e[1]��e[2]���Ǹ������� 
		// A point X = C+y[0]*U[0]+y[1]*U[1]+y[2]*U[2]�����ڲ����ں����ϣ�
		// ÿ��|y[i]| <= e[i]�������е�i
		Box3();
		Box3(const Vector3D& center, const Vector3D& firstAxis, const Vector3D& secondAxis, const Vector3D& thirdAxis,
			 const Real firstExtent, const Real secondExtent, const Real thirdExtent, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		// ���صĶ�����Ϊ8
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

	// �������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Box3<Real>& box);
}

#endif // MATHEMATICS_OBJECTS3D_BOX3_H
