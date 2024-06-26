///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:46)

#ifndef RENDERING_RENDERERS_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H
#define RENDERING_RENDERERS_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class VertexFormatManagementTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = VertexFormatManagementTesting;
        using ParentType = UnitTest;

    public:
        explicit VertexFormatManagementTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void VertexFormatTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H