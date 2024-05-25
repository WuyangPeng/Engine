/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:01)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_MESSAGE_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_MESSAGE_MANAGER_TESTING_H

#include "Detail/Entity.h"
#include "CoreTools/MessageEvent/MessageEventFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TelegramMessageManagerTesting final : public UnitTest
    {
    public:
        using ClassType = TelegramMessageManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit TelegramMessageManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TelegramType = Telegram<int>;
        using TelegramMessageManagerType = TelegramMessageManager<int>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AllEventTest();
        void SpecifiedEventTest();

        NODISCARD static TelegramType GetTelegram();
        void CallEventTest(TelegramMessageManagerType& telegramMessageManager, const TelegramType& telegram) const;
        void DoAllEventTest(const Entity& entity, const TelegramType& telegram, TelegramMessageManagerType& telegramMessageManager);
        void DoCallEvent0Test(const Entity& entity, TelegramMessageManagerType& telegramMessageManager);
        void DoCallEvent1Test(const Entity& entity, const TelegramType& telegram0, TelegramMessageManagerType& telegramMessageManager);
        void DispatchDelayEventTest(const Entity& entity, TelegramMessageManagerType& telegramMessageManager);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_MESSAGE_MANAGER_TESTING_H