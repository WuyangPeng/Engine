// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class  GaussianQuadrature
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = GaussianQuadrature<Real, UserDataType>;

		// ���һ���������û���������ݡ�
		typedef Real(*Function)(Real, const UserDataType*);

	public:
		GaussianQuadrature(Real begin, Real end, Function function, const UserDataType* userData);

		CLASS_INVARIANT_DECLARE;

		Real GetResult() const;

	private:
		void Calculate();

	private:
		Real m_Radius;
		Real m_Center;
		Function m_Function;
		const UserDataType* m_UserData;
		Real m_Result;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
