/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 00:02)

#ifndef CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_TESTING_H

#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/DefaultTestingNoObjectPtr.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DefaultTestingNoObjectPtrTesting final : public UnitTest
    {
    public:
        using ClassType = DefaultTestingNoObjectPtrTesting;
        using ParentType = UnitTest;

    public:
        explicit DefaultTestingNoObjectPtrTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ConstObjectAssociated = ConstObjectAssociated<DefaultTestingNoObjectPtr>;
        static constexpr auto bufferSize = 256;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SaveStreamTest();
        void LoadStreamTest();
        void LinkStreamTest();
        void GetStreamingSizeTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_DEFAULT_TESTING_NO_OBJECT_PTR_TESTING_H