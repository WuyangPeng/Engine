///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 14:37)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_H

#include "Texture.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TextureCube, TextureCubeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureCube : public Texture
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TextureCube);
        using ParentType = Texture;
        using TextureCubeSharedPtr = std::shared_ptr<ClassType>;
        using ConstTextureCubeSharedPtr = std::shared_ptr<ClassType>;

    public:
        TextureCube(TextureFormat format, int dimension, int numLevels, BufferUsage usage = BufferUsage::Texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureCube);

        NODISCARD TextureFormat GetFormat() const noexcept override;
        NODISCARD TextureFlags GetTextureType() const noexcept override;
        NODISCARD BufferUsage GetUsage() const noexcept override;
        NODISCARD int GetNumLevels() const noexcept override;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int index, int level) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetNumTotalBytes() const noexcept override;
        NODISCARD int GetLevelOffset(int level) const override;

        NODISCARD int GetPixelSize() const override;
        NODISCARD bool IsCompressed() const noexcept override;
        NODISCARD bool IsMipmapable() const override;
        void SaveToFile(WriteFileManager& outFile) const override;
        void ReadFromFile(ReadFileManager& inFile) override;

        void SetUserField(int index, int userField) override;
        NODISCARD int GetUserField(int index) const override;

        void GenerateMipmaps() override;
        NODISCARD bool HasMipmaps() const override;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        NODISCARD char* GetTextureData(int face, int level);
        NODISCARD const char* GetTextureData(int face, int level) const;

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TextureCube);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureCube);
}

#endif  // RENDERING_RESOURCES_TEXTURE_CUBE_H
