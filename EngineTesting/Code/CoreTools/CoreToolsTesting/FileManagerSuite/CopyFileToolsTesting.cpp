///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 12:00)

#include "CopyFileToolsTesting.h"
#include "CoreTools/FileManager/CopyFileTools.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

System::String CoreTools::CopyFileToolsTesting::GetCopyFileName()
{
    return SYSTEM_TEXT("Resource/CopyFile.txt"s);
}

CoreTools::CopyFileToolsTesting::CopyFileToolsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyFileToolsTesting)

void CoreTools::CopyFileToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyFileToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VerificationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
    ASSERT_THROW_EXCEPTION_0(VerificationTest);
}

void CoreTools::CopyFileToolsTesting::CopyFileTest()
{
    const auto cFileManagerHelpFileName = SYSTEM_TEXT("Resource/CFileManagerTesting/CFileManagerHelperTestingText.txt"s);

    CopyFileTools tools{ cFileManagerHelpFileName, GetCopyFileName() };
}

void CoreTools::CopyFileToolsTesting::VerificationTest()
{
    const auto cFileManagerHelpContent = SYSTEM_TEXT("CFileManagerHelper Testing Text"s);
    IFStreamManager manager{ GetCopyFileName() };

    ASSERT_EQUAL(manager.GetFileContent(), cFileManagerHelpContent);
}

void CoreTools::CopyFileToolsTesting::DeleteFileTest()
{
    DeleteFileTools tools{ GetCopyFileName() };
}
