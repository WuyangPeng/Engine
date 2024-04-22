/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 12:12)

#ifndef CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class HashCombineTesting final : public UnitTest
    {
    public:
        using ClassType = HashCombineTesting;
        using ParentType = UnitTest;

    public:
        explicit HashCombineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void HashCombineTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H