///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:55)

#include "CommandAddSharedStringsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddSharedStrings.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CommandAddSharedStringsTesting::CommandAddSharedStringsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandAddSharedStringsTesting)

void CoreTools::CommandAddSharedStringsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandAddSharedStringsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CommandAddSharedStringsTest);
}

void CoreTools::CommandAddSharedStringsTesting::CommandAddSharedStringsTest() noexcept
{
    SimpleCSV::CommandAddSharedStrings commandAddSharedStrings{};
}
