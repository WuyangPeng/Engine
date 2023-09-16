///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:23)

#include "CFileSetVBufferTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CFileSetVBufferTesting::CFileSetVBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileSetVBufferTesting)

void System::CFileSetVBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileSetVBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetVBufferTest);
}

void System::CFileSetVBufferTesting::SetVBufferTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("r"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetVBufferTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileSetVBufferTesting::DoSetVBufferTest(FILE* file)
{
    ASSERT_TRUE(SetVBuffer(file, FileSetVBuffer::IOFBF, 512));
}
