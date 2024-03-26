/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:22)

#include "CreateFileMappingTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/MemoryTools/ViewOfFile.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateFileMappingTesting::CreateFileMappingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileMappingTesting)

void System::CreateFileMappingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileMappingTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(CreateFileMappingRandomShuffle);
}

bool System::CreateFileMappingTesting::CreateFileMappingRandomShuffle()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileMappingTest);

    return true;
}

void System::CreateFileMappingTesting::CreateFileMappingTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateFileMappingTest, index);
    }
}

void System::CreateFileMappingTesting::DoCreateFileMappingTest(size_t index)
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

void System::CreateFileMappingTesting::FileMappingTest(size_t index, WindowsHandle fileHandle)
{
    const auto fileMappingHandle = Create(index, fileHandle, false);

    ASSERT_NOT_THROW_EXCEPTION_2(FileMappingAgainTest, index, fileHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileMappingTest, fileMappingHandle);
}

void System::CreateFileMappingTesting::FileMappingAgainTest(size_t index, WindowsHandle fileHandle)
{
    const auto againFileMappingHandle = Create(index, fileHandle, true);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFileMappingTest, againFileMappingHandle);
}

System::WindowsHandle System::CreateFileMappingTesting::Create(size_t index, WindowsHandle fileHandle, bool isAgain)
{
    const auto memoryProtect = GetMemoryProtect(index);
    const auto fileMapProtection = GetFileMapProtection(index);

    const auto loopTestFileName = GetLoopTestFileName();

    auto isExists = false;

    const auto fileMappingHandle = CreateSystemFileMapping(fileHandle, memoryProtect, fileMapProtection, 0, GetMaximumSizeLow(), loopTestFileName.c_str(), &isExists);
    ASSERT_UNEQUAL_NULL_PTR(fileMappingHandle);
    ASSERT_EQUAL(isExists, isAgain);

    return fileMappingHandle;
}
