/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/13 09:41)

#include "SmtpTransportTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Framework/Smtp/SmtpTransport.h"

Framework::SmtpTransportTesting::SmtpTransportTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SmtpTransportTesting)

void Framework::SmtpTransportTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::SmtpTransportTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SmtpTransportTest);
}

void Framework::SmtpTransportTesting::SmtpTransportTest()
{
    SmtpTransport smtpTransport{ EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    smtpTransport.SendMailMessage("TEST", "TEST1");
}
