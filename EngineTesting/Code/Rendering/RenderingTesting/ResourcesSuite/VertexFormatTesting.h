///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:37)

#ifndef RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H
#define RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class VertexFormatTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = VertexFormatTesting;
        using ParentType = UnitTest;

    public:
        explicit VertexFormatTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void BaseTest() noexcept;
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H