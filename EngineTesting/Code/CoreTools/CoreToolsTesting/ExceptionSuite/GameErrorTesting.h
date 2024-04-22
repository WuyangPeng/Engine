/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:03)

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
