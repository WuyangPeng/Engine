// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 16:55)

#ifndef CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H 
#define CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Time/DeltaTime.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE DeltaTimeManagerImpl
	{
	public:
		using ClassType = DeltaTimeManagerImpl;

	public:
		DeltaTimeManagerImpl();

		CLASS_INVARIANT_DECLARE;

		void ResetCurrentTime();
		uint64_t GetElapsedTimeInMicroseconds() const;
		uint64_t GetElapsedTimeInSeconds() const;
		uint64_t GetNowTimeInMicroseconds() const;
		uint64_t GetNowTimeInSeconds() const;

	private:
		System::DeltaTimeValueData m_Initial;
	};
}

#endif // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
