// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:52)

// 3D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_DETAIL_H

#include "Vector3DTools.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR3D_TOOLS_DETAIL)

#include "Vector3D.h"
#include "Vector3DOrthonormalizeDetail.h"
#include "BarycentricCoordinatesDetail.h"
#include "Vector3DOrthonormalBasisDetail.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

#include "System/Helper/PragmaWarning.h" 

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

template <typename Real>
bool Mathematics::Vector3DTools<Real>
	::Approximate(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon)  
{
	MATHEMATICS_ASSERTION_1(Math::sm_Zero <= epsilon, "epsilon必须大于或等于0！");

	return Math::FAbs(lhs.GetXCoordinate() - rhs.GetXCoordinate()) < epsilon &&
		   Math::FAbs(lhs.GetYCoordinate() - rhs.GetYCoordinate()) < epsilon &&
		   Math::FAbs(lhs.GetZCoordinate() - rhs.GetZCoordinate()) < epsilon;
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::VectorMagnitude(const Vector3D& vector)  
{
	return Math::Sqrt(VectorMagnitudeSquared(vector));
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::VectorMagnitudeSquared(const Vector3D& vector)  
{
	return vector.GetXCoordinate() * vector.GetXCoordinate() + vector.GetYCoordinate() * vector.GetYCoordinate() + vector.GetZCoordinate() * vector.GetZCoordinate();
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::DotProduct(const Vector3D& lhs, const Vector3D& rhs)
{
	return (lhs.GetXCoordinate() * rhs.GetXCoordinate() + lhs.GetYCoordinate() * rhs.GetYCoordinate() + lhs.GetZCoordinate() * rhs.GetZCoordinate());
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D
Mathematics::Vector3DTools<Real>
	::CrossProduct(const Vector3D& lhs, const Vector3D& rhs) 
{
	return Vector3D{ lhs.GetYCoordinate() * rhs.GetZCoordinate() - lhs.GetZCoordinate() * rhs.GetYCoordinate(),
					 lhs.GetZCoordinate() * rhs.GetXCoordinate() - lhs.GetXCoordinate() * rhs.GetZCoordinate(),
					 lhs.GetXCoordinate() * rhs.GetYCoordinate() - lhs.GetYCoordinate() * rhs.GetXCoordinate() };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::CrossProductWithReduceMultiplication(const Vector3D& lhs, const Vector3D& rhs)
{
	auto t1 = lhs.GetXCoordinate() - lhs.GetYCoordinate();
	auto t2 = rhs.GetYCoordinate() + rhs.GetZCoordinate();
	auto t3 = lhs.GetXCoordinate() * rhs.GetZCoordinate();
	auto t4 = t1 * t2 - t3;

	return Vector3D{ rhs.GetYCoordinate() * (t1 - lhs.GetZCoordinate()) - t4,
					 lhs.GetZCoordinate() * rhs.GetXCoordinate() - t3,
					 t4 - lhs.GetYCoordinate() * (rhs.GetXCoordinate() - t2) };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::UnitCrossProduct(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon)
{
	auto cross = CrossProduct(lhs, rhs);
	cross.Normalize(epsilon);

	return cross;
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::Distance(const Vector3D& lhs, const Vector3D& rhs)
{
	return Math::Sqrt(DistanceSquared(lhs, rhs));
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::DistanceSquared(const Vector3D& lhs, const Vector3D& rhs)
{
	auto distanceX = lhs.GetXCoordinate() - rhs.GetXCoordinate();
	auto distanceY = lhs.GetYCoordinate() - rhs.GetYCoordinate();
	auto distanceZ = lhs.GetZCoordinate() - rhs.GetZCoordinate();

	return distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ;
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::ParallelVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon)
{
	auto moduleSquare = VectorMagnitudeSquared(rhs);

	if (epsilon < moduleSquare)
	{
		return rhs * (DotProduct(lhs, rhs) / moduleSquare);
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		return Vector3D();
	}
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::ApeakVectorLhsToRhs(const Vector3D& lhs, const Vector3D& rhs, const Real epsilon)
{
	return lhs - ParallelVectorLhsToRhs(lhs, rhs, epsilon);
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::ReflectionVector(const Vector3D& ray, const Vector3D& normal)
{
	return 2 * DotProduct(normal, ray) * normal - ray;
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::RefractionVector(const Vector3D& ray, const Vector3D& normal, Real consistencyRatio)
{
	MATHEMATICS_ASSERTION_1(consistencyRatio <= 1, "consistencyRatio必须小于或等于1！");

	auto cosphi = DotProduct(-ray, normal);
	auto conphiSquare = cosphi * cosphi;
	auto consistencyRatioSquare = consistencyRatio * consistencyRatio;
	auto costheta = 1 / consistencyRatioSquare * Math::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

	return consistencyRatio * ray - (costheta + consistencyRatio * cosphi) * normal;
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::FeatheringOutZAxes(const Vector3D& vector, Function function)
{
	if (function != nullptr)
	{
		auto r = function(vector.GetZCoordinate());

		return Vector3D{ vector.GetXCoordinate() * r,vector.GetYCoordinate() * r,vector.GetZCoordinate() };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s));
	}
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::TwistZAxes(const Vector3D& vector, Function function)
{
	if (function != nullptr)
	{
		auto delta = function(vector.GetZCoordinate());

		return Vector3D{ vector.GetXCoordinate() * Math::Cos(delta) - vector.GetYCoordinate() * Math::Sin(delta),
						 vector.GetXCoordinate() * Math::Sin(delta) - vector.GetYCoordinate() * Math::Cos(delta),
						 vector.GetZCoordinate() };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("函数指针为空！"s));
	}
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3D Mathematics::Vector3DTools<Real>
	::BendYAxes(const Vector3D& vector, Real curvatureRadius, Real bendCenter, Real bendAreaMin, Real bendAreaMax)
{
	MATHEMATICS_ASSERTION_1(bendAreaMin <= bendAreaMax, "bendAreaMin值必须小于或等于bendAreaMax！");

	auto y = vector.GetYCoordinate();

	if (vector.GetYCoordinate() <= bendAreaMin)
		y = bendAreaMin;
	else if (vector.GetYCoordinate() >= bendAreaMax)
		y = bendAreaMax;

	auto delta = 1 / curvatureRadius * (y - bendCenter);

	Vector3D bendVector;

	bendVector.SetXCoordinate(vector.GetXCoordinate());

	if (bendAreaMin <= vector.GetYCoordinate() && vector.GetYCoordinate() <= bendAreaMax)
	{
		bendVector.SetYCoordinate(-Math::Sin(delta) * (vector.GetZCoordinate() - curvatureRadius) + bendCenter);
		bendVector.SetZCoordinate(-Math::Cos(delta) * (vector.GetZCoordinate() - curvatureRadius) + bendCenter);
	}
	else if (vector.GetYCoordinate() < bendAreaMin)
	{
		bendVector.SetYCoordinate(-Math::Sin(delta) * (vector.GetZCoordinate() - curvatureRadius) + bendCenter + Math::Cos(delta) * (vector.GetYCoordinate() - bendAreaMin));

		bendVector.SetZCoordinate(-Math::Cos(delta) * (vector.GetZCoordinate() - curvatureRadius) + bendCenter + Math::Sin(delta) * (vector.GetYCoordinate() - bendAreaMin));
	}
	else if (bendAreaMax < vector.GetYCoordinate())
	{
		bendVector.SetYCoordinate(-Math::Sin(delta) * (vector.GetZCoordinate() - curvatureRadius) + curvatureRadius + Math::Cos(delta)  * (vector.GetYCoordinate() - bendAreaMax));

		bendVector.SetZCoordinate(-Math::Cos(delta) * (vector.GetZCoordinate() - curvatureRadius) + curvatureRadius + Math::Sin(delta) * (vector.GetYCoordinate() - bendAreaMax));
	}

	return bendVector;
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::ScalarTripleProduct(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs)
{
	return DotProduct(CrossProduct(lhs, mhs), rhs);
}

template <typename Real>
Real Mathematics::Vector3DTools<Real>
	::GetVectorIncludedAngle(const Vector3D& lhs, const Vector3D& rhs)
{
	return Math::ACos(DotProduct(lhs, rhs) / (VectorMagnitude(lhs) * VectorMagnitude(rhs)));
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::AxesAlignBoundingBox3D Mathematics::Vector3DTools<Real>
	::ComputeExtremes(const std::vector<Vector3D>& vectors)
{
	MATHEMATICS_ASSERTION_0(0 < vectors.size(), "在ComputeExtremes中的输入无效！\n");

	auto min = vectors[0];
	auto max = min;

	for (const auto& eachVector : vectors)
	{
		for (auto i = 0; i < 3; ++i)
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

	return AxesAlignBoundingBox3D{ min,max };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalize Mathematics::Vector3DTools<Real>
	::Orthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs, const Real epsilon)
{
	// 如果输入向量v0、v1和v2，则Gram-Schmidt正交向量产生矢量u0、u1和u2如下，
	//   u0 = v0 / |v0|
	//   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
	//   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / 
	//        |v2 - (u0 * v2)u0 - (u1 * v2)u1|
	//
	// 其中|A|表示向量A的长度和A * B表示向量A和B的点积

	return Vector3DOrthonormalize{ lhs, mhs, rhs,epsilon };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalize Mathematics::Vector3DTools<Real>
	::Orthonormalize(const std::vector<Vector3D> vectors, const Real epsilon)
{
	MATHEMATICS_ASSERTION_0(vectors.size() == 3, "vectors的大小错误！");

	return Vector3DOrthonormalize{ vectors,epsilon };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalBasis Mathematics::Vector3DTools<Real>
	::GenerateOrthonormalBasis(const Vector3D& nonzeroVector, const Real epsilon)
{
	MATHEMATICS_ASSERTION_0(!nonzeroVector.IsZero(epsilon), "输入必须是非零向量！");

	return Vector3DOrthonormalBasis{ nonzeroVector,false,epsilon };
}

template <typename Real>
typename const Mathematics::Vector3DTools<Real>::Vector3DOrthonormalBasis Mathematics::Vector3DTools<Real>
	::GenerateComplementBasis(const Vector3D& unitVector, const Real epsilon)
{
	MATHEMATICS_ASSERTION_0(unitVector.IsNormalize(epsilon), "输入必须是单位向量！");

	return Vector3DOrthonormalBasis{ unitVector,true,epsilon };
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR3D_TOOLS_DETAIL)


template <typename Real>
bool Mathematics
	::operator==(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 3 * sizeof(Real)) == 0;
}

template <typename Real>
bool Mathematics
	::operator<(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 3 * sizeof(Real)) < 0;
}

template <typename Real>
std::ostream& Mathematics
	::operator<< (std::ostream& outFile, const Vector3D<Real>& vector)
{
	return outFile << "x=" << vector.GetXCoordinate() << "　y=" << vector.GetYCoordinate() << "　z=" << vector.GetZCoordinate();
}



#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_DETAIL_H
