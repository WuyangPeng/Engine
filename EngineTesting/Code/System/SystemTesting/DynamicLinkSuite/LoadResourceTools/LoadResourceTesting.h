///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 21:55)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TESTING_H

#include "ResourceTestingBase.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
    class LoadResourceTesting final : public ResourceTestingBase
    {
    public:
        using ClassType = LoadResourceTesting;
        using ParentType = ResourceTestingBase;

    public:
        explicit LoadResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadResourceTest();

        void DoLoadResourceTest(const DynamicLinkCharType* type, WindowsWord name);

        NODISCARD DynamicLinkGlobal GetResourceInLibrary(DynamicLinkResource resource);
        void LockResourceInLibraryTest(DynamicLinkGlobal global);
        void SizeofResourceInLibraryTest(DynamicLinkResource resource);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TESTING_H