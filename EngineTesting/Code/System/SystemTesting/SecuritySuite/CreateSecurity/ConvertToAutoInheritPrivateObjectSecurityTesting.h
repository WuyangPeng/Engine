///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/30 0:24)

#ifndef SYSTEM_SECURITY_SUITE_CONVERT_TO_AUTO_INHERIT_PRIVATE_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_CONVERT_TO_AUTO_INHERIT_PRIVATE_OBJECT_SECURITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConvertToAutoInheritPrivateObjectSecurityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConvertToAutoInheritPrivateObjectSecurityTesting;
        using ParentType = UnitTest;

    public:
        explicit ConvertToAutoInheritPrivateObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConvertToAutoInheritPrivateObjectSecurityTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CONVERT_TO_AUTO_INHERIT_PRIVATE_OBJECT_SECURITY_TESTING_H