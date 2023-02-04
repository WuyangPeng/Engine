///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/05 22:36)

#include "ViewOfFileTesting.h"
#include "System/MemoryTools/Flags/ViewOfFileFlags.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/ViewOfFile.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::ViewOfFileTesting::ViewOfFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ViewOfFileTesting)

void System::ViewOfFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ViewOfFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ViewOfFileTest);
}

void System::ViewOfFileTesting::ViewOfFileTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        const auto fileMapDesiredAccess = GetFileMapDesiredAccess(index);

        ASSERT_NOT_THROW_EXCEPTION_1(DoViewOfFileTest, fileMapDesiredAccess);
        ASSERT_NOT_THROW_EXCEPTION_1(DoViewOfFileUseBaseAddressTest, fileMapDesiredAccess);
    }
}

void System::ViewOfFileTesting::DoViewOfFileTest(FileMapDesiredAccess fileMapDesiredAccess)
{
    const auto fileMappingHandle = Create();

    auto buffer = MapSystemViewOfFile(fileMappingHandle, fileMapDesiredAccess, 0, 0, 0);
    ASSERT_NOT_THROW_EXCEPTION_1(BufferTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileMappingTest, fileMappingHandle);
}

void System::ViewOfFileTesting::DoViewOfFileUseBaseAddressTest(FileMapDesiredAccess fileMapDesiredAccess)
{
    const auto fileMappingHandle = Create();

    auto buffer = MapSystemViewOfFile(fileMappingHandle, fileMapDesiredAccess, 0, 0, 0, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(BufferTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileMappingTest, fileMappingHandle);
}

System::WindowsHandle System::ViewOfFileTesting::Create()
{
    const auto loopTestFileName = GetLoopTestFileName();

    const auto fileMappingHandle = CreateSystemFileMapping(invalidHandleValue, MemoryProtect::ReadWrite, FileMapProtection::Default, 0, GetMaximumSizeLow(), loopTestFileName.c_str(), nullptr);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(fileMappingHandle, "CreateSystemFileMapping 失败"s);

    return fileMappingHandle;
}

void System::ViewOfFileTesting::BufferTest(WindowsVoidPtr buffer)
{
    ASSERT_UNEQUAL_NULL_PTR(buffer);

    ASSERT_TRUE(FlushSystemViewOfFile(buffer, 0));
    ASSERT_TRUE(UnmapSystemViewOfFile(buffer));
}
