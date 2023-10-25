///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:27)

#include "OFStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    auto fileSize = manager.GetStreamSize();
    const auto contentSize = ofStreamFileContent.size();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize));

    manager << SYSTEM_TEXT(" ") << ofStreamFileContent;
    fileSize = manager.GetStreamSize();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize) * 2 + 1);
}
