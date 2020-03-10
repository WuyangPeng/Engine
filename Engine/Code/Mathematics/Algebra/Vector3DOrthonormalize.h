// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 14:05)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Vector3DOrthonormalize
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector3DOrthonormalize<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		// Gram-Schmidt������. 
		// �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
		Vector3DOrthonormalize(const Vector3D& lhs, const Vector3D& mhs,const Vector3D& rhs,const Real epsilon = Math::sm_ZeroTolerance);

		explicit Vector3DOrthonormalize(const std::vector<Vector3D> vectors,const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;
		
	    const Vector3D GetUVector() const;
	    const Vector3D GetVVector() const;
	    const Vector3D GetWVector() const;

	private:
	    void Generate();

	private:
	    Vector3D m_UVector;
	    Vector3D m_VVector;
	    Vector3D m_WVector; 
		Real m_Epsilon;
	};		 	

	using Vector3DOrthonormalizef = Vector3DOrthonormalize<float>;
	using Vector3DOrthonormalized = Vector3DOrthonormalize<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H
