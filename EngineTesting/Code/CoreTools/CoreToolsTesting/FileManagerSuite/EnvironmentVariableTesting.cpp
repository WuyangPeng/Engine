// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:42)

#include "EnvironmentVariableTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EnvironmentVariableTesting)

void CoreTools::EnvironmentVariableTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(EnvironmentTest);
	ASSERT_NOT_THROW_EXCEPTION_0(JsonTest);
}

void CoreTools::EnvironmentVariableTesting
	::EnvironmentTest()
{
	EnvironmentVariable variable{ SYSTEM_TEXT("EngineInclude"s) };

	auto path = variable.GetVariable();

	ASSERT_UNEQUAL(path.find(SYSTEM_TEXT("Code"s)), System::String::npos);
}

void CoreTools::EnvironmentVariableTesting
	::JsonTest()
{
	EnvironmentVariable variable{ SYSTEM_TEXT("JSON"s) };

	auto path = variable.GetVariable();

	ASSERT_EQUAL(path, System::String{ SYSTEM_TEXT("JSON"s) });
}