// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:38)

#include "DeleteFileToolsTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/CWriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace CoreTools
{
	const auto g_DeleteFileName = SYSTEM_TEXT("Resource/DeleteTestingText.txt"s);
}
#include STSTEM_WARNING_POP
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DeleteFileToolsTesting)

void CoreTools::DeleteFileToolsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileSucceedTest);
}

void CoreTools::DeleteFileToolsTesting
	::DeleteFileSucceedTest()
{
	{
		CWriteFileManager manager(g_DeleteFileName);
	}

	DeleteFileTools deleteFileTools(g_DeleteFileName);
}

