/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:01)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_LESS_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_LESS_TESTING_H

#include "CoreTools/MessageEvent/MessageEventFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TelegramLessTesting final : public UnitTest
    {
    public:
        using ClassType = TelegramLessTesting;
        using ParentType = UnitTest;

    public:
        explicit TelegramLessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType = TelegramLess<int>;
        using TelegramType = Telegram<int>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LessTest();

        void Less0Test(const TelegramType& lhs, const TelegramType& rhs);
        void Less1Test(const TelegramType& lhs, const TelegramType& rhs);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_LESS_TESTING_H