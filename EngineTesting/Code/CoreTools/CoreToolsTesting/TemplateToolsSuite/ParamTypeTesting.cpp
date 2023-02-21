///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:03)

#include "ParamTypeTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;
using namespace std::literals;

CoreTools::ParamTypeTesting::ParamTypeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ParamTypeTesting)

void CoreTools::ParamTypeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ParamTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ParamTypeTest, 0, ""s);
}

void CoreTools::ParamTypeTesting::ParamTypeTest(MAYBE_UNUSED ParamType<int>::type integer, MAYBE_UNUSED ParamType<string>::type characterString) noexcept
{
}
