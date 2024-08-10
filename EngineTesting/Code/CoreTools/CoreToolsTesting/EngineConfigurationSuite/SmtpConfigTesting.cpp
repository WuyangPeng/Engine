/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 16:11)

#include "SmtpConfigTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/EngineConfiguration/SmtpConfig.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SmtpConfigTesting::SmtpConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SmtpConfigTesting)

void CoreTools::SmtpConfigTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::SmtpConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SmtpConfigTest);
}

void CoreTools::SmtpConfigTesting::SmtpConfigTest()
{
    const auto jsonBase = JSON_ANALYSIS_MANAGER_SINGLETON.Create("Configuration/SmtpConfig.json", SmtpConfig::GetCurrentRttiType().GetName());

    const auto smtpConfig = boost::polymorphic_pointer_downcast<SmtpConfig>(jsonBase);

    ASSERT_EQUAL(smtpConfig->GetSmtpHost(), SYSTEM_TEXT("smtp.qq.com"));
    ASSERT_FALSE(smtpConfig->GetSmtpSslEnable());
    ASSERT_TRUE(smtpConfig->GetSmtpAuth());
    ASSERT_EQUAL(smtpConfig->GetSendUser(), SYSTEM_TEXT("94458936@qq.com"));
    ASSERT_EQUAL(smtpConfig->GetPassword(), SYSTEM_TEXT("bbbbbbbbbbbbcbbb"));

    const SmtpConfig::ReceiveUserType receiveUserType{ SYSTEM_TEXT("user1@example.com"),
                                                       SYSTEM_TEXT("user2@example.com"),
                                                       SYSTEM_TEXT("user3@example.com") };

    ASSERT_EQUAL(smtpConfig->GetReceiveUser(), receiveUserType);
}
