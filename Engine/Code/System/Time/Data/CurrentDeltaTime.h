// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:29)

#ifndef SYSTEM_TIME_CURRENT_DELTA_TIME_H
#define SYSTEM_TIME_CURRENT_DELTA_TIME_H

#include "System/SystemDll.h"  

#include "DeltaTimeValueData.h"
#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
	// ��ȡ��ǰʱ��
	class SYSTEM_DEFAULT_DECLARE CurrentDeltaTime
	{
	public:
		using ClassType = CurrentDeltaTime;

	public:
		CurrentDeltaTime() noexcept;

		const DeltaTimeValueData GetDeltaTimeValueData() const noexcept;

	public:
		DeltaTimeB m_CurrentTime;
	};
}

#endif // SYSTEM_TIME_CURRENT_DELTA_TIME_H