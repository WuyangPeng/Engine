///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/10 22:49)

#include "LoadStringWindowsTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/SystemWindowsTesting/resource.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using namespace std::literals;

System::LoadStringWindowsTesting::LoadStringWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadStringWindowsTesting)

void System::LoadStringWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadStringWindowsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStringTest);
}

void System::LoadStringWindowsTesting::LoadStringTest()
{
    using BufferType = std::array<DynamicLinkCharType, gMaxPath>;
    BufferType stringTableValue{};

    const auto maxFileNameLength = LoadStringInLibrary(instance, IDS_STRING, stringTableValue.data(), gMaxPath);

    DynamicLinkString result{ stringTableValue.data() };
    ASSERT_EQUAL(boost::numeric_cast<int>(result.size()), maxFileNameLength);

    ASSERT_EQUAL(DYNAMIC_LINK_TEXT("Test"s), result);
}
