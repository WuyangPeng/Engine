///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:10)

#ifndef SYSTEM_SECURITY_SUITE_INITIALIZE_ACL_TESTING_H
#define SYSTEM_SECURITY_SUITE_INITIALIZE_ACL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InitializeAclTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitializeAclTesting;
        using ParentType = UnitTest;

    public:
        explicit InitializeAclTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RevisionInitializeAclTest();
        void RevisionDsInitializeAclTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_INITIALIZE_ACL_TESTING_H