/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.1 (2024/09/13 09:40)

#ifndef FRAMEWORK_SMTP_SUITE_SMTP_TRANSPORT_TESTING_H
#define FRAMEWORK_SMTP_SUITE_SMTP_TRANSPORT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class SmtpTransportTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SmtpTransportTesting;
        using ParentType = UnitTest;

    public:
        explicit SmtpTransportTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SmtpTransportTest();
    };
}

#endif  // FRAMEWORK_SMTP_SUITE_SMTP_TRANSPORT_TESTING_H