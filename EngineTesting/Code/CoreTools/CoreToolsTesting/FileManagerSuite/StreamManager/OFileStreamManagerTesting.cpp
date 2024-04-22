/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 17:19)

#include "OFileStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::String CoreTools::OFileStreamManagerTesting::GetOFileStreamFileName()
{
    return SYSTEM_TEXT("Resource/StreamManagerTesting/OFileStreamManagerTest.txt");
}

System::String CoreTools::OFileStreamManagerTesting::GetOFileStreamFileContent()
{
    return SYSTEM_TEXT("OFileStreamManagerTest test text");
}

CoreTools::OFileStreamManagerTesting::OFileStreamManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OFileStreamManagerTesting)

void CoreTools::OFileStreamManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::OFileStreamManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OFileStreamManagerMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OFileStreamManagerSizeTest);
}

void CoreTools::OFileStreamManagerTesting::OFileStreamManagerMessageTest()
{
    OFileStreamManager manager{ GetOFileStreamFileName(), false };

    manager.SetSimplifiedChinese();
    manager << GetOFileStreamFileContent();
}

void CoreTools::OFileStreamManagerTesting::OFileStreamManagerSizeTest()
{
    const auto ofStreamFileContent = GetOFileStreamFileContent();
    OFileStreamManager manager{ GetOFileStreamFileName(), true };

    manager.SetSimplifiedChinese();
    auto fileSize = manager.GetStreamSize();
    const auto contentSize = ofStreamFileContent.size();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize));

    manager << SYSTEM_TEXT(" ") << ofStreamFileContent;
    fileSize = manager.GetStreamSize();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize) * 2 + 1);
}
