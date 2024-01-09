/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 23:45)

#ifndef DATABASE_GENERATE_TESTING_DATABASE_GENERATE_SUITE_DATABASE_GENERATE_MESSAGE_TESTING_H
#define DATABASE_GENERATE_TESTING_DATABASE_GENERATE_SUITE_DATABASE_GENERATE_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateTesting
{
    class DatabaseGenerateMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseGenerateMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseGenerateMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // DATABASE_GENERATE_TESTING_DATABASE_GENERATE_SUITE_DATABASE_GENERATE_MESSAGE_TESTING_H
