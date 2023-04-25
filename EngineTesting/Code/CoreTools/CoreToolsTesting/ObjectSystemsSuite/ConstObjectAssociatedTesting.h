﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/20 15:17)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONST_OBJECT_ASSOCIATED_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONST_OBJECT_ASSOCIATED_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConstObjectAssociatedTesting final : public UnitTest
    {
    public:
        using ClassType = ConstObjectAssociatedTesting;
        using ParentType = UnitTest;

    public:
        explicit ConstObjectAssociatedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConstObjectAssociatedTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONST_OBJECT_ASSOCIATED_TESTING_H