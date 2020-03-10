// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:30)

#ifndef SYSTEM_TIME_DELTA_TIME_FWD_H
#define SYSTEM_TIME_DELTA_TIME_FWD_H 

#include "System/Helper/ConfigMacro.h"
#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
	class CurrentDeltaTime;
	class DeltaTimeValueData;

	DeltaTimeValueData operator -(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept;

	int64_t GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept;
	int64_t GetTimeInSeconds(const DeltaTimeValueData& deltaTime) noexcept;
	int64_t GetTimeInMicroseconds() noexcept;
	int64_t GetTimeInSeconds() noexcept;
	void SystemPause() noexcept;
}

#endif // SYSTEM_TIME_DELTA_TIME_FWD_H