///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 14:32)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ObjectRegisterTesting final : public UnitTest
    {
    public:
        using ClassType = ObjectRegisterTesting;
        using ParentType = UnitTest;

    public:
        explicit ObjectRegisterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void UniqueIdExceptionTest();
        void RegisterRootSucceedTest();
        void RegisterObjectSucceedTest();
        void RegisterWeakObjectSucceedTest();
        void RegisterObjectContainerSucceedTest();
        void RegisterObjectArraySucceedTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H