/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:33)

#include "LoadStringTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/System/ResourcesLibrary/resource.h"

using namespace std::literals;

System::LoadStringTesting::LoadStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadStringTesting)

void System::LoadStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);
}

void System::LoadStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStringTest);
}

void System::LoadStringTesting::LoadStringTest()
{
    DynamicLinkCharBufferType stringTableValue{};

    const auto maxFileNameLength = LoadStringInLibrary(GetDllModule(), IDS_STRING1, stringTableValue.data(), gMaxPath - 1);

    const DynamicLinkString result{ stringTableValue.data() };
    ASSERT_EQUAL(boost::numeric_cast<int>(result.size()), maxFileNameLength);

    ASSERT_EQUAL(DYNAMIC_LINK_TEXT("TestString"s), result);
}
