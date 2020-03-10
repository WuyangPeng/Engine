// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:56)

#include "CoreTools/CoreToolsExport.h"

#include "DeltaTimeManagerImpl.h"
#include "System/Time/Data/CurrentDeltaTime.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::DeltaTimeManagerImpl
	::DeltaTimeManagerImpl()
	:m_Initial{ System::CurrentDeltaTime{}.GetDeltaTimeValueData() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeltaTimeManagerImpl);

uint64_t CoreTools::DeltaTimeManagerImpl
	::GetElapsedTimeInMicroseconds() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	System::CurrentDeltaTime currentTime{};

	auto result = currentTime.GetDeltaTimeValueData();

	auto deltaTime = result - m_Initial;

	return System::GetTimeInMicroseconds(deltaTime);
}

uint64_t CoreTools::DeltaTimeManagerImpl
	::GetElapsedTimeInSeconds() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	System::CurrentDeltaTime currentTime{};

	auto result = currentTime.GetDeltaTimeValueData();

	auto deltaTime = result - m_Initial;

	return System::GetTimeInSeconds(deltaTime);
}

void CoreTools::DeltaTimeManagerImpl
	::ResetCurrentTime()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	System::CurrentDeltaTime currentTime{};

	m_Initial = currentTime.GetDeltaTimeValueData();
}

uint64_t CoreTools::DeltaTimeManagerImpl
	::GetNowTimeInMicroseconds() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	System::CurrentDeltaTime currentTime{};

	return System::GetTimeInMicroseconds(currentTime.GetDeltaTimeValueData());
}

uint64_t CoreTools::DeltaTimeManagerImpl
	::GetNowTimeInSeconds() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	System::CurrentDeltaTime currentTime{};

	return System::GetTimeInSeconds(currentTime.GetDeltaTimeValueData());
}

