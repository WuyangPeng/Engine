///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/26 11:09)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_MODULE_FILE_NAME_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_MODULE_FILE_NAME_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetModuleFileNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetModuleFileNameTesting;
        using ParentType = UnitTest;

    public:
        explicit GetModuleFileNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetModuleFileNameSucceedTest();
        void GetModuleFileNameFailureTest();

        NODISCARD DynamicLinkString GetResourcesLibraryName();
        NODISCARD DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        NODISCARD static DynamicLinkString GetResource();
        NODISCARD static DynamicLinkString GetResourcesLibrary();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_MODULE_FILE_NAME_TESTING_H