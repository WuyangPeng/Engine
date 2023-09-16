///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:07)

#include "OpenFileMappingTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/MemoryTools/ViewOfFile.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenFileMappingTesting::OpenFileMappingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenFileMappingTesting)

void System::OpenFileMappingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenFileMappingTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::OpenFileMappingTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_0(OpenFileMappingTest);

    return true;
}

void System::OpenFileMappingTesting::OpenFileMappingTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoOpenFileMappingTest, index);
    }
}

void System::OpenFileMappingTesting::DoOpenFileMappingTest(size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    const auto fileHandle = CreateSystemFile(GetFileMappingName(),
                                             GetMapping(memoryProtect),
                                             FileHandleShareMode::Prevents,
                                             FileHandleCreationDisposition::OpenAlways);
    ASSERT_TRUE_FAILURE_THROW(IsFileHandleValid(fileHandle), "CreateSystemFile 失败");

    ASSERT_NOT_THROW_EXCEPTION_2(FileMappingTest, index, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileTest, fileHandle);
}

void System::OpenFileMappingTesting::FileMappingTest(size_t index, WindowsHandle fileHandle)
{
    const auto loopTestFileName = GetLoopTestFileName();

    const auto memoryProtect = GetMemoryProtect(index);
    const auto fileMapProtection = GetFileMapProtection(index);

    const auto fileMappingHandle = CreateSystemFileMapping(fileHandle, memoryProtect, fileMapProtection, 0, GetMaximumSizeLow(), loopTestFileName.c_str(), nullptr);
    ASSERT_UNEQUAL_NULL_PTR(fileMappingHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(FileMappingOpenTest, index);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileMappingTest, fileMappingHandle);
}

void System::OpenFileMappingTesting::FileMappingOpenTest(size_t index)
{
    const auto fileMapDesiredAccess = GetFileMapDesiredAccess(index);
    const auto loopTestFileName = GetLoopTestFileName();
    const auto openFileMappingHandle = OpenSystemFileMapping(fileMapDesiredAccess, true, loopTestFileName.c_str());
    ASSERT_UNEQUAL_NULL_PTR(openFileMappingHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileMappingTest, openFileMappingHandle);
}
