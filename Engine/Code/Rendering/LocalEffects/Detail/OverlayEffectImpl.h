///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 14:29)

#ifndef RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/State/StateFwd.h"

#include <array>
#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OverlayEffectImpl
    {
    public:
        using ClassType = OverlayEffectImpl;

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
        OverlayEffectImpl() noexcept;
        OverlayEffectImpl(int windowWidth, int windowHeight);

        OverlayEffectImpl(ProgramFactory& factory,
                          int windowWidth,
                          int windowHeight,
                          int textureWidth,
                          int textureHeight,
                          SamplerStateFilter filter,
                          SamplerStateMode mode0,
                          SamplerStateMode mode1,
                          bool useColorPShader);

        OverlayEffectImpl(ProgramFactory& factory,
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

        void SetOverlayRectangle(const RectangleType& rectangle);

        NODISCARD RectangleType GetOverlayRectangle() const noexcept;

        void SetTextureRectangle(const RectangleType& rectangle);

        NODISCARD RectangleType GetTextureRectangle() const noexcept;

        void SetRectangles(const RectangleType& aOverlayRectangle, const RectangleType& aTextureRectangle);

        NODISCARD bool Contains(int x, int y) const;

        void SetTexture(const Texture2DSharedPtr& texture);
        void SetTexture(std::string const& textureName, const Texture2DSharedPtr& texture);

        void SetNormalizedZ(float z);

    private:
        NODISCARD static VertexFormat GetVertexFormat();
        void Initialize();

        void UpdateVertexBuffer();

    private:
        float windowWidth;
        float windowHeight;
        float invTextureWidth;
        float invTextureHeight;
        RectangleType overlayRectangle;
        RectangleType textureRectangle;
        VertexBufferSharedPtr vertexBuffer;
        IndexBufferSharedPtr indexBuffer;
        VisualProgramSharedPtr program;
        VisualEffectSharedPtr effect;
        ShaderAPIType shaderAPIType;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_IMPL_H
