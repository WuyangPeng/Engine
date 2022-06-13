///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class ObjectRegisterTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ObjectRegisterTesting);

    private:
        void MainTest();
        void UniqueIDExceptionTest() noexcept;
        void RegisterRootSucceedTest() noexcept;
        void RegisterObjectPtrSucceedTest() noexcept;
        void RegisterObjectPtrArraySucceedTest() noexcept;
        void RegisterObjectSmartPtrSucceedTest() noexcept;
        void RegisterObjectSmartPtrArraySucceedTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H