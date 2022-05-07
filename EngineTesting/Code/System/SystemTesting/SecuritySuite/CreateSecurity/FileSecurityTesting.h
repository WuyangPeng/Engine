///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/27 19:57)

#ifndef SYSTEM_SECURITY_SUITE_FILE_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_FILE_SECURITY_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class FileSecurityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FileSecurityTesting;
        using ParentType = UnitTest;

    public:
        explicit FileSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FileSecurityTest(); 

    private:
        using SecurityRequestedInformationFlagsCollection = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationFlagsCollection securityRequestedInformationFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_FILE_SECURITY_TESTING_H