// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:14)

#ifndef RENDERING_RESOURCES_TEXTURE_2D_H
#define RENDERING_RESOURCES_TEXTURE_2D_H

#include "Texture.h"

EXPORT_SHARED_PTR(Rendering, Texture2DImpl, RENDERING_DEFAULT_DECLARE);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2D : public Texture
    {
    public:
        void Swap(Texture2D& rhs) noexcept;

    public:
        TYPE_DECLARE(Texture2D);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~Texture2D() noexcept;
        Texture2D(const Texture2D& rhs);
        Texture2D& operator=(const Texture2D& rhs);
        Texture2D(Texture2D&& rhs) noexcept;
        Texture2D& operator=(Texture2D&& rhs) noexcept;
		using ParentType = Texture;
		using Texture2DSharedPtr = std::shared_ptr<ClassType>;
		using ConstTexture2DSharedPtr = std::shared_ptr<const ClassType>;
        
    public:
		Texture2D (TextureFormat format, int dimension0, int dimension1,int numLevels, BufferUsage usage = BufferUsage::Texture);
		 
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2D); 
        
          TextureFormat GetFormat () const noexcept override;
                TextureFlags GetTextureType() const noexcept override;
          BufferUsage GetUsage() const noexcept override;
                int GetNumLevels() const noexcept override;
        
          int GetNumDimensions() const noexcept override;
          int GetDimension (int index, int level) const override;
          int GetNumLevelBytes (int level) const override;
          int GetNumTotalBytes() const noexcept override;
          int GetLevelOffset (int level) const override;
        
          int GetPixelSize () const override;
          bool IsCompressed() const noexcept override;
          bool IsMipmapable () const override;

          void SetUserField (int index, int userField) override;
          int GetUserField (int index) const override;
        
          void GenerateMipmaps () override;
          bool HasMipmaps () const override;

          void SaveToFile (WriteFileManager& outFile) const override;
          void ReadFromFile (ReadFileManager& inFile) override;

        int GetWidth () const;
        int GetHeight () const;

        char* GetTextureData (int level);
		const char* GetTextureData (int level) const;

		  TextureSharedPtr Clone() const override;
                ObjectInterfaceSharedPtr CloneObject() const override;
    private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)   
    CORE_TOOLS_STREAM_REGISTER(Texture2D);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( Texture2D); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_TEXTURE_1D_H
