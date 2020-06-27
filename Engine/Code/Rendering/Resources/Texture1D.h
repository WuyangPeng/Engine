// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:12)

#ifndef RENDERING_RESOURCES_TEXTURE_1D_H
#define RENDERING_RESOURCES_TEXTURE_1D_H

#include "Texture.h"

RENDERING_EXPORT_SHARED_PTR(Texture1DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture1D : public Texture
    {
    public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(Texture1D);
		using ParentType = Texture;
		using Texture1DSmartPointer = CoreTools::FourthSubclassSmartPointer<ClassType>;
		using ConstTexture1DSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<ClassType>;

    public:
		Texture1D (TextureFormat format, int dimension0,int numLevels,BufferUsage usage = BufferUsage::Texture);
		virtual ~Texture1D();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture1D); 
        
        virtual TextureFormat GetFormat () const override;
        virtual TextureFlags GetTextureType () const override;
        virtual BufferUsage GetUsage () const override;
        virtual int GetNumLevels () const override;
        
        virtual int GetNumDimensions () const override;
        virtual int GetDimension (int index, int level) const override;
        virtual int GetNumLevelBytes (int level) const override;
        virtual int GetNumTotalBytes () const override;
        virtual int GetLevelOffset (int level) const override;
        
        virtual int GetPixelSize () const override;
        virtual bool IsCompressed () const override;
        virtual bool IsMipmapable () const override;
        
        virtual void SetUserField (int index, int userField) override;
        virtual int GetUserField (int index) const override;
        
        virtual void GenerateMipmaps () override;
        virtual bool HasMipmaps () const override;
        
        virtual void SaveToFile (WriteFileManager& outFile) const override;
		virtual void ReadFromFile (ReadFileManager& inFile) override;

        int GetLength () const;
 
        char* GetTextureData (int level);
		const char* GetTextureData (int level) const;

		virtual TextureSmartPointer Clone() const override;
        
    private:
		IMPL_TYPE_DECLARE(Texture1D);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(Texture1D);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, Texture1D); 
}

#endif // RENDERING_RESOURCES_TEXTURE_1D_H
