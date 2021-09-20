///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/04 11:04)

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