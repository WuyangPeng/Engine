///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/27 21:46)

#ifndef SYSTEM_SECURITY_SUITE_TRANSACTION_MAP_GENERIC_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_TRANSACTION_MAP_GENERIC_MASK_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class TransactionMapGenericMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = TransactionMapGenericMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit TransactionMapGenericMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using MaskContainer = std::map<FileHandleDesiredAccess, AccessGenericMask>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void TransactionMapGenericMaskTest();

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_TRANSACTION_MAP_GENERIC_MASK_TESTING_H