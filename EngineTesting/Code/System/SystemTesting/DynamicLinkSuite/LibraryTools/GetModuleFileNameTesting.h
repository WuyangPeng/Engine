///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/09 13:55)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_FILE_NAME_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_FILE_NAME_TESTING_H

#include "GetModuleTestingBase.h"

namespace System
{
    class GetModuleFileNameTesting final : public GetModuleTestingBase
    {
    public:
        using ClassType = GetModuleFileNameTesting;
        using ParentType = GetModuleTestingBase;

    public:
        explicit GetModuleFileNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetModuleFileNameSucceedTest();
        void DoGetModuleFileNameSucceedTest(DynamicLinkModule libraryModule);
        NODISCARD DynamicLinkString GetDynamicLinkFileNameTest(DynamicLinkModule libraryModule);
        void DllModuleFileNameTest(WindowsDWord maxFileNameLength, DynamicLinkModule libraryModule, const DynamicLinkString& dllModuleFileName);

        void GetModuleFileNameFailureTest();
        void DllModuleFileNameFailureTest(WindowsDWord maxFileNameLength, DynamicLinkModule libraryModule, const BufferType& moduleFileName);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_FILE_NAME_TESTING_H