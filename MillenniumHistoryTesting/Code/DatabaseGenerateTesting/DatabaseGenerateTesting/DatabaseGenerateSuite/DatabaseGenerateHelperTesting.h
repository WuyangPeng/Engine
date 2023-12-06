/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:53)

#ifndef DATABASE_GENERATE_TESTING_DATABASE_GENERATE_SUITE_DATABASE_GENERATE_HELPER_TESTING_H
#define DATABASE_GENERATE_TESTING_DATABASE_GENERATE_SUITE_DATABASE_GENERATE_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateTesting
{
    class DatabaseGenerateHelperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseGenerateHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseGenerateHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // DATABASE_GENERATE_TESTING_DATABASE_GENERATE_SUITE_DATABASE_GENERATE_HELPER_TESTING_H
