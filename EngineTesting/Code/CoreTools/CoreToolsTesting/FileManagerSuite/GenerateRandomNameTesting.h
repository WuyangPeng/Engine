///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 19:13)

#ifndef CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H
#define CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class GenerateRandomNameTesting final : public UnitTest
    {
    public:
        using ClassType = GenerateRandomNameTesting;
        using ParentType = UnitTest;

    public:
        explicit GenerateRandomNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StringTest();
        void WStringTest();
        void TStringTest();
    };
}

#endif  // CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H