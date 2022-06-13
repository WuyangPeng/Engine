///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:21)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class TelegramTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TelegramTesting);

    private:
        void MainTest();

        void TelegramTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_TELEGRAM_TESTING_H