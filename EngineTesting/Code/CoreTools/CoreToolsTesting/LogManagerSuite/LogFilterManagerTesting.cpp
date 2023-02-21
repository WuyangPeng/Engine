///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:11)

#include "LogFilterManagerTesting.h"
#include "System/Helper/EnumOperator.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using namespace std::literals;
using System::operator++;

CoreTools::LogFilterManagerTesting::LogFilterManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogFilterManagerTesting)

void CoreTools::LogFilterManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LogFilterManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetLogFilterTypeTest);
}

void CoreTools::LogFilterManagerTesting::ValidTest()
{
    for (auto logFilter = LogFilter::System; logFilter < LogFilter::MaxLogFilter; ++logFilter)
    {
        auto describe = LogFilterManager::GetLogFilterDescribe(logFilter);
        ASSERT_FALSE(describe.empty());
    }
}

void CoreTools::LogFilterManagerTesting::GetLogFilterTypeTest()
{
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("System"s)), LogFilter::System);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("CoreTools"s)), LogFilter::CoreTools);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Mathematics"s)), LogFilter::Mathematics);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Database"s)), LogFilter::Database);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("SoundEffect"s)), LogFilter::SoundEffect);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Script"s)), LogFilter::Script);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Network"s)), LogFilter::Network);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Rendering"s)), LogFilter::Rendering);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Physics"s)), LogFilter::Physics);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Imagics"s)), LogFilter::Imagics);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("ArtificialIntellegence"s)), LogFilter::ArtificialIntellegence);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("UserInterface"s)), LogFilter::UserInterface);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("AssistTools"s)), LogFilter::AssistTools);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Framework"s)), LogFilter::Framework);
    ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("User"s)), LogFilter::User);
}
