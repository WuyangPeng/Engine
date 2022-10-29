///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/02 0:36)

#ifndef RENDERING_STATE_SUITE_DRAWING_STATE_TESTING_H
#define RENDERING_STATE_SUITE_DRAWING_STATE_TESTING_H

#include "Detail/DrawingStateTest.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"

namespace Rendering
{
    class DrawingStateTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = DrawingStateTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit DrawingStateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();
        void StreamCreateExceptionTest();

        void DrawingStateTrueTest(GraphicsObjectType type);
        void DrawingStateExceptionTest(GraphicsObjectType type);

        void LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer);

        NODISCARD int GetCorrectIndex(const DrawingStateTest& drawingStateTest) const;

        NODISCARD GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const override;
    };
}

#endif  // RENDERING_STATE_SUITE_DRAWING_STATE_TESTING_H