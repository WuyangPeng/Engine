///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:17)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_H
#define RENDERING_RESOURCES_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "TextureSingle.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture3D, Texture3DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture3D : public TextureSingle
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Texture3D);
        using ParentType = TextureSingle;

    public:
        Texture3D(DataFormatType format, int width, int height, int thickness, bool hasMipMaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture3D);

        NODISCARD int GetNumItems() const noexcept override;

        NODISCARD int GetDimension(int index) const override;

        NODISCARD DataFormatType GetFormat() const noexcept override;
        NODISCARD int GetNumLevels() const noexcept override;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int level, int index) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetLevelOffset(int item, int level) const override;

        NODISCARD bool HasMipMaps() const noexcept override;
        void SaveToFile(WriteFileManager& outFile) const override;
        void ReadFromFile(ReadFileManager& inFile) override;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD int GetThickness() const;

        void AutoGenerateMipMaps() noexcept override;
        NODISCARD bool WantAutoGenerateMipMaps() const noexcept override;

        NODISCARD int GetNumSubResources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

        NODISCARD int GetNumElementsFor(int level) const override;

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture3D);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture3D);
}

#endif  // RENDERING_RESOURCES_TEXTURE_3D_H
