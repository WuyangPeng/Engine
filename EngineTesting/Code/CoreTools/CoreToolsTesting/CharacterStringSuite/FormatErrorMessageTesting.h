/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 14:39)

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
        void DoRunUnitTest() override;
        void MainTest();

        void SucceedMessageTest();
        void FindFileErrorTest();
        void PlaceholderErrorTest();
        void NetworkErrorTest();
        void ComErrorTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H
