/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:01)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H

#include "CoreTools/MessageEvent/MessageEventFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TelegramTesting final : public UnitTest
    {
    public:
        using ClassType = TelegramTesting;
        using ParentType = UnitTest;

    public:
        explicit TelegramTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType = Telegram<int>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Telegram0Test();
        void Telegram1Test();
        void Telegram2Test();
        void Telegram3Test();
        void Telegram4Test();
        void Telegram5Test();
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H