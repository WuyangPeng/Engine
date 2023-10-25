///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:12)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONST_WEAK_OBJECT_ASSOCIATED_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONST_WEAK_OBJECT_ASSOCIATED_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConstWeakObjectAssociatedTesting final : public UnitTest
    {
    public:
        using ClassType = ConstWeakObjectAssociatedTesting;
        using ParentType = UnitTest;

    public:
        explicit ConstWeakObjectAssociatedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void ConstWeakObjectAssociatedTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONST_WEAK_OBJECT_ASSOCIATED_TESTING_H