///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:28)

#include "OStreamSharedTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::OStreamSharedTesting::OStreamSharedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OStreamSharedTesting)

void CoreTools::OStreamSharedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::OStreamSharedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CoutTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CerrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileToolsTest);
}

void CoreTools::OStreamSharedTesting::CoutTest()
{
    OStreamShared oStreamShared{ true };

    ASSERT_TRUE(oStreamShared.IsCout());
    ASSERT_FALSE(oStreamShared.IsCerr());
    ASSERT_FALSE(oStreamShared.IsFile());

    oStreamShared << "这里打印测试文本。\n";

    oStreamShared.GetStream() << "这里打印测试文本。\n";
}

void CoreTools::OStreamSharedTesting::CerrTest()
{
    OStreamShared oStreamShared{ false };

    ASSERT_FALSE(oStreamShared.IsCout());
    ASSERT_TRUE(oStreamShared.IsCerr());
    ASSERT_FALSE(oStreamShared.IsFile());

    oStreamShared << "这里打印测试文本。\n";

    oStreamShared.GetStream() << "这里打印测试文本。\n";
}

void CoreTools::OStreamSharedTesting::FileTest()
{
    OStreamShared oStreamShared{ "Resource/OStreamSharedTesting.txt"s };

    ASSERT_FALSE(oStreamShared.IsCout());
    ASSERT_FALSE(oStreamShared.IsCerr());
    ASSERT_TRUE(oStreamShared.IsFile());

    oStreamShared << "这里打印测试文本。\n";

    oStreamShared.GetStream() << "这里打印测试文本。\n";
}

void CoreTools::OStreamSharedTesting::DeleteFileToolsTest()
{
    DeleteFileTools deleteFileTools{ SYSTEM_TEXT("Resource/OStreamSharedTesting.txt") };
}
