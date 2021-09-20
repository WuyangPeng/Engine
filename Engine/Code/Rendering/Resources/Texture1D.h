// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:12)

#ifndef RENDERING_RESOURCES_TEXTURE_1D_H
#define RENDERING_RESOURCES_TEXTURE_1D_H

#include "Texture.h"
EXPORT_SHARED_PTR(Rendering, Texture1DImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture1D : public Texture
    {
    public:
        void Swap(Texture1D& rhs) noexcept;

    public:
        TYPE_DECLARE(Texture1D);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~Texture1D() noexcept;
        Texture1D(const Texture1D& rhs);
        Texture1D& operator=(const Texture1D& rhs);
        Texture1D(Texture1D&& rhs) noexcept;
        Texture1D& operator=(Texture1D&& rhs) noexcept;
        using ParentType = Texture;
        using Texture1DSharedPtr = std::shared_ptr<ClassType>;
        using ConstTexture1DSharedPtr = std::shared_ptr<const ClassType>;

    public:
        Texture1D(TextureFormat format, int dimension0, int numLevels, BufferUsage usage = BufferUsage::Texture);
       

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

        TextureSharedPtr Clone() const override;
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Texture1D);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( Texture1D);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_RESOURCES_TEXTURE_1D_H
