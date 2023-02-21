///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/18 18:15)

#ifndef CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class HashCombineTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = HashCombineTesting;
        using ParentType = UnitTest;

    public:
        explicit HashCombineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void HashCombineTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H