/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 00:02)

#ifndef CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DefaultTestingObjectPtrTesting final : public UnitTest
    {
    public:
        using ClassType = DefaultTestingObjectPtrTesting;
        using ParentType = UnitTest;

    public:
        explicit DefaultTestingObjectPtrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
        void LinkStreamTest();
        void GetStreamingSizeTest();

    private:
        static constexpr auto bufferSize = 256;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_OBJECT_PTR_TESTING_H