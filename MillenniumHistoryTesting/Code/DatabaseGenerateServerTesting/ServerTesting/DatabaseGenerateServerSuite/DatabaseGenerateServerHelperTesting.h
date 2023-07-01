///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 22:01)

#ifndef DATABASE_GENERATE_SERVER_TESTING_DATABASE_GENERATE_SERVER_SUITE_DATABASE_GENERATE_SERVER_HELPER_TESTING_H
#define DATABASE_GENERATE_SERVER_TESTING_DATABASE_GENERATE_SERVER_SUITE_DATABASE_GENERATE_SERVER_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerTesting
{
    class DatabaseGenerateServerHelperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseGenerateServerHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseGenerateServerHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // DATABASE_GENERATE_SERVER_TESTING_DATABASE_GENERATE_SERVER_SUITE_DATABASE_GENERATE_SERVER_HELPER_TESTING_H
