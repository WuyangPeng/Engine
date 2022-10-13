///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/05 14:28)

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