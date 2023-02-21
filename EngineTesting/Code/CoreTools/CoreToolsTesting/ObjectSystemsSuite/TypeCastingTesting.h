///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TYPE_CASTING_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TYPE_CASTING_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TypeCastingTesting : public UnitTest
    {
    public:
        using ClassType = TypeCastingTesting;
        using ParentType = UnitTest;

    public:
        explicit TypeCastingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void StaticCastSucceedTest() noexcept;
        void DynamicCastSucceedTest() noexcept;
        void PolymorphicCastSucceedTest() noexcept;
        void ExceptionTest() noexcept;

        void SharedPtrDynamicCastSucceedTest() noexcept;
        void SharedPtrPolymorphicCastSucceedTest() noexcept;
        void SharedPtrExceptionTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TYPE_CASTING_TESTING_H