///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 0:22)

#include "FileStreamMacroTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <fstream>

using namespace std::literals;

System::FileStreamMacroTesting::FileStreamMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileStreamMacroTesting)

void System::FileStreamMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileStreamMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileStreamMacroTest);
}

void System::FileStreamMacroTesting::FileStreamMacroTest()
{
    FileStream testFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroFStreamTest.txt"s };
    OFileStream testOFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroOFStreamTest.txt"s };
    IFileStream testIFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroIFStreamTest.txt"s };

    ASSERT_TRUE(testFStream && testOFStream && testIFStream);
}
