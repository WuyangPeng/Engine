/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:42)

#ifndef CORE_TOOLS_TESTING_TYPE_ALIAS_TESTING_H
#define CORE_TOOLS_TESTING_TYPE_ALIAS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TypeAliasTesting final : public UnitTest
    {
    public:
        using ClassType = TypeAliasTesting;
        using ParentType = UnitTest;

    public:
        explicit TypeAliasTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TypeAliasTest();
    };
}

#endif  // CORE_TOOLS_TESTING_TYPE_ALIAS_TESTING_H