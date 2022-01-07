///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.6 (2021/11/15 18:28)

#include "JsonRowTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonGenerate.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::vector;
using namespace std::literals;

CoreTools::JsonRowTesting::JsonRowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonRowTesting)

void CoreTools::JsonRowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonRowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(JsonRowTest);
}

void CoreTools::JsonRowTesting::JsonRowTest() noexcept
{
}
