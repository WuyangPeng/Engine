// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:33)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H

#include "Intersector.h"

namespace Mathematics
{
	// ��̬�ཻ��ѯ��Ĭ��ʵ�ַ��ء�false����
	// Find��ѯ����һ����һ�νӴ����ཻ���ϡ�
	// �����ฺ���ṩ����,��Ϊ���ϵ����������ڶ������͡�
	template <typename Real, template <typename> class Vector>
	class DynamicIntersector : public Intersector<Real, Vector>
	{
	public:
		using VectorType = Vector<Real>;
		using ClassType = DynamicIntersector<Real, Vector>;
		using ParentType = Intersector<Real, Vector>;
		using Math = Math<Real>;

	public:
		explicit DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~DynamicIntersector() = 0;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		// ���������ڵ�һ�νӴ�ʱ��̬�ཻ��ѯ��ʱ�䡣
		Real GetContactTime() const;
		Real GetTMax() const;
		const VectorType GetLhsVelocity() const;
		const VectorType GetRhsVelocity() const;

	protected:
		void SetContactTime(Real contactTime);

	private:
		Real m_ContactTime;
		Real m_TMax;
		VectorType m_LhsVelocity;
		VectorType m_RhsVelocity;
	};

	using DynamicIntersector2f = DynamicIntersector<float, Vector2D>;
	using DynamicIntersector3f = DynamicIntersector<float, Vector3D>;
	using DynamicIntersector2d = DynamicIntersector<double, Vector2D>;
	using DynamicIntersector3d = DynamicIntersector<double, Vector3D>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
