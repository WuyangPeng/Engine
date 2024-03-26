/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:22)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_HANDLE_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_HANDLE_TESTING_H

#include "GetModuleTestingBase.h"
#include "System/DynamicLink/Flags/GetModuleHandleFlags.h"

namespace System
{
    class GetModuleHandleTesting final : public GetModuleTestingBase
    {
    public:
        using ClassType = GetModuleHandleTesting;
        using ParentType = GetModuleTestingBase;

    public:
        explicit GetModuleHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetModuleHandleSucceed0Test();
        void GetModuleHandleSucceed1Test();
        void GetModuleHandleSucceed2Test();
        void GetModuleHandleSucceed3Test();
        void GetModuleHandleFailureTest();

        void GetHandleUnequalNullPtrTest();
        NODISCARD DynamicLinkModule GetHandleUseTypeUnequalNullPtrTest(GetModuleHandleType getModuleHandleType);
        void GetHandleEqualNullPtrTest();
        void GetHandleUseTypeEqualNullPtrTest(GetModuleHandleType getModuleHandleType);

        NODISCARD DynamicLinkModule GetDynamicLibraryFailureThrow();
        NODISCARD DynamicLinkModule GetHandle(GetModuleHandleType getModuleHandleType);

        NODISCARD static DynamicLinkModule GetHandle();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_MODULE_HANDLE_TESTING_H