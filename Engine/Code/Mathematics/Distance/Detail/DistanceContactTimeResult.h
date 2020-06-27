// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 17:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H

#include "DistanceResultImpl.h"

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceContactTimeResult : public DistanceResultImpl<Real, Vector>
	{
	public:
		using ClassType = DistanceContactTimeResult<Real, Vector>;
		using ParentType = DistanceResultImpl<Real, Vector>;
		using ImplTypePtr = ParentType::ImplTypePtr;

	public:
		DistanceContactTimeResult(Real distance, Real contactTime);
		virtual ~DistanceContactTimeResult();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// �����ڶ�̬��ѯ����С�����ʱ�䡣
		virtual Real GetContactTime() const override;
		virtual void SetContactTime(Real contactTime) override;

		virtual ImplTypePtr Clone() const override;

		virtual bool isHaveContactTime() const override;

	private:
		Real m_ContactTime;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
