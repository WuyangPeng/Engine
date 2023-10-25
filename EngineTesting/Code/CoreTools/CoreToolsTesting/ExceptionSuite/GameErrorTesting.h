///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:29)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TESTING_H
#define CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class GameErrorTesting final : public UnitTest
    {
    public:
        using ClassType = GameErrorTesting;
        using ParentType = UnitTest;

    public:
        explicit GameErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LastErrorTest();
        void ComErrorTest();
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_GAME_ERROR_TESTING_H
