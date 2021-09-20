// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:37)

#include "StringReplacingTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/EngineConfiguration/StringReplacing.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, StringReplacing)

void CoreTools::StringReplacingTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(StringReplacingTest);
}

void CoreTools::StringReplacingTesting
	::StringReplacingTest()
{
	TestingType stringReplacing{ "Configuration/StringReplacing.json" };

	ASSERT_EQUAL(stringReplacing.GetReplacing(SYSTEM_TEXT("V1")), System::String(SYSTEM_TEXT("Temp1")));
	ASSERT_EQUAL(stringReplacing.GetReplacing(SYSTEM_TEXT("V2")), System::String(SYSTEM_TEXT("Temp2")));
}
