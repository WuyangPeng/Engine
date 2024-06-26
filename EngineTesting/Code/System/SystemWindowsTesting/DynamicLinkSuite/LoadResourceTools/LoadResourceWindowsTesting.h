/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:38)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_WINDOWS_TESTING_H

#include "ResourceWindowsTestingBase.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
    /// @brief 加载资源模块的测试。
    /// 这里只测试dllModule参数为instance的情况。
    /// SystemWindowsTesting有dllModule不为instance时的测试。
    class LoadResourceWindowsTesting final : public ResourceWindowsTestingBase
    {
    public:
        using ClassType = LoadResourceWindowsTesting;
        using ParentType = ResourceWindowsTestingBase;

    public:
        explicit LoadResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

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

#endif  // SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_WINDOWS_TESTING_H