// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:37)

#include "CopyFileToolsTesting.h"
#include "CoreTools/FileManager/CopyFileTools.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
	const auto g_CFileManagerHelpFileName = SYSTEM_TEXT("Resource/CFileManagerTesting/CFileManagerHelpTestingText.txt"s);

	const auto g_CFileManagerHelpContent = SYSTEM_TEXT("CFileManagerHelp Testing Text"s);

	const auto g_CopyFileName = SYSTEM_TEXT("Resource/CopyFile.txt"s);
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CopyFileToolsTesting)

void CoreTools::CopyFileToolsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CopyFileTest);
	ASSERT_NOT_THROW_EXCEPTION_0(VerificationTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
	ASSERT_THROW_EXCEPTION_0(VerificationTest);
}

void CoreTools::CopyFileToolsTesting
	::CopyFileTest()
{
	CopyFileTools tools{ g_CFileManagerHelpFileName,g_CopyFileName };
}

void CoreTools::CopyFileToolsTesting
	::VerificationTest()
{
	IFStreamManager manager{ g_CopyFileName };

	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(manager.GetFileContent(), g_CFileManagerHelpContent);
}

void CoreTools::CopyFileToolsTesting
	::DeleteFileTest()
{
	DeleteFileTools tools{ g_CopyFileName };
}

