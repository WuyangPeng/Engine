// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 17:27)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_DETAIL_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_DETAIL_H

#include "AVector.h"

#include "Vector3D.h"
#include "AlgebraTraits.h"
#include "AVectorOrthonormalizeDetail.h"
#include "AVectorOrthonormalBasisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename T>
const Mathematics::AVector<T> Mathematics::AVector<T>
	::sm_Zero{ AlgebraTraits::NullValue,AlgebraTraits::NullValue,AlgebraTraits::NullValue };

template <typename T>
const Mathematics::AVector<T> Mathematics::AVector<T>
	::sm_UnitX{ AlgebraTraits::UnitValue,AlgebraTraits::NullValue,AlgebraTraits::NullValue };

template <typename T>
const Mathematics::AVector<T> Mathematics::AVector<T>
	::sm_UnitY{ AlgebraTraits::NullValue,AlgebraTraits::UnitValue,AlgebraTraits::NullValue };

template <typename T>
const Mathematics::AVector<T> Mathematics::AVector<T>
	::sm_UnitZ{ AlgebraTraits::NullValue,AlgebraTraits::NullValue,AlgebraTraits::UnitValue };

template <typename T>
Mathematics::AVector<T>
	::AVector()
	:m_HomogeneousPoint{ AlgebraTraits::NullValue,AlgebraTraits::NullValue,AlgebraTraits::NullValue,AlgebraTraits::NullValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::AVector<T>
	::~AVector()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::AVector<T>
	::AVector( T x, T y, T z )
	:m_HomogeneousPoint{ x,y,z,AlgebraTraits::NullValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::AVector<T>
	::AVector(const HomogeneousPoint& homogeneousPoint)
	:m_HomogeneousPoint{ homogeneousPoint }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::AVector<T>
	::AVector( const Float3& tuple )
	:m_HomogeneousPoint{ tuple.GetFirstValue(),tuple.GetSecondValue(),tuple.GetThirdValue(),AlgebraTraits::NullValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::AVector<T>
	::AVector( const Vector3D& rhs )
	:m_HomogeneousPoint{ rhs.GetXCoordinate(),rhs.GetYCoordinate(),rhs.GetZCoordinate(),AlgebraTraits::NullValue }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::AVector<T>
	::IsValid() const noexcept
{
	if(Math::FAbs(m_HomogeneousPoint.GetW() - AlgebraTraits::NullValue) <= Math::sm_Epsilon)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	


template <typename T>
const Mathematics::Float3 Mathematics::AVector<T>
	::GetFloat3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return Float3{ boost::numeric_cast<float>(m_HomogeneousPoint.GetX()),
				   boost::numeric_cast<float>(m_HomogeneousPoint.GetY()),
				   boost::numeric_cast<float>(m_HomogeneousPoint.GetZ()) };
}

template <typename T>
const Mathematics::Vector3D<T> Mathematics::AVector<T>
	::GetVector3D() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return Vector3D{ m_HomogeneousPoint.GetX(),m_HomogeneousPoint.GetY(),m_HomogeneousPoint.GetZ() };
}

template <typename T>
const T& Mathematics::AVector<T>
	::operator[]( int index ) const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	try
	{
		MATHEMATICS_ASSERTION_0(0 <= index && index < 3, "索引错误！");
	}
	catch (...)
	{

	}	

	return m_HomogeneousPoint[index];
}

template <typename T>
T& Mathematics::AVector<T>
	::operator[]( int index ) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	try
	{
		MATHEMATICS_ASSERTION_0(0 <= index && index < 3, "索引错误！");
	}
	catch (...)
	{

	}	

	return OPERATOR_SQUARE_BRACKETS(T,index);
}

template <typename T>
const Mathematics::AVector<T> Mathematics::AVector<T>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return AVector{ -m_HomogeneousPoint[0],-m_HomogeneousPoint[1],-m_HomogeneousPoint[2] };
}


template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>
	::operator+=( const ClassType& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] += rhs[0];
	m_HomogeneousPoint[1] += rhs[1];
	m_HomogeneousPoint[2] += rhs[2];

	return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>
	::operator-=( const ClassType& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] -= rhs[0];
	m_HomogeneousPoint[1] -= rhs[1];
	m_HomogeneousPoint[2] -= rhs[2];

	return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>
	::operator*=( T scalar )
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] *= scalar;
	m_HomogeneousPoint[1] *= scalar;
	m_HomogeneousPoint[2] *= scalar;

	return *this;
}

template <typename T>
Mathematics::AVector<T>& Mathematics::AVector<T>
	::operator/=( T scalar )
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (Math::sm_ZeroTolerance < Math::FAbs(scalar))
	{
		m_HomogeneousPoint[0] /= scalar;
		m_HomogeneousPoint[1] /= scalar;
		m_HomogeneousPoint[2] /= scalar;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false,"除零错误！");

		m_HomogeneousPoint[0] = Math::sm_MaxReal;
		m_HomogeneousPoint[1] = Math::sm_MaxReal;
		m_HomogeneousPoint[2] = Math::sm_MaxReal;
	}

	return *this;
}


template <typename T>
T Mathematics::AVector<T>
	::Length() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Math::Sqrt(SquaredLength());
}

template <typename T>
T Mathematics::AVector<T>
	::SquaredLength() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return  m_HomogeneousPoint[0] * m_HomogeneousPoint[0] + 
			m_HomogeneousPoint[1] * m_HomogeneousPoint[1] + 
			m_HomogeneousPoint[2] *	m_HomogeneousPoint[2];
}


