///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:02)

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