// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:15)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_H
#define RENDERING_RESOURCES_TEXTURE_3D_H

#include "Texture.h"

EXPORT_SHARED_PTR(Rendering, Texture3DImpl, RENDERING_DEFAULT_DECLARE);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture3D : public Texture
    {
    public:
        void Swap(Texture3D& rhs) noexcept;

    public:
        TYPE_DECLARE(Texture3D);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~Texture3D() noexcept;
        Texture3D(const Texture3D& rhs);
        Texture3D& operator=(const Texture3D& rhs);
        Texture3D(Texture3D&& rhs) noexcept;
        Texture3D& operator=(Texture3D&& rhs) noexcept;
		using ParentType = Texture;
		using Texture3DSharedPtr = std::shared_ptr<ClassType>;
		using ConstTexture3DSharedPtr = std::shared_ptr<ClassType>;
        
    public:
		Texture3D (TextureFormat format, int dimension0,int dimension1,int dimension2,int numLevels,BufferUsage usage = BufferUsage::Texture);
		 
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture3D); 
        
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
        int GetThickness () const;
        
        char* GetTextureData (int level);
		const char* GetTextureData (int level) const;
        ObjectInterfaceSharedPtr CloneObject() const override;
		  TextureSharedPtr Clone() const override;
        
    private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)  
    CORE_TOOLS_STREAM_REGISTER(Texture3D);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( Texture3D); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_TEXTURE_3D_H
