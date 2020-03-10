// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 17:13)

#ifndef MATHEMATICS_ALGEBRA_HQUATERNION_DETAIL_H
#define MATHEMATICS_ALGEBRA_HQUATERNION_DETAIL_H

#include "AQuaternion.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AQUATERNION_DETAIL)

#include "AVector.h"
#include "Matrix.h"
#include "AlgebraTraits.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::sm_Zero = AQuaternion<Real>{ AlgebraTraits::NullValue,AlgebraTraits::NullValue,AlgebraTraits::NullValue,AlgebraTraits::NullValue };

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::sm_Identity = AQuaternion<Real>{ AlgebraTraits::UnitValue, AlgebraTraits::NullValue, AlgebraTraits::NullValue, AlgebraTraits::NullValue };

template <typename Real>
Mathematics::AQuaternion<Real>
	::AQuaternion()
	:m_Tuple{}
{ 
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::AQuaternion<Real>
	::AQuaternion(Real w, Real x, Real y, Real z)
	:m_Tuple{ w,x,y,z }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::AQuaternion<Real>
	::AQuaternion(const AQuaternion& rhs)
	:m_Tuple{ rhs.m_Tuple[0],rhs.m_Tuple[1],rhs.m_Tuple[2],rhs.m_Tuple[3] }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::AQuaternion<Real>
	::AQuaternion(const Matrix& matrix)
{
	FromRotationMatrix(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::FromRotationMatrix( const Matrix& matrix )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	// �㷨��Ken Shoemake�����£���1987��SIGGRAPH�γ�����
	// ����Ԫ΢���ֺͿ��ٶ�������

	const int next[3]{ 1, 2, 0 };

	auto trace = matrix(0,0) + matrix(1,1) + matrix(2,2);

	if (Real{} < trace)
	{
		// |w| > 1/2, ����ѡ�� w > 1/2
		auto root = Math::Sqrt(trace + AlgebraTraits::UnitValue);  // 2w

		m_Tuple[0] = static_cast<Real>(0.5) * root;
		root = static_cast<Real>(0.5) / root;  // 1 / (4w)
		m_Tuple[1] = (matrix(2,1) - matrix(1,2)) * root;
		m_Tuple[2] = (matrix(0,2) - matrix(2,0)) * root;
		m_Tuple[3] = (matrix(1,0) - matrix(0,1)) * root;
	}
	else
	{
		// |w| <= 1/2
		int i{ 0 };
		if(matrix(0,0) < matrix(1,1))
		{
			i = 1;
		}
		if(matrix(i,i) < matrix(2,2))
		{
			i = 2;
		}		
		
		auto j = next[i];
		auto k = next[j];

		auto root = Math::Sqrt(matrix(i,i) - matrix(j,j) - matrix(k,k) + AlgebraTraits::UnitValue);
		Real* quat[3] { &m_Tuple[1], &m_Tuple[2], &m_Tuple[3] };
		*quat[i] = static_cast<Real>(0.5) * root;
		root = static_cast<Real>(0.5) / root;
		m_Tuple[0] = (matrix(k,j) - matrix(j,k)) * root;
		*quat[j] = (matrix(j,i) + matrix(i,j) ) * root;
		*quat[k] = (matrix(k,i)  + matrix(i,k) ) * root;
	}
}

template <typename Real>
Mathematics::AQuaternion<Real>
	::AQuaternion(const AVector& axis, Real angle)
{
	MATHEMATICS_ASSERTION_1(axis.IsNormalize(),"axis�����ǵ�λ������");

	FromAxisAngle(axis,angle);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::FromAxisAngle( const AVector& axis, Real angle )
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(axis.IsNormalize(),"axis�����ǵ�λ������");

	// ������ת����Ԫ����
	//   q = cos(A/2) + sin(A/2) * (x * i + y * j + z * k)

	auto halfAngle = static_cast<Real>(0.5) * angle;

	auto sinValue = Math::Sin(halfAngle);
	m_Tuple[0] = Math::Cos(halfAngle);

	m_Tuple[1] = sinValue * axis[0];
	m_Tuple[2] = sinValue * axis[1];
	m_Tuple[3] = sinValue * axis[2];
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>
	::operator=( const AQuaternion& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = rhs.m_Tuple[0];
	m_Tuple[1] = rhs.m_Tuple[1];
	m_Tuple[2] = rhs.m_Tuple[2];
	m_Tuple[3] = rhs.m_Tuple[3];

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AQuaternion<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const Real& Mathematics::AQuaternion<Real>
	::operator[]( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 4,"��������");

	return m_Tuple[index];
}

template <typename Real>
Real& Mathematics::AQuaternion<Real>
	::operator[]( int index ) 
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 4,"��������");

	return OPERATOR_SQUARE_BRACKETS(Real,index);
}

template <typename Real>
Real Mathematics::AQuaternion<Real>
	::GetW() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <typename Real>
Real Mathematics::AQuaternion<Real>
	::GetX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <typename Real>
Real Mathematics::AQuaternion<Real>
	::GetY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[2];
}

