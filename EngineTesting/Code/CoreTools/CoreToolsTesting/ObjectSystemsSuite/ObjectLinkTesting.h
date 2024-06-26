/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:52)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H

#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectLinkTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectLinkTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectLinkTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ObjectLinkSharedPtr = std::shared_ptr<ObjectLink>;
        using ObjectAssociated = ObjectAssociated<Object>;
        using ObjectAssociatedContainer = std::vector<ObjectAssociated>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InsertObjectTest();
        void SortTest();
        void ResolveLinkTest();
        void ResolveLinkContainerTest();

        NODISCARD ObjectLinkSharedPtr CreateObjectLink();
        void BeforeSortTest(const ObjectLink& objectLink);
        void SortResultTest(const ObjectLink& objectLink);

    private:
        BoolObjectSharedPtr boolObject;
        EnumObjectSharedPtr enumObject;
        IntObjectSharedPtr intObject;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H