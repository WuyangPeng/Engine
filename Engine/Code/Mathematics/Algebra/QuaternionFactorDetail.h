// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/05 19:13)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_DETAIL_H

#include "QuaternionFactor.h"
#include "Quaternion.h"
#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::QuaternionFactor<Real>
	::QuaternionFactor( const Quaternion& quaternion,QuaternionFactorFlags flag )
	:m_Quaternion{ quaternion }, m_SinX{}, m_CosX{}, m_SinY{}, m_CosY{}, m_SinZ{}, m_CosZ{}
{
	switch(flag)
	{
	case QuaternionFactorFlags::XYZ:
		FactorXYZ();
		break;
	case QuaternionFactorFlags::XZY:
		FactorXZY();
		break;
	case QuaternionFactorFlags::YZX:
		FactorYZX();
		break;
	case QuaternionFactorFlags::YXZ:
		FactorYXZ();
		break;
	case QuaternionFactorFlags::ZXY:
		FactorZXY();
		break;
	case QuaternionFactorFlags::ZYX:
		FactorZYX();
		break;
	default:
		MATHEMATICS_ASSERTION_1(false,"错误的枚举值！");
		break;		
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuaternionFactor<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::QuaternionFactor<Real>
	::GetSinX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SinX;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>
	::GetSinY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SinY;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>
	::GetSinZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SinZ;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>
	::GetCosX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_CosX;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>
	::GetCosY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_CosY;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>
	::GetCosZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_CosZ;
}


template <typename Real>
void Mathematics::QuaternionFactor<Real>
	::FactorXYZ()
{
	auto a = m_Quaternion[0] * m_Quaternion[1] - m_Quaternion[2] * m_Quaternion[3];
	auto b = static_cast<Real>(0.5) * (m_Quaternion[0] * m_Quaternion[0] -  m_Quaternion[1] * m_Quaternion[1] - m_Quaternion[2] * m_Quaternion[2] + m_Quaternion[3] * m_Quaternion[3]);

	auto fLength = Math::Sqrt(a * a + b * b);

	if (Math::sm_ZeroTolerance < fLength)
	{
		auto sigma0 = a / fLength;
		auto gamma0 = b / fLength;

		if (Real{} <= gamma0)
		{
			m_CosX = Math::Sqrt(static_cast<Real>(0.5) * (static_cast<Real>(1) + gamma0));
			m_SinX = static_cast<Real>(0.5) * sigma0 / m_CosX;
		}
		else
		{
			m_SinX = Math::Sqrt(static_cast<Real>(0.5) * (static_cast<Real>(1) - gamma0));
			m_CosX = static_cast<Real>(0.5) * sigma0 / m_SinX;
		}

		auto tmp0 = m_CosX * m_Quaternion[0] + m_SinX * m_Quaternion[1];
		auto tmp1 = m_CosX * m_Quaternion[3] - m_SinX * m_Quaternion[2];
		auto invLength = Math::InvSqrt(tmp0 * tmp0 + tmp1 * tmp1);
		m_CosZ = tmp0 * invLength;
		m_SinZ = tmp1 * invLength;

		if(Math::FAbs(m_SinZ) <= Math::FAbs(m_CosZ))
		{
			m_CosY = tmp0 / m_CosZ;
			m_SinY = (m_CosX * m_Quaternion[2] + m_SinX * m_Quaternion[3]) / m_CosZ;
		}
		else
		{
			m_CosY = tmp1 / m_CosZ;
			m_SinY = (m_CosX * m_Quaternion[1] - m_SinX * m_Quaternion[0]) / m_CosZ;
		}
	}
	else
	{
		// 无穷多解。选择其中之一。
		if (Real{} < m_Quaternion[0] * m_Quaternion[2] + m_Quaternion[1] * m_Quaternion[3])
		{
			// p = (p0,p1,p0,p1)
			m_CosX = static_cast<Real>(1);
			m_SinX = Real{ };
			m_CosY = Math::sm_InverseSqrt2;
			m_SinY = Math::sm_InverseSqrt2;
			m_CosZ = Math::sm_Sqrt2 * m_Quaternion[0];
			m_SinZ = Math::sm_Sqrt2 * m_Quaternion[1];
		}
		else
		{
			// p = (p0,p1,-p0,-p1)
			m_CosX = (Real)1;
			m_SinX = Real{};
			m_CosY = Math::sm_InverseSqrt2;
			m_SinY = -Math::sm_InverseSqrt2;
			m_CosZ = Math::sm_Sqrt2 * m_Quaternion[0];
			m_SinZ = -Math::sm_Sqrt2 * m_Quaternion[1];
		}
	}
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>
	::FactorXZY()
{
	m_Quaternion = Quaternion{ m_Quaternion[0], m_Quaternion[1],m_Quaternion[3], -m_Quaternion[2] };

	FactorXYZ();	

	Real temp = m_SinY;
	m_SinY = -m_SinZ;
	m_SinZ = temp;

	temp = m_CosY;
	m_CosY =  m_CosZ;
	m_CosZ = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>
	::FactorYZX()
{
	m_Quaternion = Quaternion{ m_Quaternion[0], -m_Quaternion[2],m_Quaternion[3], -m_Quaternion[1] };

	FactorXYZ();

	auto temp = m_SinZ;
	m_SinZ = m_SinY;
	m_SinY = -m_SinX;
	m_SinX = -temp;

	temp = m_CosZ;
	m_CosZ = m_CosY;
	m_CosY = m_CosX;
	m_CosX = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>
	::FactorYXZ()
{
	m_Quaternion = Quaternion{ m_Quaternion[0], -m_Quaternion[2],m_Quaternion[1], m_Quaternion[3] };
	
	FactorXYZ();

	auto temp = m_SinY;
	m_SinY = -m_SinX;
	m_SinX = temp;

	temp = m_CosY;
	m_CosY = m_CosX;
	m_CosX = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>
	::FactorZXY()
{
	m_Quaternion = Quaternion{ m_Quaternion[0], -m_Quaternion[3],m_Quaternion[1], -m_Quaternion[2] };

	FactorXYZ();

	auto temp = m_SinZ;
	m_SinZ = -m_SinX;
	m_SinX = m_SinY;
	m_SinY = -temp;

	temp = m_CosZ;
	m_CosZ = m_CosX;
	m_CosX = m_CosY;
	m_CosY = temp;	
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>
	::FactorZYX()
{
	m_Quaternion = Quaternion{ m_Quaternion[0], m_Quaternion[3],-m_Quaternion[2], m_Quaternion[1] };

	FactorXYZ();

	auto temp = m_SinZ;
	m_SinZ = m_SinX;
	m_SinX = temp;
	m_SinY = -m_SinY;

	temp = m_CosZ;
	m_CosZ = m_CosX;
	m_CosX = temp;
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_DETAIL_H