template <typename Real>
Real Mathematics::AQuaternion<Real>
	::GetZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[3];
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::SetW( Real w )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = w;
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::SetX( Real x )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = x;
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::SetY( Real y )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = y;
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::SetZ( Real z )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[3] = z;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>
	::operator*=( const AQuaternion& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	*this = *this * rhs;

	return *this;
}

template <typename Real>
const  Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return AQuaternion{ -m_Tuple[0],-m_Tuple[1],-m_Tuple[2],-m_Tuple[3] };
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>
	::operator+=( const AQuaternion& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 4; ++i)
	{
		m_Tuple[i] += rhs.m_Tuple[i];
	}

	return *this;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>
	::operator-=( const AQuaternion& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 4; ++i)
	{
		m_Tuple[i] -= rhs.m_Tuple[i];
	}

	return *this;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>
	::operator*=( Real scalar )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 4; ++i)
	{
		m_Tuple[i] *= scalar;
	}

	return *this;
}

template <typename Real>
Mathematics::AQuaternion<Real>& Mathematics::AQuaternion<Real>
	::operator/=( Real scalar )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if(Math::FAbs(scalar) <= Math::sm_ZeroTolerance)
	{
		for (auto i = 0; i < 4; ++i)
		{
			m_Tuple[i] = Math::sm_MaxReal;
		}
	}
	else
	{
		for (auto i = 0; i < 4; ++i)
		{
			m_Tuple[i] /= scalar;
		}
	}

	return *this;
}

template <typename Real>
typename const Mathematics::AQuaternion<Real>::Matrix Mathematics::AQuaternion<Real>
	::ToRotationMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto twoX  = static_cast<Real>(2) * m_Tuple[1];
	auto twoY  = static_cast<Real>(2) * m_Tuple[2];
	auto twoZ  = static_cast<Real>(2) * m_Tuple[3];
	auto twoWX = twoX * m_Tuple[0];
	auto twoWY = twoY * m_Tuple[0];
	auto twoWZ = twoZ * m_Tuple[0];
	auto twoXX = twoX * m_Tuple[1];
	auto twoXY = twoY * m_Tuple[1];
	auto twoXZ = twoZ * m_Tuple[1];
	auto twoYY = twoY * m_Tuple[2];
	auto twoYZ = twoZ * m_Tuple[2];
	auto twoZZ = twoZ * m_Tuple[3];

	return Matrix{ AlgebraTraits::UnitValue - (twoYY + twoZZ),twoXY - twoWZ,twoXZ + twoWY,Real{},
				   twoXY + twoWZ,AlgebraTraits::UnitValue - (twoXX + twoZZ),twoYZ - twoWX,Real{},
				   twoXZ - twoWY,twoYZ + twoWX,AlgebraTraits::UnitValue - (twoXX + twoYY),Real{},
				   Real{},Real{},Real{},AlgebraTraits::UnitValue };
}

template <typename Real>
typename const Mathematics::AQuaternion<Real>::AVector Mathematics::AQuaternion<Real>
	::ToAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	// ������ת����Ԫ���� 
	//   q = cos(A/2) + sin(A/2) * (x*i + y*j + z*k)

	auto sqrareLength = m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3];

	if (Math::sm_ZeroTolerance < sqrareLength)
	{
		auto invLength = Math::InvSqrt(sqrareLength);

		return AVector{ m_Tuple[1] * invLength,m_Tuple[2] * invLength,m_Tuple[3] * invLength };
	}
	else
	{
		// �Ƕ��� 0 (2 * pi��ģ), �����κ��ᶼ�С�
		return AVector{ AlgebraTraits::UnitValue,Real{},Real{} };
	}
}

template <typename Real>
Real Mathematics
	::AQuaternion<Real>::ToAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto sqrareLength = m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3];

	if (Math::sm_ZeroTolerance < sqrareLength)
	{
		return static_cast<Real>(2) * Math::ACos(m_Tuple[0]);
	}
	else
	{
		return Real{};
	}
}

template <typename Real>
Real Mathematics::AQuaternion<Real>
	::Length() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Math::Sqrt(SquaredLength());
}

template <typename Real>
Real Mathematics::AQuaternion<Real>
	::SquaredLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0] * m_Tuple[0] + m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3];
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::Normalize( Real epsilon )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto length = Length();

	if (epsilon < length)
	{
		m_Tuple[0] /= length;
		m_Tuple[1] /= length;
		m_Tuple[2] /= length;
		m_Tuple[3] /= length;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false,"��Ԫ�����򻯴���");

		m_Tuple[0] = Real{ };
		m_Tuple[1] = Real{ };
		m_Tuple[2] = Real{ };
		m_Tuple[3] = Real{ };
	}
}

