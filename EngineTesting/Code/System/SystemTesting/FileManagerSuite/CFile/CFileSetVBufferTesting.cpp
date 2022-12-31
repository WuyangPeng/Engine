///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/12 18:53)

#include "CFileSetVBufferTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

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
    auto file = OpenFile(SYSTEM_FILE_TEXT("r"s));

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetVBufferTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileSetVBufferTesting::DoSetVBufferTest(FILE* file)
{
    ASSERT_TRUE(SetVBuffer(file, FileSetVBuffer::IOFBF, 512));
}
