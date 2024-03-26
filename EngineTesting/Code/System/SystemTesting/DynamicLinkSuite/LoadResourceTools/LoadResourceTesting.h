/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:20)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TESTING_H

#include "ResourceTestingBase.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
    /// @brief 加载资源模块的测试。
    /// 这里只测试dllModule参数不为instance的情况。
    /// SystemWindowsTesting有dllModule为instance时的测试。
    class LoadResourceTesting final : public ResourceTestingBase
    {
    public:
        using ClassType = LoadResourceTesting;
        using ParentType = ResourceTestingBase;

    public:
        explicit LoadResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadResourceTest();

        void DoLoadResourceTest(const DynamicLinkCharType* type, WindowsWord name);

        NODISCARD DynamicLinkGlobal GetResourceInLibrary(DynamicLinkResource resource);
        void LockResourceInLibraryTest(DynamicLinkGlobal global);
        void SizeofResourceInLibraryTest(DynamicLinkResource resource);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TESTING_H