// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:48)

// 2D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_DETAIL_H

#include "Vector2DTools.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_DETAIL)

#include "Vector2D.h"
#include "Vector2DOrthonormalizeDetail.h"
#include "Vector2DOrthonormalBasisDetail.h"
#include "BarycentricCoordinatesDetail.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

    #include "System/Helper/PragmaWarning.h" 

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

#include <iostream>

template <typename Real>
bool Mathematics::Vector2DTools<Real>
	::Approximate(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
	MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

	return Math::FAbs(lhs.GetXCoordinate() - rhs.GetXCoordinate()) < epsilon &&
		   Math::FAbs(lhs.GetYCoordinate() - rhs.GetYCoordinate()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::VectorMagnitude(const Vector2D& vector)  
{
	return Math::Sqrt(VectorMagnitudeSquared(vector));
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::VectorMagnitudeSquared(const Vector2D& vector)  
{

	return vector.GetXCoordinate() * vector.GetXCoordinate() + vector.GetYCoordinate() * vector.GetYCoordinate();
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::Distance(const Vector2D& lhs, const Vector2D& rhs)  
{
	return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::DistanceSquared(const Vector2D& lhs, const Vector2D& rhs)  
{
	auto distanceX = lhs.GetXCoordinate() - rhs.GetXCoordinate();
	auto distanceY = lhs.GetYCoordinate() - rhs.GetYCoordinate();

	return distanceX * distanceX + distanceY * distanceY;
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::DotProduct(const Vector2D& lhs, const Vector2D& rhs)  
{
	return (lhs.GetXCoordinate() * rhs.GetXCoordinate() + lhs.GetYCoordinate() * rhs.GetYCoordinate());
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::PseudoCrossProduct(const Vector2D& lhs, const Vector2D& rhs)
{
	return DotPerp(lhs, rhs);
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>
	::ParallelVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
	MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

	auto moduleSquare = VectorMagnitudeSquared(rhs);

	if (epsilon < moduleSquare)
	{
		return rhs * (DotProduct(lhs, rhs) / moduleSquare);
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		return Vector2D{};
	}
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>
	::ApeakVectorLhsToRhs(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
	return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::GetVectorIncludedAngle(const Vector2D& lhs, const Vector2D& rhs)  
{
	return Math::ACos(DotProduct(lhs, rhs) / (VectorMagnitude(lhs) * VectorMagnitude(rhs)));
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>
	::GetPerp(const Vector2D& vector)  
{
	return Vector2D{ vector.GetYCoordinate(), -vector.GetXCoordinate() };
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2DTools<Real>
	::GetUnitPerp(const Vector2D& vector, const Real epsilon)
{
	auto perp = GetPerp(vector);
	perp.Normalize(epsilon);

	return perp;
}

template <typename Real>
Real Mathematics::Vector2DTools<Real>
	::DotPerp(const Vector2D& lhs, const Vector2D& rhs)  
{
	return DotProduct(Vector2D(-lhs.GetYCoordinate(), lhs.GetXCoordinate()), rhs);
}

template <typename Real>
const typename Mathematics::Vector2DTools<Real>::AxesAlignBoundingBox2D	Mathematics::Vector2DTools<Real>
	::ComputeExtremes(const std::vector<Vector2D>& vectors)
{
	MATHEMATICS_ASSERTION_0(0 < vectors.size(), "在ComputeExtremes中的输入无效！\n");

	auto min = vectors[0];
	auto max = min;

	for (const auto& eachVector : vectors)
	{
		for (auto i = 0; i < 2; ++i)
		{
			if (eachVector[i] < min[i])
			{
				min[i] = eachVector[i];
			}
			else if (max[i] < eachVector[i])
			{
				max[i] = eachVector[i];
			}
		}
	}

	return AxesAlignBoundingBox2D{ min,max };
}

template <typename Real>
const typename Mathematics::Vector2DTools<Real>::Vector2DOrthonormalize Mathematics::Vector2DTools<Real>
	::Orthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon)
{
	// 如果输入向量v0和v1，则Gram-Schmidt正交向量产生矢量u0和u1如下，
	//
	//   u0 = v0 / |v0|
	//   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
	//
	// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

	return Vector2DOrthonormalize{ lhs, rhs,epsilon };
}

template <typename Real>
const typename Mathematics::Vector2DTools<Real>::Vector2DOrthonormalBasis Mathematics::Vector2DTools<Real>
	::GenerateOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon)
{
	return Vector2DOrthonormalBasis{ nonzeroVector,epsilon };
}

#include STSTEM_WARNING_POP

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_DETAIL)

template <typename Real>
bool Mathematics
	::operator==(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 2 * sizeof(Real)) == 0;
}

template <typename Real>
bool Mathematics
	::operator<(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 2 * sizeof(Real)) < 0;
}

template <typename Real>
std::ostream& Mathematics
	::operator<< (std::ostream& outFile, const Vector2D<Real>& vector)
{
	return outFile << "x=" << vector.GetXCoordinate() << "　y=" << vector.GetYCoordinate();
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_DETAIL_H