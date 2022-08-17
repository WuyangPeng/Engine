///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/15 14:48)

#ifndef RENDERING_RESOURCES_DRAW_TARGET_IMPL_H
#define RENDERING_RESOURCES_DRAW_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Textures/TextureDepthStencil.h"
#include "Rendering/Resources/Textures/TextureRenderTarget.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE DrawTargetImpl
    {
    public:
        using ClassType = DrawTargetImpl;

    public:
        DrawTargetImpl() noexcept;
        DrawTargetImpl(int numRenderTargets,
                       DataFormatType renderTargetFormat,
                       int width,
                       int height,
                       bool hasRenderTargetMipmaps = false,
                       DataFormatType depthStencilFormat = DataFormatType::Unknown);

        ~DrawTargetImpl() noexcept = default;
        DrawTargetImpl(const DrawTargetImpl& rhs);
        DrawTargetImpl& operator=(const DrawTargetImpl& rhs);
        DrawTargetImpl(DrawTargetImpl&& rhs) noexcept;
        DrawTargetImpl& operator=(DrawTargetImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumTargets() const;

        NODISCARD DataFormatType GetRenderTargetFormat() const;
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD bool HasRenderTargetMipmaps() const;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD TextureRenderTargetSharedPtr GetRenderTargetTexture(int index);
        NODISCARD TextureDepthStencilSharedPtr GetDepthStencilTexture();
        NODISCARD ConstTextureRenderTargetSharedPtr GetRenderTargetTexture(int index) const;
        NODISCARD ConstTextureDepthStencilSharedPtr GetDepthStencilTexture() const;
        NODISCARD bool HasDepthStencil() const noexcept;

        void AutogenerateRTMipmaps();
        NODISCARD bool WantAutogenerateRTMipmaps() const;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        using TextureRenderTargetObjectAssociated = CoreTools::ObjectAssociated<TextureRenderTarget>;
        using TextureRenderTargetContainer = std::vector<TextureRenderTargetObjectAssociated>;
        using TextureDepthStencilObjectAssociated = CoreTools::ObjectAssociated<TextureDepthStencil>;

    private:
        void Swap(DrawTargetImpl& rhs) noexcept;

    private:
        TextureRenderTargetContainer renderTargetTextures;
        TextureDepthStencilObjectAssociated depthStencilTexture;
    };
}

#endif  // RENDERING_RESOURCES_DRAW_TARGET_IMPL_H