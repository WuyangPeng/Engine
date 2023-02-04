///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/25 20:53)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_FILE_PRIVATE_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_CREATE_FILE_PRIVATE_OBJECT_SECURITY_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class CreateFilePrivateObjectSecurityTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = CreateFilePrivateObjectSecurityTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit CreateFilePrivateObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreatePrivateObjectSecurityTest();

        void DoCreatePrivateObjectSecurityTest(WindowsHandle tokenHandle);
        void CreateSecurityTest(SecurityRequestedInformation securityRequestedInformation, WindowsHandle tokenHandle);
        void SetSystemFileSecurityTest(SecurityRequestedInformation securityRequestedInformation, SecurityDescriptorPtr descriptor);

        NODISCARD BufferType GetSystemFileSecurityTest(SecurityRequestedInformation securityRequestedInformation);

    private:
        String existingFileName;
        String setFileName;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_FILE_PRIVATE_OBJECT_SECURITY_TESTING_H