///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/28 16:53)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_BASE_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_SECURITY_BASE_TESTING_BASE_H

#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Security/Using/SecuritySidUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SecurityBaseTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityBaseTestingBase;
        using ParentType = UnitTest;

    public:
        explicit SecurityBaseTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::vector<char>;

    protected:
        NODISCARD WindowsHandle OpenProcessToken();
        NODISCARD WindowsDWord GetBufferLength(WindowsHandle tokenHandle, TokenInformationClass tokenInformation);
        void CloseTokenTest(WindowsHandle tokenHandle);
        NODISCARD SecuritySID GetSecuritySID();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_BASE_TESTING_BASE_H