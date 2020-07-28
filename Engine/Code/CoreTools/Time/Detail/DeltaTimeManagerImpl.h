// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:55)

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
		DeltaTimeManagerImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		void ResetCurrentTime() noexcept;
		uint64_t GetElapsedTimeInMicroseconds() const noexcept;
		uint64_t GetElapsedTimeInSeconds() const noexcept;
		uint64_t GetNowTimeInMicroseconds() const noexcept;
		uint64_t GetNowTimeInSeconds() const noexcept;

	private:
		System::DeltaTimeValueData m_Initial;
	};
}

#endif // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
