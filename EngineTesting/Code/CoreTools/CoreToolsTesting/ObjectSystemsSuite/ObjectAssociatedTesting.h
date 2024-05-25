/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:52)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_OBJECT_ASSOCIATED_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_OBJECT_ASSOCIATED_TESTING_H

#include "Detail/BoolObject.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectAssociatedTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectAssociatedTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectAssociatedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ObjectAssociated = ObjectAssociated<Object>;

        static constexpr auto associated = 9;
        static constexpr auto uniqueId = 5;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ObjectAssociatedTest();

        void ObjectAssociated0Test();
        void ObjectAssociated1Test(const BoolObjectSharedPtr& boolObject);
        void ObjectAssociated2Test(const BoolObjectSharedPtr& boolObject, const ObjectAssociated& objectAssociated);
        void ObjectAssociated3Test(const ObjectAssociated& objectAssociated);
        void ObjectAssociated4Test();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_OBJECT_ASSOCIATED_TESTING_H