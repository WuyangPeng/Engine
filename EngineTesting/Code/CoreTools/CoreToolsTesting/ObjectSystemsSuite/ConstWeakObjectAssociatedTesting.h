/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 18:08)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONST_WEAK_OBJECT_ASSOCIATED_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONST_WEAK_OBJECT_ASSOCIATED_TESTING_H

#include "Detail/BoolObject.h"
#include "CoreTools/ObjectSystems/Object.h"
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
        using TestingType = ConstWeakObjectAssociated<Object>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConstWeakObjectAssociatedTest();

        void ConstWeakObjectAssociated0Test(const BoolObjectSharedPtr& boolObject);
        void ConstWeakObjectAssociated1Test(const BoolObjectSharedPtr& boolObject);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONST_WEAK_OBJECT_ASSOCIATED_TESTING_H