///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 12:00)

#include "OFStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::ostream;
using namespace std::literals;

System::String CoreTools::OFStreamManagerTesting::GetOFStreamFileName()
{
    return SYSTEM_TEXT("Resource/StreamManagerTesting/OFStreamManagerTest.txt"s);
}

System::String CoreTools::OFStreamManagerTesting::GetOFStreamFileContent()
{
    return SYSTEM_TEXT("OFStreamManagerTest test text"s);
}

CoreTools::OFStreamManagerTesting::OFStreamManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OFStreamManagerTesting)

void CoreTools::OFStreamManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::OFStreamManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OFStreamManagerMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OFStreamManagerSizeTest);
}

void CoreTools::OFStreamManagerTesting::OFStreamManagerMessageTest()
{
    OFStreamManager manager{ GetOFStreamFileName(), false };

    manager.SetSimplifiedChinese();
    manager << GetOFStreamFileContent();
}

void CoreTools::OFStreamManagerTesting::OFStreamManagerSizeTest()
{
    const auto ofStreamFileContent = GetOFStreamFileContent();
    OFStreamManager manager{ GetOFStreamFileName(), true };

    manager.SetSimplifiedChinese();
    auto fileSize = manager.GetOFStreamSize();
    const auto contentSize = ofStreamFileContent.size();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize));

    manager << SYSTEM_TEXT(" ") << ofStreamFileContent;
    fileSize = manager.GetOFStreamSize();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize) * 2 + 1);
}
