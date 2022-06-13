///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:06)

#include "ConsoleHandleTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::ConsoleHandleTesting::ConsoleHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }, standardHandleFlags{ StandardHandle::Input, StandardHandle::Output, StandardHandle::Error }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleHandleTesting)

void System::ConsoleHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HandleTest);
}

void System::ConsoleHandleTesting::HandleTest()
{
    const auto inputFileName = SYSTEM_TEXT("Resource/ConsoleHandleTesting/InputHandleTest.txt"s);
    const auto outputFileName = SYSTEM_TEXT("Resource/ConsoleHandleTesting/OutputHandleTest.txt"s);

    auto inputHandle = CreateSystemFile(inputFileName.c_str(), FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenAlways);
    ASSERT_TRUE(IsFileHandleValid(inputHandle));

    auto outputHandle = CreateSystemFile(outputFileName.c_str(), FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::OpenAlways);
    ASSERT_TRUE(IsFileHandleValid(outputHandle));

    for (auto flag : standardHandleFlags)
    {
        auto defaultHandle = GetStandardHandle(flag);
        ASSERT_TRUE(IsHandleValid(defaultHandle));

        WindowsHandle previousHandle{ nullptr };

        if (flag != StandardHandle::Input)
        {
            ASSERT_TRUE(SetStandardHandle(flag, outputHandle));
            ASSERT_EQUAL(outputHandle, GetStandardHandle(flag));

            ASSERT_TRUE(SetStandardHandle(flag, defaultHandle, &previousHandle));

            ASSERT_EQUAL(previousHandle, outputHandle);
        }
        else
        {
            ASSERT_TRUE(SetStandardHandle(flag, inputHandle));
            ASSERT_EQUAL(inputHandle, GetStandardHandle(flag));

            ASSERT_TRUE(SetStandardHandle(flag, defaultHandle, &previousHandle));

            ASSERT_EQUAL(previousHandle, inputHandle);
        }
    }

    ASSERT_TRUE(CloseSystemFile(outputHandle));
    ASSERT_TRUE(CloseSystemFile(inputHandle));
}
