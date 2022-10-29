///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/04 16:52)

#ifndef RENDERING_STATE_SUITE_DEPTH_STENCIL_STATE_TESTING_H
#define RENDERING_STATE_SUITE_DEPTH_STENCIL_STATE_TESTING_H

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class DepthStencilStateTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = DepthStencilStateTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit DepthStencilStateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();
        void StreamCreateExceptionTest();

        void StreamTest();
        void GetStreamingSizeTest();

        void LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer);

        NODISCARD int GetCorrectIndex(const DepthStencilStateSharedPtr& state) const;

        void DepthStencilStateTest();

        void DepthStencilStateValueTest();
        void DepthStencilStateSaveTest();

        void ConstructorTest();
        void SetDepthEnableTest();
        void SetWriteMaskTest();
        void SetComparisonTest();
        void SetStencilEnableTest();
        void SetStencilReadMaskTest();
        void SetStencilWriteMaskTest();
        void SetReferenceTest();

        void SetFrontFaceFailTest();
        void SetFrontFaceDepthFailTest();
        void SetFrontFacePassTest();
        void SetFrontFaceComparisonTest();

        void SetBackFaceFailTest();
        void SetBackFaceDepthFailTest();
        void SetBackFacePassTest();
        void SetBackFaceComparisonTest();

        NODISCARD GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const override;

    private:
        bool depthEnable;
        DepthStencilStateWriteMask writeMask;
        DepthStencilStateComparison comparison;
        bool stencilEnable;
        int stencilReadMask;
        int stencilWriteMask;
        DepthStencilStateFace frontFace;
        DepthStencilStateFace backFace;
        int reference;
        DepthStencilStateSharedPtr depthStencilState;
    };
}

#endif  // RENDERING_STATE_SUITE_DEPTH_STENCIL_STATE_TESTING_H