// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 17:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "CoreTools/Contract/ImplStaticAssertHelper.h"

#include <vector>

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceResultImpl;

	template <typename Real, typename Vector>
	class DistanceResult
	{
	public:
		using ClassType = DistanceResult<Real, Vector>;
		using ImplType = DistanceResultImpl<Real, Vector>;
		using ClassShareType = CoreTools::DelayCopyUnsharedClasses;
		using ClosestPoints = std::vector<Vector>;

	public:
		explicit DistanceResult(Real distance);
		DistanceResult(Real distance, Real contactTime);
		DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint);
		DistanceResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);
		DistanceResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter);

		CLASS_INVARIANT_DECLARE;

		Real GetDistance() const;

		// �����ڶ�̬��ѯ����С�����ʱ�䡣
		Real GetContactTime() const;

		// �����������������㡣��Щ�ھ�̬��̬��ѯʱ����Ч�ġ�
		// ���������ϵļ��������������һ����ʱ������������£�GetSize��������ֵ����1��
		// GetPoint����֧�ֲ�ѯ�������������顣
		const Vector GetLhsClosestPoint() const;
		const Vector GetRhsClosestPoint() const;
		const Vector GetLhsClosestPoint(int index) const;
		const Vector GetRhsClosestPoint(int index) const;
		int GetLhsClosestPointSize() const;
		int GetRhsClosestPointSize() const;

		void SetDistance(Real distance);
		void SetContactTime(Real contactTime);
		void SetSqrtDistance();
		void Set(Real distance, Real contactTime);

		Real GetLhsParameter() const;
		Real GetRhsParameter() const;

	private:
		void Copy();

	private:
		IMPL_TYPE_DECLARE(DistanceResult);
	};

	using DistanceResult2f = DistanceResult<float, Vector2Df>;
	using DistanceResult3f = DistanceResult<float, Vector3Df>;
	using DistanceResult2d = DistanceResult<double, Vector2Dd>;
	using DistanceResult3d = DistanceResult<double, Vector3Dd>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RESULT_H
