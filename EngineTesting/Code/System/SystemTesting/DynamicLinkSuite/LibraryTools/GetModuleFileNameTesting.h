/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:22)

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
        void DoRunUnitTest() override;
        void MainTest();

        void GetModuleFileNameSucceedTest();
        void DoGetModuleFileNameSucceedTest(DynamicLinkModule libraryModule);
        NODISCARD DynamicLinkString GetDynamicLinkFileNameTest(DynamicLinkModule libraryModule);
        void DllModuleFileNameTest(WindowsDWord maxFileNameLength, DynamicLinkModule libraryModule, const DynamicLinkString& dllModuleFileName);

        void GetModuleFileNameFailureTest();
        void DllModuleFileNameFailureTest(WindowsDWord maxFileNameLength, DynamicLinkModule libraryModule, const DynamicLinkCharBufferType& moduleFileName);

        void GetExecutableNameTest();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_FILE_NAME_TESTING_H