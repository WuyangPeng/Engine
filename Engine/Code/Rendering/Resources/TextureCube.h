// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 11:16)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_H

#include "Texture.h"

RENDERING_EXPORT_SHARED_PTR(TextureCubeImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureCube : public Texture
    {
    public:
         COPY_UNSHARE_CLASSES_TYPE_DECLARE(TextureCube, DESTRUCTOR_STATEMENT);
		using ParentType = Texture;
		using TextureCubeSharedPtr = std::shared_ptr<ClassType>;
		using ConstTextureCubeSharedPtr = std::shared_ptr<ClassType>;
        
    public:
		TextureCube (TextureFormat format, int dimension, int numLevels, BufferUsage usage = BufferUsage::Texture);
		 
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureCube); 
        
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
          void SaveToFile (WriteFileManager& outFile) const override;
          void ReadFromFile (ReadFileManager& inFile) override;

		  void SetUserField (int index, int userField) override;
          int GetUserField (int index) const override;
        
          void GenerateMipmaps () override;
          bool HasMipmaps () const override;

        int GetWidth () const;
        int GetHeight () const;

        char* GetTextureData (int face,int level);
		const char* GetTextureData (int face,int level) const;

		  TextureSharedPtr Clone() const override;
                ObjectInterfaceSharedPtr CloneObject() const override;
    private:
		IMPL_TYPE_DECLARE(TextureCube);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)  
    CORE_TOOLS_STREAM_REGISTER(TextureCube);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( TextureCube); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_TEXTURE_CUBE_H
