/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:31)

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
    : ParentType{ stream }, standardHandles{ StandardHandle::Input, StandardHandle::Output, StandardHandle::Error }
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
    for (auto standardHandle : standardHandles)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoHandleTest, standardHandle);
    }
}

void System::ConsoleHandleTesting::DoHandleTest(StandardHandle standardHandle)
{
    if (standardHandle != StandardHandle::Input)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(OutputHandleTest, standardHandle);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(InputHandleTest, standardHandle);
    }
}

void System::ConsoleHandleTesting::OutputHandleTest(StandardHandle standardHandle)
{
    const auto outputFileName = SYSTEM_TEXT("Resource/ConsoleHandleTesting/OutputHandleTest.txt"s);
    StandardHandleTest(standardHandle, outputFileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents);
}

void System::ConsoleHandleTesting::InputHandleTest(StandardHandle standardHandle)
{
    const auto inputFileName = SYSTEM_TEXT("Resource/ConsoleHandleTesting/InputHandleTest.txt"s);
    StandardHandleTest(standardHandle, inputFileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead);
}

void System::ConsoleHandleTesting::StandardHandleTest(StandardHandle standardHandle, const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode)
{
    const auto handle = CreateSystemFile(fileName, access, shareMode, FileHandleCreationDisposition::OpenAlways);
    ASSERT_TRUE(IsFileHandleValid(handle));

    ASSERT_NOT_THROW_EXCEPTION_2(SetStandardHandleTest, standardHandle, handle);

    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::ConsoleHandleTesting::SetStandardHandleTest(StandardHandle standardHandle, WindowsHandle windowsHandle)
{
    const auto defaultHandle = GetStandardHandle(standardHandle);
    ASSERT_TRUE(IsHandleValid(defaultHandle));

    ASSERT_TRUE(SetStandardHandle(standardHandle, windowsHandle));
    ASSERT_EQUAL(windowsHandle, GetStandardHandle(standardHandle));

    ASSERT_NOT_THROW_EXCEPTION_3(PreviousHandleTest, standardHandle, defaultHandle, windowsHandle);
}

void System::ConsoleHandleTesting::PreviousHandleTest(StandardHandle standardHandle, WindowsHandle defaultHandle, WindowsHandle windowsHandle)
{
    WindowsHandle previousHandle{ nullptr };

    ASSERT_TRUE(SetStandardHandle(standardHandle, defaultHandle, &previousHandle));

    ASSERT_EQUAL(previousHandle, windowsHandle);
}
