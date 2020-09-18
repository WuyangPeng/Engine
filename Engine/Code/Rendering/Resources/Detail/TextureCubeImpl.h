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
 
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;
     
        int GetWidth () const;
        int GetHeight () const;

        char* GetTextureData (int face,int level);
		const char* GetTextureData (int face,int level) const;
        
          int GetNumDimensions () const noexcept override;
          int GetDimension (int index, int level) const override;
          int GetNumLevelBytes (int level) const override;
          int GetNumTotalBytes () const noexcept override;
          int GetLevelOffset (int level) const override;

	protected:
		  int GetMaxLevels() const override;

	private:
		using FloatColour = Colour<float>;
		using TextureLevelData = TextureLevelData<2>;

	private:
        void ResetDimension(int dimension);
		  void DoGenerateMipmaps() override;
		  void ComputeNumLevelBytes() override;
		  void VerifyNumLevels() override;
        void GenerateNextMipmap (int dimension, const char* texels,int dimensionNext, char* texelsNext);
        int CalculateNumLevelBytes(int dimension);
        
          void LoadLevelData (CoreTools::BufferSource& source) override;
		  void SaveLevelData (const CoreTools::BufferTargetSharedPtr& target) const override;
          int GetLevelDataStreamingSize() const noexcept override;
	
		  void SaveLevelDataToFile (WriteFileManager& outFile) const override;
		  void LoadLevelDataFromFile (ReadFileManager& inFile) override;

		  void ExpandFileBufferSize() override;
        
    private:
        TextureLevelData m_TextureLevelData;
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