template <typename Real>
bool Mathematics::AQuaternion<Real>
	::IsNormalize (Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto length = Length();

	if (epsilon < length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::Inverse() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto norm = SquaredLength();

	if (Math::sm_ZeroTolerance < norm)
	{
		return AQuaternion{ m_Tuple[0] / norm,-m_Tuple[1] / norm,-m_Tuple[2] / norm,-m_Tuple[3] / norm };
	}
	else
	{	
		MATHEMATICS_ASSERTION_1(false,"����һ����Ч�Ľ������Ǵ���");

		return AQuaternion{};
	}
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::Conjugate() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	
	return AQuaternion{ m_Tuple[0], -m_Tuple[1], -m_Tuple[2], -m_Tuple[3] };
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::Exp() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_1(Math::FAbs(m_Tuple[0]) <= Math::sm_ZeroTolerance,"��Ԫ��w�������0��");

	// ��� q = A * (x*i+y*j+z*k) ���� (x,y,z) �ǵ�λ���ȣ�Ȼ��
	// exp(q) = cos(A) + sin(A)*(x*i+y*j+z*k)��
	// ��� sin(A) �ǽӽ�Ϊ��,
	// ʹ�� exp(q) = cos(A) + A*(x*i+y*j+z*k) ��Ϊ A/sin(A) ������ 1��

	AQuaternion result;

	auto angle = Math::Sqrt(m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2] + m_Tuple[3] * m_Tuple[3]);

	auto sinValue = Math::Sin(angle);
	result.m_Tuple[0] = Math::Cos(angle);

	if (Math::sm_ZeroTolerance <= Math::FAbs(sinValue))
	{
		auto coeff = sinValue / angle;
		for (auto i = 1; i < 4; ++i)
		{
			result.m_Tuple[i] = coeff * m_Tuple[i];
		}
	}
	else
	{
		for (auto i = 1; i < 4; ++i)
		{
			result.m_Tuple[i] = m_Tuple[i];
		}
	}

	return result;
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::AQuaternion<Real>
	::Log() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	// ��� q = cos(A) + sin(A) * (x*i+y*j+z*k) ���� (x,y,z) �ǵ�λ����,
	// Ȼ�� log(q) = A * (x*i+y*j+z*k)�� 
	// ��� sin(A) �ǽӽ��㣬
	// ʹ�� log(q) = sin(A) * (x*i+y*j+z*k)
	// ��Ϊ A/sin(A) ������ 1��

	AQuaternion result;
	result.m_Tuple[0] = Real{ };

	if (Math::FAbs(m_Tuple[0]) < AlgebraTraits::UnitValue)
	{
		auto angle = Math::ACos(m_Tuple[0]);
		auto sinValue = Math::Sin(angle);
		if (Math::sm_ZeroTolerance <= Math::FAbs(sinValue))
		{
			auto coeff = angle / sinValue;
			for (auto i = 1; i < 4; ++i)
			{
				result.m_Tuple[i] = coeff * m_Tuple[i];
			}

			return result;
		}
	}

	for (auto i = 1; i < 4; ++i)
	{
		result.m_Tuple[i] = m_Tuple[i];
	}

	return result;
}

