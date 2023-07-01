///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 19:29)

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

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        DrawTargetImpl() noexcept;
        DrawTargetImpl(int numRenderTargets,
                       DataFormatType renderTargetFormat,
                       int width,
                       int height,
                       bool hasRenderTargetMipMaps = false,
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
        NODISCARD bool HasRenderTargetMipMaps() const;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD TextureRenderTargetSharedPtr GetRenderTargetTexture(int index);
        NODISCARD TextureDepthStencilSharedPtr GetDepthStencilTexture();
        NODISCARD ConstTextureRenderTargetSharedPtr GetRenderTargetTexture(int index) const;
        NODISCARD ConstTextureDepthStencilSharedPtr GetDepthStencilTexture() const;
        NODISCARD bool HasDepthStencil() const noexcept;

        void AutoGenerateRenderTargetMipMaps();
        NODISCARD bool WantAutoGenerateRenderTargetMipMaps() const;

        NODISCARD int GetStreamingSize() const;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

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