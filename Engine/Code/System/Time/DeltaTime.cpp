// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:30)

#include "System/SystemExport.h"

#include "DeltaTime.h"
#include "Data/CurrentDeltaTime.h"
#include "System/Window/WindowSystem.h"

int64_t System
	::GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept
{
	return g_Microseconds * deltaTime.GetSecond() + deltaTime.GetMicrosecond();
}

int64_t System
	::GetTimeInMicroseconds() noexcept
{
	const CurrentDeltaTime currentTime{};

	const DeltaTimeValueData deltaTimeValueData{ currentTime.GetDeltaTimeValueData() };

	return GetTimeInMicroseconds(deltaTimeValueData);
}

int64_t System
	::GetTimeInSeconds(const DeltaTimeValueData& deltaTime) noexcept
{
	return deltaTime.GetSecond();
}

int64_t System
	::GetTimeInSeconds() noexcept
{
	const auto microseconds = GetTimeInMicroseconds();
	return microseconds / g_Microseconds;
}

void System
	::SystemPause() noexcept
{
	SystemCommand("PAUSE");
}
