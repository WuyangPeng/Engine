/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/11 19:17)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_H

#include "GraphicsObjectTestingBase.h"
#include "Detail/GraphicsObjectTest.h"

namespace Rendering
{
    class GraphicsObjectTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = GraphicsObjectTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit GraphicsObjectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AccessTest();

        void BufferTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest);
        void TextureTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest);
        void TextureArrayTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest);
        void ShaderTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest);
        void DrawingStateTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest);

        NODISCARD GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const override;
    };
}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_H