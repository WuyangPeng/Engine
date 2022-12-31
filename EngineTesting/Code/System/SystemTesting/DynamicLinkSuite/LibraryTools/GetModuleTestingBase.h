///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 14:48)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_TESTING_BASE_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_TESTING_BASE_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace System
{
    class GetModuleTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetModuleTestingBase;
        using ParentType = UnitTest;

    public:
        explicit GetModuleTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::array<DynamicLinkCharType, gMaxPath>;

    protected:
        NODISCARD DynamicLinkString GetResourcesLibraryName();
        NODISCARD DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        NODISCARD static DynamicLinkString GetResource();
        NODISCARD static DynamicLinkString GetResourcesLibrary();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_TESTING_BASE_H