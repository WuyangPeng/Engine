// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:12)

#ifndef RENDERING_RESOURCES_TEXTURE_1D_H
#define RENDERING_RESOURCES_TEXTURE_1D_H

#include "Texture.h"

RENDERING_EXPORT_SHARED_PTR(Texture1DImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture1D : public Texture
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Texture1D);
        using ParentType = Texture;
        using Texture1DSmartPointer = std::shared_ptr<ClassType>;
        using ConstTexture1DSmartPointer = std::shared_ptr<const ClassType>;

    public:
        Texture1D(TextureFormat format, int dimension0, int numLevels, BufferUsage usage = BufferUsage::Texture);
        ~Texture1D();

        Texture1D(Texture1D&&) = default;
        Texture1D& operator=(Texture1D&&) = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture1D);

        TextureFormat GetFormat() const noexcept override;
        TextureFlags GetTextureType() const noexcept override;
        BufferUsage GetUsage() const noexcept override;
        int GetNumLevels() const noexcept override;

        int GetNumDimensions() const noexcept override;
        int GetDimension(int index, int level) const override;
        int GetNumLevelBytes(int level) const override;
        int GetNumTotalBytes() const noexcept override;
        int GetLevelOffset(int level) const override;

        int GetPixelSize() const override;
        bool IsCompressed() const noexcept override;
        bool IsMipmapable() const override;

        void SetUserField(int index, int userField) override;
        int GetUserField(int index) const override;

        void GenerateMipmaps() override;
        bool HasMipmaps() const override;

        void SaveToFile(WriteFileManager& outFile) const override;
        void ReadFromFile(ReadFileManager& inFile) override;

        int GetLength() const;

        char* GetTextureData(int level);
        const char* GetTextureData(int level) const;

        TextureSmartPointer Clone() const override;

    private:
        IMPL_TYPE_DECLARE(Texture1D);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Texture1D);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, Texture1D);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_RESOURCES_TEXTURE_1D_H
