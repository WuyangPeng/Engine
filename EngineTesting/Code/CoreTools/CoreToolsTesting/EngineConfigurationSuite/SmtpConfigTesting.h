/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 16:09)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_SMTP_CONFIG_TESTING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_SMTP_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SmtpConfigTesting final : public UnitTest
    {
    public:
        using ClassType = SmtpConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit SmtpConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SmtpConfigTest();
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_SUITE_SMTP_CONFIG_TESTING_H