///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/04 20:37)

#ifndef RENDERING_STATE_RASTERIZER_STATE_H
#define RENDERING_STATE_RASTERIZER_STATE_H

#include "Rendering/RenderingDll.h"

#include "DepthStencilStateFace.h"
#include "DrawingState.h"
#include "StateFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/GraphicsObject.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RasterizerState : public DrawingState
    {
    public:
        using ClassType = RasterizerState;
        using ParentType = DrawingState;

    public:
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

    private:
        enum class RasterizerStateCreate
        {
            Init,
        };

    public:
        NODISCARD static RasterizerStateSharedPtr Create(const std::string& name);
        explicit RasterizerState(RasterizerStateCreate rasterizerStateCreate, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RasterizerState);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RasterizerStateFill GetFill() const noexcept;
        void SetFill(RasterizerStateFill rasterizerStateFill) noexcept;

        NODISCARD RasterizerStateCull GetCull() const noexcept;
        void SetCull(RasterizerStateCull rasterizerStateCull) noexcept;

        NODISCARD bool IsFrontCCW() const noexcept;
        void SetFrontCCW(bool aFrontCCW) noexcept;

        NODISCARD int GetDepthBias() const noexcept;
        void SetDepthBias(int aDepthBias) noexcept;

        NODISCARD float GetDepthBiasClamp() const noexcept;
        void SetDepthBiasClamp(float aDepthBiasClamp) noexcept;

        NODISCARD float GetSlopeScaledDepthBias() const noexcept;
        void SetSlopeScaledDepthBias(float aSlopeScaledDepthBias) noexcept;

        NODISCARD bool IsEnableDepthClip() const noexcept;
        void SetEnableDepthClip(bool aEnableDepthClip) noexcept;

        NODISCARD bool IsEnableScissor() const noexcept;
        void SetEnableScissor(bool aEnableScissor) noexcept;

        NODISCARD bool IsEnableMultisample() const noexcept;
        void SetEnableMultisample(bool aEnableMultisample) noexcept;

        NODISCARD bool IsEnableAntialiasedLine() const noexcept;
        void SetEnableAntialiasedLine(bool aEnableAntialiasedLine) noexcept;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        void CheckDrawingState();

    private:
        RasterizerStateFill fill;
        RasterizerStateCull cull;
        bool frontCCW;
        int depthBias;
        float depthBiasClamp;
        float slopeScaledDepthBias;
        bool enableDepthClip;
        bool enableScissor;
        bool enableMultisample;
        bool enableAntialiasedLine;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(RasterizerState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(RasterizerState);
}

#endif  // RENDERING_STATE_RASTERIZER_STATE_H
