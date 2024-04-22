/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/18 22:08)

#include "LogFilterManagerTesting.h"
#include "System/Helper/EnumOperator.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using System::operator++;
using namespace std::literals;

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
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("System"s)), LogFilter::System);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("CoreTools"s)), LogFilter::CoreTools);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Mathematics"s)), LogFilter::Mathematics);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Database"s)), LogFilter::Database);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("SoundEffect"s)), LogFilter::SoundEffect);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Script"s)), LogFilter::Script);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Network"s)), LogFilter::Network);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Rendering"s)), LogFilter::Rendering);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Physics"s)), LogFilter::Physics);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Imagics"s)), LogFilter::Imagics);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("ArtificialIntelligence"s)), LogFilter::ArtificialIntelligence);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("UserInterface"s)), LogFilter::UserInterface);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("AssistTools"s)), LogFilter::AssistTools);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Framework"s)), LogFilter::Framework);
    ASSERT_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("User"s)), LogFilter::User);
}
