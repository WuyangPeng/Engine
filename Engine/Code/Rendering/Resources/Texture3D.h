// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:15)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_H
#define RENDERING_RESOURCES_TEXTURE_3D_H

#include "Texture.h"

RENDERING_EXPORT_SHARED_PTR(Texture3DImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture3D : public Texture
    {
    public:
		OLD_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Texture3D);
		using ParentType = Texture;
		using Texture3DSmartPointer = CoreTools::FourthSubclassSmartPointer<ClassType>;
		using ConstTexture3DSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<ClassType>;
        
    public:
		Texture3D (TextureFormat format, int dimension0,int dimension1,int dimension2,int numLevels,BufferUsage usage = BufferUsage::Texture);
		  ~Texture3D();
                Texture3D(Texture3D&&) = default;
                  Texture3D& operator=(Texture3D&&) = default;
        
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
		  TextureSmartPointer Clone() const override;
        
    private:
		IMPL_TYPE_DECLARE(Texture3D);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)  
    CORE_TOOLS_STREAM_REGISTER(Texture3D);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, Texture3D); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_TEXTURE_3D_H
