/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 15:51)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TYPE_TRAITS_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TYPE_TRAITS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TypeTraitsTesting final : public UnitTest
    {
    public:
        using ClassType = TypeTraitsTesting;
        using ParentType = UnitTest;

    public:
        explicit TypeTraitsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void TypeTraitsTest() noexcept;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TYPE_TRAITS_TESTING_H