template <typename Real>
typename const Mathematics::AQuaternion<Real>::AVector Mathematics::AQuaternion<Real>
	::Rotate( const AVector& vector ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	
	// ����һ������u = (x0,y0,z0)�͵�λ���ȵ���Ԫ��q = <w,x,y,z>
	// ����v = (x1,y1,z1)��������uʹ��q��תΪv = q*u*q^{-1}��
	// ����*��ʾ��Ԫ���˷�������u����Ϊ��Ԫ��<0,x0,y0,z0>��
	// ��Ҫע�����q^{-1} = <w,-x,-y,-z>��
	// ����û�������Ĺ���ȥȡq���档

	// ����
	//   q*u*q^{-1} = q*<0,x0,y0,z0>*q^{-1}
	//     = q*(x0*i+y0*j+z0*k)*q^{-1}
	//     = x0*(q*i*q^{-1})+y0*(q*j*q^{-1})+z0*(q*k*q^{-1})
	//	
	// �Ǽ�����HQuaternion<Real>::ToRotationMatrix����ת������С�
	// ����v�������Ϊ������u����ת����ĳ˻���
	// ��ˣ���ת�������Ԫ����ʾ��
	// ��Ҫ�Ⱦ�����ٵĿռ�͸����ʱ����������ת���������
	// ���͵Ŀռ䡪��ʱ��Ȩ�⡭��

	auto matrix = ToRotationMatrix();

	return matrix * vector;
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::Slerp( Real t, const AQuaternion& firstQuaternion, const AQuaternion& secondQuaternion )
{
	MATHEMATICS_CLASS_IS_VALID_9;	

	auto cosValue = Dot(firstQuaternion,secondQuaternion);
	auto angle = Math::ACos(cosValue);

	if (Math::sm_ZeroTolerance <= Math::FAbs(angle))
	{
		auto sinValue = Math::Sin(angle);
		auto tAngle = t * angle;
		auto coeff0 = Math::Sin(angle - tAngle) / sinValue;
		auto coeff1 = Math::Sin(tAngle) / sinValue;

		m_Tuple[0] = coeff0 * firstQuaternion.m_Tuple[0] + coeff1 * secondQuaternion.m_Tuple[0];
		m_Tuple[1] = coeff0 * firstQuaternion.m_Tuple[1] + coeff1 * secondQuaternion.m_Tuple[1];
		m_Tuple[2] = coeff0 * firstQuaternion.m_Tuple[2] + coeff1 * secondQuaternion.m_Tuple[2];
		m_Tuple[3] = coeff0 * firstQuaternion.m_Tuple[3] + coeff1 * secondQuaternion.m_Tuple[3];
	}
	else
	{
		*this = firstQuaternion;
	}	
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::Intermediate( const AQuaternion& firstQuaternion, const AQuaternion& secondQuaternion, const AQuaternion& thirdQuaternion )
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(firstQuaternion.IsNormalize() && secondQuaternion.IsNormalize() && thirdQuaternion.IsNormalize(),
							"firstQuaternion��secondQuaternion��thirdQuaternion���붼�ǵ�λ���ȣ�");

	auto secondQuaternionConjugate = secondQuaternion.Conjugate();
	auto p0 = secondQuaternionConjugate * firstQuaternion;
	auto p2 = secondQuaternionConjugate * thirdQuaternion;

	auto arg = -static_cast<Real>(0.25) * (p0.Log() + p2.Log());
	*this = secondQuaternion * arg.Exp();
}

template <typename Real>
void Mathematics::AQuaternion<Real>
	::Squad( Real t, const AQuaternion& q0,const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1 )
{
	MATHEMATICS_CLASS_IS_VALID_9;
	
	auto slerpT = static_cast<Real>(2) * t * (AlgebraTraits::UnitValue - t);

	AQuaternion slerpP;
	slerpP.Slerp(t, q0, q1);

	AQuaternion slerpQ;
	slerpQ.Slerp(t, a0, a1);

	Slerp(slerpT, slerpP, slerpQ);
}

#endif //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AQUATERNION_DETAIL)

template <typename Real>
bool Mathematics
	::operator==( const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs )
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(Real)) == 0;
}

template <typename Real>
bool Mathematics
	::operator<( const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs )
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(Real)) < 0;
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics
	::operator*( const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs )
{
	// ע��:  �˷�һ�㲻�ǿɽ����ģ������ڴ��������£�
	// p * q != q * p

	return AQuaternion<Real>{ lhs[0] * rhs[0] -
		                      lhs[1] * rhs[1] -
							  lhs[2] * rhs[2] -
							  lhs[3] * rhs[3],
							 
							  lhs[0] * rhs[1] +
							  lhs[1] * rhs[0] +
							  lhs[2] * rhs[3] -
							  lhs[3] * rhs[2],
							 
							  lhs[0] * rhs[2] +
							  lhs[2] * rhs[0] +
							  lhs[3] * rhs[1] -
							  lhs[1] * rhs[3],
					   
							  lhs[0] * rhs[3] +
							  lhs[3] * rhs[0] +
							  lhs[1] * rhs[2] -
							  lhs[2] * rhs[1] };
}

template <typename Real>
Real Mathematics
	::Dot( const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs )
{
	return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2] + lhs[3] * rhs[3];
}


template <typename Real>
bool Mathematics	
	::Approximate( const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs,const Real epsilon )
{
	return Math<Real>::FAbs(lhs[0] - rhs[0]) <= epsilon &&
		   Math<Real>::FAbs(lhs[1] - rhs[1]) <= epsilon &&
		   Math<Real>::FAbs(lhs[2] - rhs[2]) <= epsilon &&
		   Math<Real>::FAbs(lhs[3] - rhs[3]) <= epsilon;
}


template <typename Real>
bool Mathematics
	::Approximate( const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs )
{
	return Approximate(lhs,rhs,Math<Real>::sm_ZeroTolerance);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion)
{
	outFile << "w = " << quaternion.GetW() 
		    << "x = " << quaternion.GetX() 
			<< "y = " << quaternion.GetY() 
			<< "z = " << quaternion.GetZ();

	return outFile;
}

#endif // MATHEMATICS_ALGEBRA_HQUATERNION_DETAIL_H
