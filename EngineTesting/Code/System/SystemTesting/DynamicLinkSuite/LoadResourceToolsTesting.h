/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。

/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:20)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LoadResourceToolsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadResourceToolsTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadResourceToolsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void LoadTestingLibrary();

        NODISCARD static String GetResourcesLibrary();
        void FreeTestingLibrary();
        NODISCARD DynamicLinkModule GetDllModule() const noexcept;

    private:
        DynamicLinkModule dllModule;
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H