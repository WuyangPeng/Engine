///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/06 0:55)

#ifndef RENDERING_GRAPHICS_RENDERER_H
#define RENDERING_GRAPHICS_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "BaseRenderer.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Base/InputLayoutManager.h"

#include <map>
#include <mutex>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GraphicsRenderer : public BaseRenderer
    {
    public:
        using ClassType = GraphicsRenderer;
        using ParentType = BaseRenderer;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using ConstGraphicsObjectSharedPtr = std::shared_ptr<const GraphicsObject>;
        using RendererDrawTargetSharedPtr = std::shared_ptr<RendererDrawTarget>;
        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;

    public:
        explicit GraphicsRenderer(const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual void ClearColorBuffer() = 0;
        virtual void ClearDepthBuffer() = 0;
        virtual void ClearStencilBuffer() = 0;
        virtual void ClearBuffers() = 0;

        void SetFont(const FontSharedPtr& font) override;

        void Bind(const ConstGraphicsObjectSharedPtr& object);
        void Unbind(const ConstGraphicsObjectSharedPtr& object);

        void Bind(const ConstDrawTargetSharedPtr& object);
        void Unbind(const ConstDrawTargetSharedPtr& object);

    private:
        using RendererObjectContainer = std::map<ConstGraphicsObjectSharedPtr, RendererObjectSharedPtr>;
        using RendererDrawTargetContainer = std::map<ConstDrawTargetSharedPtr, RendererDrawTargetSharedPtr>;
        using InputLayoutManagerUniquePtr = std::unique_ptr<InputLayoutManager>;

    private:
        RendererObjectContainer rendererObject;
        mutable std::mutex rendererObjectMutex;
        RendererDrawTargetContainer rendererDrawTarget;
        mutable std::mutex rendererDrawTargetMutex;
        InputLayoutManagerUniquePtr inputLayoutManager;

        bool allowOcclusionQuery;
        bool warnOnNonemptyBridges;
    };
}

#endif  // RENDERING_GRAPHICS_RENDERER_H