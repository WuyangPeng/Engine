/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/19 10:04)

#ifndef RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H
#define RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

namespace Rendering
{
    class VertexFormatTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VertexFormatTesting;
        using ParentType = UnitTest;

    public:
        explicit VertexFormatTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void AttributeTest();
        void StreamTest();

        void DoRunUnitTest() override;

    private:
        using AttributeContainer = VertexFormat::AttributeContainer;

    private:
        AttributeContainer attributeContainer;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_VERTEX_FORMAT_TESTING_H