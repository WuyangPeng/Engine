///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:43)

#ifndef SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class SetPrivateObjectSecurityTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = SetPrivateObjectSecurityTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit SetPrivateObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SetPrivateObjectSecurityTest();

        void DoSetPrivateObjectSecurityTest(WindowsHandle tokenHandle);
        void PrivateObjectSecurityTest(SecurityDescriptorPtr& descriptor, WindowsHandle tokenHandle);
        void DoPrivateObjectSecurityTest(SecurityDescriptorPtr& descriptor, SecurityRequestedInformation securityRequestedInformation, WindowsHandle tokenHandle);
        void SetSystemPrivateObjectSecurityTest(SecurityRequestedInformation securityRequestedInformation, SecurityDescriptorPtr& descriptor, WindowsHandle tokenHandle, BufferType& buffer);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H