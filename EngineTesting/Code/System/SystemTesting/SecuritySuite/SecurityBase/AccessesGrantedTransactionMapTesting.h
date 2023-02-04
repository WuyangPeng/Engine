///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 0:50)

#ifndef SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TRANSACTION_MAP_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TRANSACTION_MAP_TESTING_H

#include "AccessesGrantedTestingBase.h"

namespace System
{
    class AccessesGrantedTransactionMapTesting final : public AccessesGrantedTestingBase
    {
    public:
        using ClassType = AccessesGrantedTransactionMapTesting;
        using ParentType = AccessesGrantedTestingBase;

    public:
        explicit AccessesGrantedTransactionMapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TransactionMapGenericMaskTest();

        void DoTransactionMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask);

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_TRANSACTION_MAP_TESTING_H