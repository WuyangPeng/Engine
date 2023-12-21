/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/19 09:25)

#ifndef RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_ATTRIBUTE_TESTING_H
#define RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_ATTRIBUTE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class VertexFormatAttributeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VertexFormatAttributeTesting;
        using ParentType = UnitTest;

    public:
        explicit VertexFormatAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void DefaultTest();
        void BaseTest();
        void StreamTest();
    };
}

#endif  // RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_ATTRIBUTE_TESTING_H