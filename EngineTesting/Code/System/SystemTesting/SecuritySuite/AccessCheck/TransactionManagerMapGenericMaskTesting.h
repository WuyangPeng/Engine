///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/27 21:46)

#ifndef SYSTEM_SECURITY_SUITE_TRANSACTION_MANAGER_MAP_GENERIC_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_TRANSACTION_MANAGER_MAP_GENERIC_MASK_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class TransactionManagerMapGenericMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = TransactionManagerMapGenericMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit TransactionManagerMapGenericMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using MaskContainer = std::map<FileHandleDesiredAccess, AccessGenericMask>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TransactionManagerMapGenericMaskTest();

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_TRANSACTION_MANAGER_MAP_GENERIC_MASK_TESTING_H