///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/29 23:10)

#include "LoadStringTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/System/ResourcesLibrary/resource.h"

#include <array>

using std::array;
using namespace std::literals;

System::LoadStringTesting::LoadStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadStringTesting)

void System::LoadStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);

    // SystemWindowsTesting有dllModule为instance的测试。
}

void System::LoadStringTesting::LoadStringTest()
{
    array<DynamicLinkCharType, g_MaxPath> stringTableValue{};

    const auto maxFileNameLength = LoadStringInLibrary(GetDllModule(), IDS_STRING1, stringTableValue.data(), g_MaxPath);
    DynamicLinkString result{ stringTableValue.data() };
    ASSERT_EQUAL(boost::numeric_cast<int>(result.size()), maxFileNameLength);

    ASSERT_EQUAL(DYNAMIC_LINK_TEXT("TestString"s), result);
}
