///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:45)

#ifndef RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_TESTING_H
#define RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class BufferManagementTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BufferManagementTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferManagementTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void VertexBufferTest() noexcept;
        void IndexBufferTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_TESTING_H