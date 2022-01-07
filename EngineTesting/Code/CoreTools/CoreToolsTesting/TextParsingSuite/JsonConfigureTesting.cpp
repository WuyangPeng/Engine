///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.6 (2021/11/15 18:28)

#include "JsonConfigureTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonGenerate.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::vector;
using namespace std::literals;

CoreTools::JsonConfigureTesting::JsonConfigureTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonConfigureTesting)

void CoreTools::JsonConfigureTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonConfigureTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonConfigureTest);
}

void CoreTools::JsonConfigureTesting::JsonConfigureTest() noexcept
{
}
