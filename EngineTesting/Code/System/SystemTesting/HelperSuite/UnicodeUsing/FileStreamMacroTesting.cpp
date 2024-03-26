/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:22)

#include "FileStreamMacroTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <fstream>

System::FileStreamMacroTesting::FileStreamMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    FileStream testFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroFStreamTest.txt" };
    OFileStream testOStream{ "Resource/UnicodeMacroTesting/UnicodeMacroOFStreamTest.txt" };
    IFileStream testIStream{ "Resource/UnicodeMacroTesting/UnicodeMacroIFStreamTest.txt" };

    ASSERT_TRUE(testFStream && testOStream && testIStream);
}
