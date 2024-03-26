/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:24)

#include "CFileSetVBufferTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CFileSetVBufferTesting::CFileSetVBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    ASSERT_TRUE(SetVBuffer(file, FileSetVBuffer::IoFullyBuffered, 512));
}
