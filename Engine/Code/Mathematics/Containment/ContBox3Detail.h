// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 16:24)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX3_DETAIL_H

#include "ContBox3.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3DDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3Detail.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ContBox3<Real>
	::ContBox3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ContBox3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::ContBox3<Real>::Box3 Mathematics::ContBox3<Real>
	::ContAlignedBox(const Points& points)
{
	auto aabb =	Vector3DTools<Real>::ComputeExtremes(points);
	auto halfDiagonal = static_cast<Real>(0.5) * (aabb.GetMaxPoint() - aabb.GetMinPoint());

	return Box3{ static_cast<Real>(0.5) * (aabb.GetMinPoint() + aabb.GetMaxPoint()),
				 Vector3D::sm_UnitX, Vector3D::sm_UnitY,Vector3D::sm_UnitZ,
				 halfDiagonal[0], halfDiagonal[1], halfDiagonal[2] };
}

template <typename Real>
typename const Mathematics::ContBox3<Real>::Box3 Mathematics::ContBox3<Real>
	::ContOrientedBox(const Points& points)
{
	GaussPointsFit3<Real> gaussPointsFit3{ points };
	auto box = gaussPointsFit3.GetBox3();

	// ��C�ǰ�Χ�����ģ���U0,U1��U2�ǰ�Χ�е��ᡣ
	// ÿһ����������ʽΪX = C + y0 * U0 + y1 * U1 + y2 * U2��
	// ����Ĵ������min(y0), max(y0), min(y1),max(y1), min(y2)��max(y2)��
	// Ȼ���Χ�����ı�����Ϊ 
	//   C' = C + 0.5 * (min(y0) + max(y0)) * U0 + 0.5 * (min(y1) + max(y1)) * U1 +
	//        0.5 * (min(y2) + max(y2)) * U2
	std::vector<Real> firstDotCollection;
	std::vector<Real> secondDotCollection;
	std::vector<Real> thirdDotCollection;
	firstDotCollection.reserve(points.size());
	secondDotCollection.reserve(points.size());
	thirdDotCollection.reserve(points.size());

	for(const auto& point: points)
	{
		auto diff = point - box.GetCenter();
		 
		auto firstDot = Vector3DTools<Real>::DotProduct(diff, box.GetFirstAxis());
		firstDotCollection.push_back(firstDot);

		auto secondDot = Vector3DTools<Real>::DotProduct(diff, box.GetSecondAxis());
		secondDotCollection.push_back(secondDot);

		auto thirdDot = Vector3DTools<Real>::DotProduct(diff, box.GetThirdAxis());
		thirdDotCollection.push_back(thirdDot);
	}

	auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

	auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

	auto thirdBoundary = std::minmax_element(thirdDotCollection.begin(), thirdDotCollection.end());

	auto center = box.GetCenter() +
		          (static_cast<Real>(0.5) * (*firstBoundary.first + *firstBoundary.second) * box.GetFirstAxis() +
				  static_cast<Real>(0.5) * (*secondBoundary.first + *secondBoundary.second) * box.GetSecondAxis() +
				  static_cast<Real>(0.5) * (*thirdBoundary.first + *thirdBoundary.second) * box.GetThirdAxis());

	auto firstExtent = (*firstBoundary.second - *firstBoundary.first) * static_cast<Real>(0.5);
	auto secondExtent = (*secondBoundary.second - *secondBoundary.first) * static_cast<Real>(0.5);
	auto thirdExtent = (*thirdBoundary.second - *thirdBoundary.first) * static_cast<Real>(0.5);

	return Box3{ center, box.GetFirstAxis(), box.GetSecondAxis(), box.GetThirdAxis(), firstExtent, secondExtent, thirdExtent };
}


template <typename Real>
bool Mathematics::ContBox3<Real>
	::InBox(const Vector3D& point, const Box3& box)
{
	auto diff = point - box.GetCenter();
	auto firstCoeff = Vector3DTools<Real>::DotProduct(diff, box.GetFirstAxis());

	if (box.GetFirstExtent() + box.GetEpsilon() < firstCoeff)
		return false;

	auto secondCoeff = Vector3DTools<Real>::DotProduct(diff, box.GetSecondAxis());

	if (box.GetSecondExtent() + box.GetEpsilon() < secondCoeff)
		return false;

	auto thirdCoeff = Vector3DTools<Real>::DotProduct(diff, box.GetThirdAxis());

	if (box.GetThirdExtent() + box.GetEpsilon() < thirdCoeff)
		return false;
    
    return true;
}


