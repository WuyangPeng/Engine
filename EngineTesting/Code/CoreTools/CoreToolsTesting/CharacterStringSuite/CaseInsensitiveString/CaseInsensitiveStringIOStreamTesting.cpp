/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 21:15)

#include "CaseInsensitiveStringIOStreamTesting.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "CoreTools/CharacterString/StringUtility.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(WStreamTest);
}

void CoreTools::CaseInsensitiveStringIOStreamTesting::StreamTest()
{
    const CaseInsensitiveString string0{ "stRinG" };
    GetStream() << string0 << '\n';
}

void CoreTools::CaseInsensitiveStringIOStreamTesting::WStreamTest()
{
    const CaseInsensitiveWString string1{ L"STRiNG" };
    GetStream() << string1 << '\n';
}