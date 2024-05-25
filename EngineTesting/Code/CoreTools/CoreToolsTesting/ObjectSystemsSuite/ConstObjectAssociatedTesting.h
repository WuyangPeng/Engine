/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 17:58)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONST_OBJECT_ASSOCIATED_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONST_OBJECT_ASSOCIATED_TESTING_H

#include "Detail/BoolObject.h"
#include "CoreTools/ObjectSystems/Object.h"
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
        using TestingType = ConstObjectAssociated<Object>;

        static constexpr auto associated = 9;
        static constexpr auto uniqueId = 5;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConstObjectAssociatedTest();

        void ConstObjectAssociated0Test();
        void ConstObjectAssociated1Test(const BoolObjectSharedPtr& boolObject);
        void ConstObjectAssociated2Test(const BoolObjectSharedPtr& boolObject, const TestingType& constObjectAssociated);
        void ConstObjectAssociated3Test(const TestingType& constObjectAssociated);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONST_OBJECT_ASSOCIATED_TESTING_H