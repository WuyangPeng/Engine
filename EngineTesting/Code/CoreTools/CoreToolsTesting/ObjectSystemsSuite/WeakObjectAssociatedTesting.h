/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/24 18:11)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_WEAK_OBJECT_ASSOCIATED_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_WEAK_OBJECT_ASSOCIATED_TESTING_H

#include "Detail/BoolObject.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WeakObjectAssociatedTesting final : public UnitTest
    {
    public:
        using ClassType = WeakObjectAssociatedTesting;
        using ParentType = UnitTest;

    public:
        explicit WeakObjectAssociatedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using WeakObjectAssociated = WeakObjectAssociated<Object>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WeakObjectAssociatedTest();

        void WeakObjectAssociated0Test();
        void WeakObjectAssociated1Test(const BoolObjectSharedPtr& boolObject);
        void WeakObjectAssociated2Test(const BoolObjectSharedPtr& boolObject);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_WEAK_OBJECT_ASSOCIATED_TESTING_H