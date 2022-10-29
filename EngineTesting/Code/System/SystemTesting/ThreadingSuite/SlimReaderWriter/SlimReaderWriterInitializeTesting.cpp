///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 21:59)

#include "SlimReaderWriterInitializeTesting.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SlimReaderWriterInitializeTesting::SlimReaderWriterInitializeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
