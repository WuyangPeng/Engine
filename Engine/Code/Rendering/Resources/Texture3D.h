///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/31 13:57)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_H
#define RENDERING_RESOURCES_TEXTURE_3D_H

#include "Texture.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture3D, Texture3DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture3D : public Texture
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Texture3D);
        using ParentType = Texture;
        using Texture3DSharedPtr = std::shared_ptr<ClassType>;
        using ConstTexture3DSharedPtr = std::shared_ptr<ClassType>;

    public:
        Texture3D(TextureFormat format, int dimension0, int dimension1, int dimension2, int numLevels, BufferUsage usage = BufferUsage::Texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture3D);

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

        void SetUserField(int index, int userField) override;
        NODISCARD int GetUserField(int index) const override;

        void GenerateMipmaps() override;
        NODISCARD bool HasMipmaps() const override;
        void SaveToFile(WriteFileManager& outFile) const override;
        void ReadFromFile(ReadFileManager& inFile) override;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD int GetThickness() const;

        NODISCARD char* GetTextureData(int level);
        NODISCARD const char* GetTextureData(int level) const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD TextureSharedPtr Clone() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Texture3D);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture3D);
}

#endif  // RENDERING_RESOURCES_TEXTURE_3D_H
