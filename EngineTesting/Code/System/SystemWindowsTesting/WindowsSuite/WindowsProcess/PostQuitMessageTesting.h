/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:15)

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
        void DoRunUnitTest() override;
        void MainTest();

        void PostQuitMessageTest() const noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_POST_QUIT_MESSAGE_TESTING_H