template <typename T>
void Mathematics::AVector<T>
	::Normalize( const T epsilon )
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto length = Length();

	if (epsilon < length)
	{
		m_HomogeneousPoint[0] /= length;
		m_HomogeneousPoint[1] /= length;
		m_HomogeneousPoint[2] /= length;
	}
	else
	{		
		MATHEMATICS_ASSERTION_1(false,"除零错误！");

		m_HomogeneousPoint[0] = T();
		m_HomogeneousPoint[1] = T();
		m_HomogeneousPoint[2] = T();
	}
}

template <typename T>
bool Mathematics::AVector<T>
	::IsZero(const T epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto length = Length();

	if (epsilon < Math::FAbs(length))
	{
		return false;
	}
	else
	{		
		return true;
	}
}

template <typename T>
bool Mathematics::AVector<T>
	::IsNormalize(const T epsilon) const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto length = Length();

	if (epsilon < Math::FAbs(length - AlgebraTraits::UnitValue))
	{
		return false;
	}
	else
	{		
		return true;
	}
}

template <typename T>
bool Mathematics
	::Approximate( const AVector<T>& lhs, const AVector<T>& rhs,
	               const T epsilon )
{
	return Math<T>::FAbs(lhs[0] - rhs[0]) <= epsilon &&
		   Math<T>::FAbs(lhs[1] - rhs[1]) <= epsilon &&
		   Math<T>::FAbs(lhs[2] - rhs[2]) <= epsilon;
}

template <typename T>
bool Mathematics
	::Approximate( const AVector<T>& lhs, const AVector<T>& rhs )
{
	return Approximate(lhs,rhs,Math<T>::sm_ZeroTolerance);
}

template <typename T>
T Mathematics
	::Dot( const AVector<T>& lhs,const AVector<T>& rhs ) noexcept
{
	return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
}

template <typename T>
const Mathematics::AVector<T>
	Mathematics
	::Cross( const AVector<T>& lhs,const AVector<T>& rhs )
{
	return AVector<T> {lhs[1] * rhs[2] - lhs[2] * rhs[1],lhs[2] * rhs[0] - lhs[0] * rhs[2],lhs[0] * rhs[1] - lhs[1] * rhs[0] };
}

template <typename T>
const Mathematics::AVector<T> Mathematics
	::UnitCross( const AVector<T>& lhs,const AVector<T>& rhs ,const T epsilon)
{
	auto cross = Cross(lhs,rhs);
	
	cross.Normalize(epsilon);
	
	return cross;
}

template <typename T>
const Mathematics::AVector<T> Mathematics
	::UnitCross( const AVector<T>& lhs,const AVector<T>& rhs )
{
	return UnitCross(lhs,rhs,Math<T>::sm_ZeroTolerance);
} 

template <typename T>
const Mathematics::AVectorOrthonormalize<T>	Mathematics
	::Orthonormalize( const AVector<T>& lhs, const AVector<T>& mhs,const AVector<T>& rhs,const T epsilon)
{
	// 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
	//   u0 = v0 / |v0|
	//   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
	//   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / 
	//        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
	//
	// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

	return AVectorOrthonormalize<T>{ lhs, mhs, rhs, epsilon };
}

template <typename T>
const Mathematics::AVectorOrthonormalize<T> Mathematics
	::Orthonormalize( const std::vector<AVector<T> >& vectors ,const T epsilon)
{
	MATHEMATICS_ASSERTION_0(vectors.size() == 3,"vectors的大小错误！");

	return AVectorOrthonormalize<T>{ vectors, epsilon };
}


template <typename T>
const Mathematics::AVectorOrthonormalize<T>	Mathematics
	::Orthonormalize( const AVector<T>& lhs, const AVector<T>& mhs,const AVector<T>& rhs )
{
	return Orthonormalize(lhs,mhs,rhs,Math<T>::sm_ZeroTolerance);
}

template <typename T>
const Mathematics::AVectorOrthonormalize<T>
	Mathematics::Orthonormalize( const std::vector<AVector<T> >& vectors )
{
	MATHEMATICS_ASSERTION_0(vectors.size() == 3,"vectors的大小错误！");

	return Orthonormalize(vectors,Math<T>::sm_ZeroTolerance);
}

template <typename T>
const Mathematics::AVectorOrthonormalBasis<T> Mathematics
	::GenerateOrthonormalBasis( const AVector<T>& nonzeroVector ,const T epsilon)
{
	MATHEMATICS_ASSERTION_0(!nonzeroVector.IsZero(epsilon),"输入必须是非零向量！"); 

	return AVectorOrthonormalBasis<T>(nonzeroVector,false,epsilon);
}

template <typename T>
const Mathematics::AVectorOrthonormalBasis<T> Mathematics
	::GenerateOrthonormalBasis( const AVector<T>& nonzeroVector )
{
	return GenerateOrthonormalBasis(nonzeroVector,Math<T>::sm_ZeroTolerance);
}


template <typename T>
const Mathematics::AVectorOrthonormalBasis<T> Mathematics
	::GenerateComplementBasis( const AVector<T>& unitVector ,const T epsilon)
{
	MATHEMATICS_ASSERTION_0(unitVector.IsNormalize(epsilon),"输入必须是单位向量！");

	return AVectorOrthonormalBasis<T>(unitVector,true,epsilon);	
}

template <typename T>
const Mathematics::AVectorOrthonormalBasis<T> Mathematics
	::GenerateComplementBasis( const AVector<T>& unitVector )
{
	return  GenerateComplementBasis(unitVector,Math<T>::sm_ZeroTolerance);
}

template <typename T>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const AVector<T>& vector) 
{
	outFile << vector[0] << "　" << vector[1] << "　" << vector[2];

	return outFile;
}

#endif // MATHEMATICS_ALGEBRA_A_VECTOR_DETAIL_H
