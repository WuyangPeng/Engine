///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 14:08)

#ifndef CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DefaultTestingObjectPtrTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DefaultTestingObjectPtrTesting;
        using ParentType = UnitTest;

    public:
        explicit DefaultTestingObjectPtrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
        void LinkStreamTest();
        void GetStreamingSizeTest(); 
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_TESTING_H