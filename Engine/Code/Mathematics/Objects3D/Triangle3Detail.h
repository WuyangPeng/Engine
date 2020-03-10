// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 10:19)

#ifndef MATHEMATICS_OBJECTS3D_TRIANGLE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_TRIANGLE3_DETAIL_H

#include "Triangle3.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Triangle3<Real>
	::Triangle3( const Vector3D& firstVector,const Vector3D& secondVector,const Vector3D& thirdVector )
{
	m_Vertex[0] = firstVector;
	m_Vertex[1] = secondVector;
	m_Vertex[2] = thirdVector;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Triangle3<Real>
	::IsValid() const noexcept
{	
	return true;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
const std::vector<typename Mathematics::Triangle3<Real>::Vector3D> Mathematics::Triangle3<Real>
	::GetVertex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	std::vector<Vector3D> vertex{ m_Vertex[0],m_Vertex[1] ,m_Vertex[2] }; 

	return vertex;
}

template <typename Real>
const std::vector<typename Mathematics::Triangle3<Real>::Vector3D> Mathematics::Triangle3<Real>
	::GetEdgeVectors() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	std::vector<Vector3D> vertex{ m_Vertex[1] - m_Vertex[0] ,m_Vertex[2] - m_Vertex[1],m_Vertex[0] - m_Vertex[2] }; 

	return vertex;
}

template <typename Real>
const typename Mathematics::Triangle3<Real>::Vector3D Mathematics::Triangle3<Real>
	::GetNormal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector3DTools::UnitCrossProduct(m_Vertex[1] - m_Vertex[0], m_Vertex[2] - m_Vertex[1]);
}

template <typename Real>
typename const Mathematics::Triangle3<Real>::Vector3D Mathematics::Triangle3<Real>
	::GetVertex(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_1(0 <= index && index < 3, "索引越界！");

	return m_Vertex[index];
}

template <typename Real>
Real Mathematics::Triangle3<Real>
	::DistanceTo( const Vector3D& point ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto diff = m_Vertex[0] - point;
	auto edge0 = m_Vertex[1] - m_Vertex[0];
	auto edge1 = m_Vertex[2] - m_Vertex[0];
	auto a00 = Vector3DTools::VectorMagnitudeSquared(edge0);
	auto a01 = Vector3DTools::DotProduct(edge0,edge1);
	auto a11 = Vector3DTools::VectorMagnitudeSquared(edge1);
	auto b0 = Vector3DTools::DotProduct(diff,edge0);
	auto b1 = Vector3DTools::DotProduct(diff,edge1);
	auto c = Vector3DTools::VectorMagnitudeSquared(diff);
	auto det = Math::FAbs(a00 * a11 - a01 * a01);
	auto s = a01 * b1 - a11 * b0;
	auto t = a01 * b0 - a00 * b1;
	Real sqrDistance { };

	if (s + t <= det)
	{
		if (s < Real{})
		{
			if (t < Real{})  // 区域4
			{
				if (b0 < Real{})
				{
					if (a00 <= -b0)
					{
						sqrDistance = a00 + static_cast<Real>(2) * b0 + c;
					}
					else
					{
						sqrDistance = c - b0 * b0 / a00;
					}
				}
				else
				{
					if (Real{} <= b1)
					{
						sqrDistance = c;
					}
					else if (a11 <= -b1)
					{
						sqrDistance = a11 + static_cast<Real>(2) * b1 + c;
					}
					else
					{
						sqrDistance = c - b1 * b1 / a11;
					}
				}
			}
			else  // 区域3
			{
				if (Real{} <= b1)
				{
					sqrDistance = c;
				}
				else if (a11 <= -b1)
				{
					sqrDistance = a11 + static_cast<Real>(2) * b1 + c;
				}
				else
				{
					sqrDistance = c - b1 * b1 / a11;
				}
			}
		}
		else if (t < Real{})  // 区域5
		{
			if (Real{} <= b0)
			{
				sqrDistance = c;
			}
			else if (a00 <= -b0)
			{
				sqrDistance = a00 + static_cast<Real>(2) * b0 + c;
			}
			else
			{
				sqrDistance = b0 * s + c - b0 * b0 / a00;
			}
		}
		else   // 区域0
		{        
			// 最小是在三角形的内部点。
			Real invDet = static_cast<Real>(1) / det;
			s *= invDet;
			t *= invDet;
			sqrDistance = s * (a00 * s + a01 * t + static_cast<Real>(2) * b0) +
				          t * (a01 * s + a11 * t + static_cast<Real>(2) * b1) + c;
		}
	}
	else
	{
		if (s < Real{})  // 区域2
		{
			auto tmp0 = a01 + b0;
			auto tmp1 = a11 + b1;
			if (tmp0 < tmp1)
			{
				auto numer = tmp1 - tmp0;
				auto denom = a00 - static_cast<Real>(2) * a01 + a11;
				if (numer >= denom)
				{
					sqrDistance = a00 + static_cast<Real>(2) * b0 + c;
				}
				else
				{
					s = numer / denom;
					t = static_cast<Real>(1) - s;
					sqrDistance = s * (a00 * s + a01 * t + static_cast<Real>(2) * b0) +
						          t * (a01 * s + a11 * t + static_cast<Real>(2) * b1) +
						          c;
				}
			}
			else
			{
				if (tmp1 <= Real{})
				{
					sqrDistance = a11 + static_cast<Real>(2) * b1 + c;
				}
				else if (Real{} <= b1)
				{
					sqrDistance = c;
				}
				else
				{
					sqrDistance = c - b1 * b1 / a11;
				}
			}
		}
		else if (t < Real{})  // 区域 6
		{
			auto tmp0 = a01 + b1;
			auto tmp1 = a00 + b0;
			if (tmp0 < tmp1)
			{
				auto numer = tmp1 - tmp0;
				auto denom = a00 - static_cast<Real>(2) * a01 + a11;
				if (denom <= numer)
				{
					t = static_cast<Real>(1);
					s = Real { };
					sqrDistance = a11 + static_cast<Real>(2) * b1 + c;
				}
				else
				{
					t = numer / denom;
					s = static_cast<Real>(1) - t;
					sqrDistance = s * (a00 * s + a01 * t + static_cast<Real>(2) * b0) +
						          t * (a01 * s + a11 * t + static_cast<Real>(2) * b1) +
						          c;
				}
			}
			else
			{
				if (tmp1 <= Real{})
				{
					sqrDistance = a00 + static_cast<Real>(2) * b0 + c;
				}
				else if (Real{} <= b0)
				{
					sqrDistance = c;
				}
				else
				{
					sqrDistance = c - b0 * b0 / a00;
				}
			}
		}
		else  // 区域 1
		{
			auto numer = a11 + b1 - a01 - b0;
			if (numer <= Real{})
			{
				sqrDistance = a11 + static_cast<Real>(2) * b1 + c;
			}
			else
			{
				auto denom = a00 - static_cast<Real>(2) * a01 + a11;
				if (denom <= numer)
				{
					sqrDistance = a00 + static_cast<Real>(2) * b0 + c;
				}
				else
				{
					s = numer / denom;
					t = static_cast<Real>(1) - s;
					sqrDistance = s * (a00 * s + a01 * t + static_cast<Real>(2) * b0) +
						          t * (a01 * s + a11 * t + static_cast<Real>(2) * b1) + 
						          c;
				}
			}
		}
	}

	return Math::Sqrt(Math::FAbs(sqrDistance));
}


#endif // MATHEMATICS_OBJECTS3D_TRIANGLE3_DETAIL_H

 