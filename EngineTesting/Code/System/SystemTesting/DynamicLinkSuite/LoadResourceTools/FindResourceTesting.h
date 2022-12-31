///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 21:04)

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
        void DoRunUnitTest() final;
        void MainTest();

        void FindResourceTest();
        void FindResourceUseLanguageTest();

        void DoFindResourceTest(const DynamicLinkCharType* type, WindowsWord name);
        void DoFindResourceUseLanguageTest(const DynamicLinkCharType* type, WindowsWord name);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H