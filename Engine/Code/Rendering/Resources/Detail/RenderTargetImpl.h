///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 15:01)

#ifndef RENDERING_RESOURCES_RENDER_TARGET_IMPL_H
#define RENDERING_RESOURCES_RENDER_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Texture2D.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderTargetImpl
    {
    public:
        using ClassType = RenderTargetImpl;
        using Object = CoreTools::Object;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using ObjectAssociated = CoreTools::ObjectAssociated<Texture2D>;

    public:
        // 支持目标的数量取决于图形硬件和驱动程序。“numTargets”必须至少1。
        RenderTargetImpl() noexcept;
        RenderTargetImpl(int numTargets, TextureFormat format, int width, int height, bool hasMipmaps, bool hasDepthStencil);

        ~RenderTargetImpl() noexcept = default;
        RenderTargetImpl(const RenderTargetImpl& rhs);
        RenderTargetImpl& operator=(const RenderTargetImpl& rhs);
        RenderTargetImpl(RenderTargetImpl&& rhs) noexcept;
        RenderTargetImpl& operator=(RenderTargetImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumTargets() const;
        NODISCARD TextureFormat GetFormat() const;
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD ConstTexture2DSharedPtr GetColorTexture(int index) const;
        NODISCARD ConstTexture2DSharedPtr GetDepthStencilTexture() const noexcept;
        NODISCARD bool HasMipmaps() const noexcept;
        NODISCARD bool HasDepthStencil() const noexcept;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        void Swap(RenderTargetImpl& rhs) noexcept;

    private:
        std::vector<ObjectAssociated> colorTextures;
        ObjectAssociated depthStencilTexture;
        bool hasMipmaps;
    };
}

#endif  // RENDERING_RESOURCES_RENDER_TARGET_IMPL_H
