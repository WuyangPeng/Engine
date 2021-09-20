///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 11:06)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_POST_QUIT_MESSAGE_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_POST_QUIT_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class PostQuitMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PostQuitMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit PostQuitMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void PostQuitMessageTest() noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_POST_QUIT_MESSAGE_TESTING_H