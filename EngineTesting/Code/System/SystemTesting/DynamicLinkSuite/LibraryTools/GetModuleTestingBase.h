/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:22)

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
        NODISCARD static DynamicLinkString GetResourcesLibraryName();
        NODISCARD static DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        NODISCARD static DynamicLinkString GetResource();
        NODISCARD static DynamicLinkString GetResourcesLibrary();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_TESTING_BASE_H