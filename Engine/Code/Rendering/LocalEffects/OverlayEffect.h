///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/21 15:45)

#ifndef RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/State/StateFwd.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OverlayEffect, OverlayEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OverlayEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OverlayEffect);

        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using IndexBufferSharedPtr = std::shared_ptr<IndexBuffer>;
        using ConstVisualProgramSharedPtr = std::shared_ptr<const VisualProgram>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using ConstVisualEffectSharedPtr = std::shared_ptr<const VisualEffect>;
        using VisualEffectSharedPtr = std::shared_ptr<VisualEffect>;
        using RectangleType = std::array<int, 4>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;

    public:
        OverlayEffect(int windowWidth, int windowHeight);

        OverlayEffect(ProgramFactory& factory,
                      int windowWidth,
                      int windowHeight,
                      int textureWidth,
                      int textureHeight,
                      SamplerStateFilter filter,
                      SamplerStateMode mode0,
                      SamplerStateMode mode1,
                      bool useColorPShader);

        OverlayEffect(ProgramFactory& factory,
                      int windowWidth,
                      int windowHeight,
                      int textureWidth,
                      int textureHeight,
                      const std::string& pixelShaderFile);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstVertexBufferSharedPtr GetVertexBuffer() const noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetIndexBuffer() const noexcept;
        NODISCARD ConstVisualProgramSharedPtr GetProgram() const noexcept;
        NODISCARD ConstVisualEffectSharedPtr GetEffect() const noexcept;

        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;
        NODISCARD VisualProgramSharedPtr GetProgram() noexcept;
        NODISCARD VisualEffectSharedPtr GetEffect() noexcept;

        void SetOverlayRectangle(const RectangleType& rectangle);

        NODISCARD RectangleType GetOverlayRectangle() const noexcept;

        void SetTextureRectangle(const RectangleType& rectangle);

        NODISCARD RectangleType GetTextureRectangle() const noexcept;

        void SetRectangles(const RectangleType& overlayRectangle, const RectangleType& textureRectangle);

        NODISCARD bool Contains(int x, int y) const;

        void SetTexture(const Texture2DSharedPtr& texture);
        void SetTexture(std::string const& textureName, const Texture2DSharedPtr& texture);

        void SetNormalizedZ(float z);

    private:
        PackageType impl;
    };

}

#endif  // RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_H
