///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/30 14:01)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FormatErrorMessageTesting final : public UnitTest
    {
    public:
        using ClassType = FormatErrorMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatErrorMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SucceedMessageTest();
        void FindFileErrorTest();
        void PlaceholderErrorTest();
        void NetworkErrorTest();
        void ComErrorTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H
