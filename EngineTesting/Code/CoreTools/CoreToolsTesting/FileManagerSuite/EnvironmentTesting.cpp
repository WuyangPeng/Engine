// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:41)

#include "EnvironmentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/FileManager/WriteFileManager.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EnvironmentTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
	const auto g_EnvironmentFileName = SYSTEM_TEXT("EnvironmentTestingText.txt"s);

	const auto g_EnvironmentPathFileName = SYSTEM_TEXT("Resource/EnvironmentTesting/EnvironmentTestingText.txt"s);
}
#include STSTEM_WARNING_POP
void CoreTools::EnvironmentTesting
	::MainTest()
{
	Environment::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InsertDirectoryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GetPathReadingSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GetPathWritingSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GetPathReadingAndWritingSucceedTest);
	ASSERT_THROW_EXCEPTION_0(GetPathReadingFailureTest);

	ASSERT_NOT_THROW_EXCEPTION_0(InsertDirectoryTest);
	ASSERT_THROW_EXCEPTION_0(GetPathWritingFailureTest);
	ASSERT_THROW_EXCEPTION_0(GetPathReadingAndWritingFailureTest);
	ASSERT_NOT_THROW_EXCEPTION_0(EraseDirectoryTest);

	ASSERT_NOT_THROW_EXCEPTION_0(ConfigurationPathTest);

	Environment::Destroy();
}

void CoreTools::EnvironmentTesting
	::InsertDirectoryTest()
{
	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetNumDirectories(), 0);

[[maybe_unused]] auto value =	ENVIRONMENT_SINGLETON.InsertDirectory(SYSTEM_TEXT("Resource/EnvironmentTesting/"s));

	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetNumDirectories(), 1);
}

void CoreTools::EnvironmentTesting
	::EraseDirectoryTest()
{
	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetNumDirectories(), 1);

[[maybe_unused]] auto value = ENVIRONMENT_SINGLETON.EraseDirectory(SYSTEM_TEXT("Resource/EnvironmentTesting/"s));

	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetNumDirectories(), 0);
}

void CoreTools::EnvironmentTesting
	::GetPathReadingSucceedTest()
{
	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetPathReading(g_EnvironmentFileName), g_EnvironmentPathFileName);
}

void CoreTools::EnvironmentTesting
	::GetPathWritingSucceedTest()
{
	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetPathWriting(g_EnvironmentFileName), g_EnvironmentPathFileName);
}

void CoreTools::EnvironmentTesting
	::GetPathReadingAndWritingSucceedTest()
{
	ASSERT_EQUAL(ENVIRONMENT_SINGLETON.GetPathReadingAndWriting(g_EnvironmentFileName), g_EnvironmentPathFileName);
}

void CoreTools::EnvironmentTesting
	::GetPathReadingFailureTest()
{
	ENVIRONMENT_SINGLETON.EraseAllDirectories();

[[maybe_unused]] auto value = ENVIRONMENT_SINGLETON.GetPathReading(g_EnvironmentFileName);
}

void CoreTools::EnvironmentTesting
	::GetPathWritingFailureTest()
{
	WriteFileManager manager{ g_EnvironmentPathFileName };

	[[maybe_unused]] auto value = ENVIRONMENT_SINGLETON.GetPathWriting(g_EnvironmentFileName);
}

void CoreTools::EnvironmentTesting
	::GetPathReadingAndWritingFailureTest()
{
	WriteFileManager manager{ g_EnvironmentPathFileName };

	[[maybe_unused]] auto value = ENVIRONMENT_SINGLETON.GetPathReadingAndWriting(g_EnvironmentFileName);
}

void CoreTools::EnvironmentTesting
	::ConfigurationPathTest()
{
	ASSERT_TRUE(ENVIRONMENT_SINGLETON.GetConfigurationPath().empty());

	auto configurationPath = SYSTEM_TEXT("Confing"s);

	ENVIRONMENT_SINGLETON.SetConfigurationPath(configurationPath);

	ASSERT_EQUAL(configurationPath, ENVIRONMENT_SINGLETON.GetConfigurationPath());
}

