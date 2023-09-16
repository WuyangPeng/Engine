///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:45)

#include "LoadStringWindowsTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/SystemWindowsTesting/resource.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::LoadStringWindowsTesting::LoadStringWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    const DynamicLinkString result{ stringTableValue.data() };
    ASSERT_EQUAL(boost::numeric_cast<int>(result.size()), maxFileNameLength);

    ASSERT_EQUAL(DYNAMIC_LINK_TEXT("Test"), result);
}
