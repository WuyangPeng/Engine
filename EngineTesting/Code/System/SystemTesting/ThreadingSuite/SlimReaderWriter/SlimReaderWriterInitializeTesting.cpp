///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:21)

#include "SlimReaderWriterInitializeTesting.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SlimReaderWriterInitializeTesting::SlimReaderWriterInitializeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SlimReaderWriterInitializeTesting)

void System::SlimReaderWriterInitializeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SlimReaderWriterInitializeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitializeTest);
}

void System::SlimReaderWriterInitializeTesting::InitializeTest() noexcept
{
    SlimReaderWriterLock slimReaderWriterLock{};
    InitializeSlimReaderWriterLock(&slimReaderWriterLock);
}
