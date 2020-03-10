// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 11:40)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/QuaternionFlags.h"
#include "Mathematics/Base/Math.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class QuaternionFactor
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = QuaternionFactor<Real>;
		using Quaternion = Quaternion<Real>;
		using Math = Math<Real>;

	public:			
		QuaternionFactor (const Quaternion& quaternion,QuaternionFactorFlags flag); 		

		CLASS_INVARIANT_DECLARE;
		
		Real GetSinX() const;
		Real GetSinY() const;
		Real GetSinZ() const;
		Real GetCosX() const;
		Real GetCosY() const;
		Real GetCosZ() const;

	private:
		// ϵ��Ϊ (cx + sx*i)*(cy + sy*j)*(cz + sz*k).
		void FactorXYZ ();

		// ϵ��Ϊ (cx + sx*i)*(cz + sz*k)*(cy + sy*j).
		void FactorXZY ();

		// ϵ��Ϊ (cy + sy*j)*(cz + sz*k)*(cx + sx*i).
		void FactorYZX ();

		// ϵ��Ϊ (cy + sy*j)*(cx + sx*i)*(cz + sz*k).
		void FactorYXZ ();

		// ϵ��Ϊ (cz + sz*k)*(cx + sx*i)*(cy + sy*j).
		void FactorZXY ();

		// ϵ��Ϊ (cz + sz*k)*(cy + sy*j)*(cx + sx*i).
		void FactorZYX ();
		
	private:
		Quaternion m_Quaternion;
		Real m_SinX;
		Real m_CosX;
		Real m_SinY;
		Real m_CosY;
		Real m_SinZ;
		Real m_CosZ;		
	};

	using QuaternionFactorf = QuaternionFactor<float>;
	using QuaternionFactord = QuaternionFactor<double>;
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H