template <typename Real>
typename const Mathematics::ContBox3<Real>::Box3 Mathematics::ContBox3<Real>
	::MergeBoxes(const Box3& lhs, const Box3& rhs)
{
	// �ڰ�Χ�����ĵĵ�һ�����롣�����Χ�ж���ͶӰ��ȷ����ƽ����Χ�е��ᣬ
	// ��ֵ���ں�����и��¡�
	auto center = static_cast<Real>(0.5) * (lhs.GetCenter() + rhs.GetCenter()); 

	// һ����Χ�е��ᣬ����һ���о����γ�һ����ת����
	// �����Χ�е��ᱻת��Ϊ��Ԫ����
	// ����ƽ����Ԫ����Ȼ���׼��Ϊ��λ���ȡ�
	// ���Ϊ����tֵΪ1/2������������Ԫ�����������Բ�ֵ��
	// �����ת������ת����������б�ѡ����Ϊ�ϲ���Χ�е��ᡣ
	std::vector<Vector3D> lhsRotationColumn{ lhs.GetFirstAxis(), lhs.GetSecondAxis(), lhs.GetThirdAxis() };

	std::vector<Vector3D> rhsRotationColumn{ rhs.GetFirstAxis(), rhs.GetSecondAxis(), rhs.GetThirdAxis() };

	Quaternion<Real> lhsQuaternion{ lhsRotationColumn };
	Quaternion<Real> rhsQuaternion{ rhsRotationColumn };
 
	if (Dot(lhsQuaternion,rhsQuaternion) < Math<Real>::GetValue(0))
    {
		rhsQuaternion = -rhsQuaternion;
    }

	auto sumQuaternion = lhsQuaternion + rhsQuaternion;
	auto invLength = Math<Real>::InvSqrt(Dot(sumQuaternion,sumQuaternion));
    sumQuaternion = invLength * sumQuaternion;

	const auto sumRotationColumn = sumQuaternion.ToRotationColumnVector3D();
 
	// ��Ŀ�������Χ�ж��㵽�ϲ���İ�Χ�е��ᡣ
	// ��������D[i]������ǰ����C������СͶӰֵmin[i]�����ͶӰֵmax[i]��
	// �����ϵ���Ӧ��������C + min[i] * D[i] and C + max[i] * D[i]��
	// C�㲢��һ�����κ�ʱ�������е㡣
	// ʵ�ʰ�Χ�����Ľ���C����Ϊ��C'��ÿ��������е㣬
	//   C' = C + sum_{i=0}^2 0.5 * (min[i] + max[i]) * D[i]
	// ��Χ�еķ�Χ��
	//  e[i] = 0.5 * (max[i] - min[i])
	auto lhsVertices = lhs.ComputeVertices();
	auto rhsVertices = rhs.ComputeVertices();

	lhsVertices.insert(lhsVertices.end(), rhsVertices.begin(), rhsVertices.end());

	std::vector<Real> firstDotCollection;
	std::vector<Real> secondDotCollection;
	std::vector<Real> thirdDotCollection;
	firstDotCollection.reserve(lhsVertices.size());
	secondDotCollection.reserve(lhsVertices.size());
	thirdDotCollection.reserve(lhsVertices.size());

	for(const auto& point: lhsVertices)
	{
		auto diff = point - center;

		auto firstDot = Vector3DTools<Real>::DotProduct(diff, sumRotationColumn[0]);
		firstDotCollection.push_back(firstDot);

		auto secondDot = Vector3DTools<Real>::DotProduct(diff, sumRotationColumn[1]);
		secondDotCollection.push_back(secondDot);

		auto thirdDot = Vector3DTools<Real>::DotProduct(diff, sumRotationColumn[2]);
		thirdDotCollection.push_back(thirdDot);
	}

	auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

	auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

	auto thirdBoundary = std::minmax_element(thirdDotCollection.begin(), thirdDotCollection.end());
    
	// [min,max] Ϊ�ϲ���İ�Χ�е���������ϵ��Ϊ������Χ�С�
	// ���µ�ǰ��Χ�����ĳ�Ϊ�°�Χ�е����ġ���������µ����ĵķ�Χ��
	center += static_cast<Real>(0.5) * (*firstBoundary.first + *firstBoundary.second) * sumRotationColumn[0] +
		      static_cast<Real>(0.5) * (*secondBoundary.first + *secondBoundary.second) * sumRotationColumn[1]  +
			  static_cast<Real>(0.5) * (*thirdBoundary.first + *thirdBoundary.second) * sumRotationColumn[2];

	auto firstExtent = (*firstBoundary.second - *firstBoundary.first) * static_cast<Real>(0.5);
	auto secondExtent = (*secondBoundary.second - *secondBoundary.first) * static_cast<Real>(0.5);
	auto thirdExtent = (*thirdBoundary.second - *thirdBoundary.first) * static_cast<Real>(0.5);

	return Box3{ center, sumRotationColumn[0], sumRotationColumn[1], sumRotationColumn[2], firstExtent, secondExtent, thirdExtent };
}

#endif // MATHEMATICS_CONTAINMENT_CONT_BOX3_DETAIL_H
 