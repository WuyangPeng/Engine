///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 21:05)

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