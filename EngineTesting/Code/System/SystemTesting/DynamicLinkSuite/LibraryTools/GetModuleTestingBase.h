///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:59)

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
        NODISCARD static DynamicLinkString GetResourcesLibraryName();
        NODISCARD static DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        NODISCARD static DynamicLinkString GetResource();
        NODISCARD static DynamicLinkString GetResourcesLibrary();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_TESTING_BASE_H