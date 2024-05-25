/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:59)

#ifndef CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H

#include "Detail/TestHash.h"
#include "Detail/TestHashKey.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <unordered_map>

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
        using UnorderedMap = std::unordered_map<TestHashKey, int, TestHash>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void HashCombineTest();

        void SizeTest(UnorderedMap& container, const TestHashKey& testHashKey);
        void FindTest(UnorderedMap& container, const TestHashKey& testHashKey);
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_HASH_COMBINE_TESTING_H