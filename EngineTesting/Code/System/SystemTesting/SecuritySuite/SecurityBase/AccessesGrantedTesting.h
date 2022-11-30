///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:40)

#ifndef SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AccessesGrantedTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AccessesGrantedTesting;
        using ParentType = UnitTest;

    public:
        explicit AccessesGrantedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FileMapGenericMaskTest();
        void TransactionManagerMapGenericMaskTest();
        void TransactionMapGenericMaskTest();
        void ResourceManagerMapGenericMaskTest();
        void EnlistmentMapGenericMaskTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TESTING_H