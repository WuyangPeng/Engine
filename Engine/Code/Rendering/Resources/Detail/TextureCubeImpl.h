// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 10:16)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "Rendering/Resources/TextureLevelData.h"

namespace Rendering
{
	template <typename T>
	class Colour;

    class RENDERING_HIDDEN_DECLARE TextureCubeImpl : public TextureImpl
    {
    public:
        using ClassType = TextureCubeImpl;
		using ParentType = TextureImpl;
        
    public:
		TextureCubeImpl();
		TextureCubeImpl (TextureFormat format, int dimension,int numLevels,BufferUsage usage = BufferUsage::Texture);
		virtual ~TextureCubeImpl();
        
		CLASS_INVARIANT_VIRTUAL_DECLARE;
     
        int GetWidth () const;
        int GetHeight () const;

        char* GetTextureData (int face,int level);
		const char* GetTextureData (int face,int level) const;
        
        virtual int GetNumDimensions () const override;
        virtual int GetDimension (int index, int level) const override;
        virtual int GetNumLevelBytes (int level) const override;
        virtual int GetNumTotalBytes () const override;
        virtual int GetLevelOffset (int level) const override;

	protected:
		virtual int GetMaxLevels() const override;

	private:
		using FloatColour = Colour<float>;
		using TextureLevelData = TextureLevelData<2>;

	private:
        void ResetDimension(int dimension);
		virtual void DoGenerateMipmaps() override;
		virtual void ComputeNumLevelBytes() override;
		virtual void VerifyNumLevels() override;
        void GenerateNextMipmap (int dimension, const char* texels,int dimensionNext, char* texelsNext);
        int CalculateNumLevelBytes(int dimension);
        
        virtual void LoadLevelData (CoreTools::BufferSource& source) override;
		virtual void SaveLevelData (CoreTools::BufferTarget& target) const override;
		virtual int GetLevelDataStreamingSize () const override;
	
		virtual void SaveLevelDataToFile (WriteFileManager& outFile) const override;
		virtual void LoadLevelDataFromFile (ReadFileManager& inFile) override;

		virtual void ExpandFileBufferSize() override;
        
    private:
        TextureLevelData m_TextureLevelData;
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
