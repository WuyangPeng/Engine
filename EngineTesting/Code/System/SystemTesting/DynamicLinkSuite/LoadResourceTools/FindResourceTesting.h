///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:01)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H

#include "ResourceTestingBase.h"

namespace System
{
    class FindResourceTesting final : public ResourceTestingBase
    {
    public:
        using ClassType = FindResourceTesting;
        using ParentType = ResourceTestingBase;

    public:
        explicit FindResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FindResourceTest();
        void FindResourceUseLanguageTest();

        void DoFindResourceTest(const DynamicLinkCharType* type, WindowsWord name);
        void DoFindResourceUseLanguageTest(const DynamicLinkCharType* type, WindowsWord name);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H