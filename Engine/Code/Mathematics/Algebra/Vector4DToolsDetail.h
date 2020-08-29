// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:54)

// 4D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_DETAIL_H

#include "Vector4DTools.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL)

#include "Vector4D.h"

#include <iostream>
#include "System/Helper/PragmaWarning.h" 
 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
template <typename Real>
bool Mathematics::Vector4DTools<Real>
	::Approximate(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon)
{
	MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= epsilon, "epsilon必须大于或等于0！");

	return Math::FAbs(lhs.GetXCoordinate() - rhs.GetXCoordinate()) < epsilon &&
		   Math::FAbs(lhs.GetYCoordinate() - rhs.GetYCoordinate()) < epsilon &&
		   Math::FAbs(lhs.GetZCoordinate() - rhs.GetZCoordinate()) < epsilon &&
		   Math::FAbs(lhs.GetWCoordinate() - rhs.GetWCoordinate()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>
	::VectorMagnitude(const Vector4D& vector)
{
	return Math::Sqrt(VectorMagnitudeSquared(vector));
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>
	::VectorMagnitudeSquared(const Vector4D& vector)
{
	return vector.GetXCoordinate() * vector.GetXCoordinate() +
		   vector.GetYCoordinate() * vector.GetYCoordinate() +
		   vector.GetZCoordinate() * vector.GetZCoordinate() +
		   vector.GetWCoordinate() * vector.GetWCoordinate();
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>
	::Distance(const Vector4D& lhs, const Vector4D& rhs)
{
	return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>
	::DistanceSquared(const Vector4D& lhs, const Vector4D& rhs)
{
	auto distanceX = lhs.GetXCoordinate() - rhs.GetXCoordinate();
	auto distanceY = lhs.GetYCoordinate() - rhs.GetYCoordinate();
	auto distanceZ = lhs.GetZCoordinate() - rhs.GetZCoordinate();
	auto distanceW = lhs.GetWCoordinate() - rhs.GetWCoordinate();

	return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ + distanceW * distanceW;
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>
	::DotProduct(const Vector4D& lhs, const Vector4D& rhs)
{
	return (lhs.GetXCoordinate() * rhs.GetXCoordinate() +
			lhs.GetYCoordinate() * rhs.GetYCoordinate() +
			lhs.GetZCoordinate() * rhs.GetZCoordinate() +
			lhs.GetWCoordinate() * rhs.GetWCoordinate());
}

template <typename Real>
typename const Mathematics::Vector4DTools<Real>::Vector4D Mathematics::Vector4DTools<Real>
	::ParallelVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon)
{
	auto moduleSquare = VectorMagnitudeSquared(rhs);

	if (epsilon < moduleSquare)
	{
		return rhs * (DotProduct(lhs, rhs) / moduleSquare);
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		return Vector4D();
	}
}

template <typename Real>
typename const Mathematics::Vector4DTools<Real>::Vector4D Mathematics::Vector4DTools<Real>
	::ApeakVectorLhsToRhs(const Vector4D& lhs, const Vector4D& rhs, const Real epsilon)
{
	return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
Real Mathematics::Vector4DTools<Real>
	::GetVectorIncludedAngle(const Vector4D& lhs, const Vector4D& rhs)
{
	return Math::ACos(DotProduct(lhs, rhs) / (VectorMagnitude(lhs) * VectorMagnitude(rhs)));
}

template <typename Real>
typename const Mathematics::Vector4DTools<Real>::AxesAlignBoundingBox4D Mathematics::Vector4DTools<Real>
	::ComputeExtremes(const std::vector<Vector4D>& vectors)
{
	MATHEMATICS_ASSERTION_0(0 < vectors.size(), "在ComputeExtremes中的输入无效！\n");

	auto min = vectors[0];
	auto max = min;

	for (const auto& eachVector : vectors)
	{
		for (auto i = 0; i < 4; ++i)
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

	return AxesAlignBoundingBox4D{ min,max };
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_DETAIL)

template <typename Real>
bool Mathematics
	::operator==(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(Real)) == 0;
}

template <typename Real>
bool Mathematics
	::operator<(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(Real)) < 0;
}

template <typename Real>
std::ostream& Mathematics
	::operator<< (std::ostream& outFile, const Vector4D<Real>& vector)
{
	return outFile << "x = " << vector.GetXCoordinate() << " y = " << vector.GetYCoordinate()
		           << " z = " << vector.GetZCoordinate() << " w = " << vector.GetWCoordinate();
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_DETAIL_H

