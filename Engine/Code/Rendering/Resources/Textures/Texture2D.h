/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:54)

#ifndef RENDERING_RESOURCES_TEXTURE_2D_H
#define RENDERING_RESOURCES_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "TextureSingle.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture2D, Texture2DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2D : public TextureSingle
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Texture2D);
        using ParentType = TextureSingle;

        using Texture2DSharedPtr = std::shared_ptr<ClassType>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const ClassType>;

    public:
        Texture2D(const std::string& name, DataFormatType format, int width, int height, bool hasMipMaps, bool createStorage = true);
        Texture2D(const std::string& name, DataFormatType format, int width, int height, bool hasMipMaps, GraphicsObjectType type, bool createStorage = true);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2D);

        NODISCARD int GetNumItems() const noexcept override;

        NODISCARD int GetDimension(int index) const override;

        NODISCARD DataFormatType GetFormat() const noexcept override;
        NODISCARD int GetNumLevels() const noexcept override;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int level, int index) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetLevelOffset(int item, int level) const override;

        NODISCARD bool HasMipMaps() const noexcept override;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        void AutoGenerateMipMaps() noexcept override;
        NODISCARD bool WantAutoGenerateMipMaps() const noexcept override;

        NODISCARD int GetNumSubResources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

        NODISCARD int GetNumElementsFor(int level) const override;

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        void MakeShared() noexcept;
        NODISCARD bool IsShared() const noexcept;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
        bool shared;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture2D);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture2D);
}

#endif  // RENDERING_RESOURCES_TEXTURE_1D_H
