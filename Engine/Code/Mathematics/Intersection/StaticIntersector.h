// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H

#include "Intersector.h"

namespace Mathematics
{
	// ��̬�ཻ��ѯ��Ĭ��ʵ�ַ��ء�false����Find��ѯ����һ���ཻ���ϡ�
	// �����ฺ���ṩ����,��Ϊ���ϵ����������ڶ������͡�
	template <typename Real, template <typename> class Vector>
	class StaticIntersector : public Intersector<Real, Vector>
	{
	public:
		using Math = Math<Real>;
		using ClassType = StaticIntersector<Real, Vector>;
		using ParentType = Intersector<Real, Vector>;

	public:
		explicit StaticIntersector(const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticIntersector() = 0;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};

	using StaticIntersector2f = StaticIntersector<float, Vector2D>;
	using StaticIntersector3f = StaticIntersector<float, Vector3D>;
	using StaticIntersector2d = StaticIntersector<double, Vector2D>;
	using StaticIntersector3d = StaticIntersector<double, Vector3D>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
