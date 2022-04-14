// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/09 15:21)

#ifndef RENDERING_RENDERERS_SUITE_BUFFER_LOCK_MANAGE_TESTING_H
#define RENDERING_RENDERERS_SUITE_BUFFER_LOCK_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class BufferLockManageTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferLockManageTesting);

    private:
        void MainTest();
        void VertexBufferTest() noexcept;
        void IndexBufferTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_BUFFER_LOCK_MANAGE_TESTING_H