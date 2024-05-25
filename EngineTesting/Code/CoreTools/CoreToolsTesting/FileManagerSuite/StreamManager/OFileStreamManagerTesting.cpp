/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/03 23:24)

#include "OFileStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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

System::String CoreTools::OFileStreamManagerTesting::GetOFileStreamFileName()
{
    return SYSTEM_TEXT("Resource/StreamManagerTesting/OFileStreamManagerTest.txt");
}

System::String CoreTools::OFileStreamManagerTesting::GetOFileStreamFileContent()
{
    return SYSTEM_TEXT("OFileStreamManagerTest test text");
}

void CoreTools::OFileStreamManagerTesting::OFileStreamManagerMessageTest()
{
    OFileStreamManager manager{ GetOFileStreamFileName(), false };

    manager.SetSimplifiedChinese();
    manager << GetOFileStreamFileContent();
}

void CoreTools::OFileStreamManagerTesting::OFileStreamManagerSizeTest()
{
    const auto fileStreamFileContent = GetOFileStreamFileContent();
    OFileStreamManager manager{ GetOFileStreamFileName(), true };

    manager.SetSimplifiedChinese();

    ASSERT_NOT_THROW_EXCEPTION_2(OriginalSizeTest, manager, fileStreamFileContent);
    ASSERT_NOT_THROW_EXCEPTION_2(ExpansionSizeTest, manager, fileStreamFileContent);
}

void CoreTools::OFileStreamManagerTesting::OriginalSizeTest(const OFileStreamManager& manager, const String& fileStreamFileContent)
{
    const auto fileSize = manager.GetStreamSize();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(fileStreamFileContent.size()));
}

void CoreTools::OFileStreamManagerTesting::ExpansionSizeTest(OFileStreamManager& manager, const String& fileStreamFileContent)
{
    manager << SYSTEM_TEXT(" ") << fileStreamFileContent;
    const auto fileSize = manager.GetStreamSize();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(fileStreamFileContent.size() * 2 + 1));
}
