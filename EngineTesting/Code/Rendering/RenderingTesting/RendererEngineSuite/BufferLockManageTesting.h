///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:39)

#ifndef RENDERING_RENDERERS_SUITE_BUFFER_LOCK_MANAGE_TESTING_H
#define RENDERING_RENDERERS_SUITE_BUFFER_LOCK_MANAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class BufferLockManageTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BufferLockManageTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferLockManageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_BUFFER_LOCK_MANAGE_TESTING_H