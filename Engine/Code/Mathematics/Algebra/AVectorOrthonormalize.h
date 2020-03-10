// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:22)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class AVectorOrthonormalize
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AVectorOrthonormalize<Real>;
		using AVector = AVector<Real>;
		using Math = Math<Real>;

	public:
		// Gram-Schmidt��������
		// �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
		AVectorOrthonormalize(const AVector& lhs, const AVector& mhs,const AVector& rhs,const Real epsilon = Math::sm_ZeroTolerance);

		explicit AVectorOrthonormalize(const std::vector<AVector> vectors,const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

	    const AVector GetUVector() const;
	    const AVector GetVVector() const;
	    const AVector GetWVector() const;

	private:
	    void Generate();

	private:
	    AVector m_UVector;
	    AVector m_VVector;
	    AVector m_WVector; 
		Real m_Epsilon;		
	};		 	

	using AVectorOrthonormalizef = AVectorOrthonormalize<float>;
	using AVectorOrthonormalized = AVectorOrthonormalize<double>;
}

#endif // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
