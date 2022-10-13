///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/05 14:28)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_H

#include "GraphicsObjectTestingBase.h"
#include "Detail/GraphicsObjectTest.h"
#include "Rendering/Base/BaseFwd.h"

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
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();

        void BufferTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest);
        void TextureTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest);
        void TextureArrayTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest);
        void ShaderTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest);
        void DrawingStateTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest);

        void CloneObjectTest();
        void GetObjectByNameTest();
        void IsNullObjectTest();
        void UniqueIDTest();
        void StreamTest();

        void FactoryTest();
        void FactoryExceptionTest();
        void GetStreamingSizeTest();
        void RegisterTest();
        void LinkTest();
        void SaveTest();
    };
}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_H