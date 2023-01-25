///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/25 16:11)

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
        using SecurityRequestedInformationFlagsContainer = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationFlagsContainer securityRequestedInformationFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_FILE_SECURITY_TESTING_H