///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/17 22:52)

#ifndef RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H
#define RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class BufferManagementLockEncapsulationTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferManagementLockEncapsulationTesting);

    private:
        void MainTest();
        void VertexBufferTest() noexcept;
        void IndexBufferTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H