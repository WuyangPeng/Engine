///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/28 15:49)

#include "CaseInsensitiveStringIOStreamTesting.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CaseInsensitiveStringIOStreamTesting::CaseInsensitiveStringIOStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CaseInsensitiveStringIOStreamTesting)

void CoreTools::CaseInsensitiveStringIOStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CaseInsensitiveStringIOStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void CoreTools::CaseInsensitiveStringIOStreamTesting::StreamTest()
{
    const CaseInsensitiveString string0{ "stRinG" };
    GetStream() << string0 << "\n";

    const CaseInsensitiveWString string1{ L"STRiNG" };
    GetStream() << string1 << "\n";
}
