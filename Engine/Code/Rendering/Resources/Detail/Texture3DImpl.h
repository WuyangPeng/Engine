// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 09:46)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_3D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "Rendering/Resources/TextureLevelData.h"

namespace Rendering
{
	template <typename T>
	class Colour;

    class RENDERING_HIDDEN_DECLARE Texture3DImpl : public TextureImpl
    {
    public:
        using ClassType = Texture3DImpl;
		using ParentType = TextureImpl;
        
    public:
		Texture3DImpl();
		Texture3DImpl (TextureFormat format, int dimension0,int dimension1,int dimension2,int numLevels,BufferUsage usage = BufferUsage::Texture);
		 
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;
     
		// 获取第零级别mipmap产生的维度。
        int GetWidth () const;
        int GetHeight () const;
        int GetThickness () const;

		// 访问纹理数据
        char* GetTextureData (int level);
		const char* GetTextureData (int level) const;
        
          int GetNumDimensions () const noexcept override;
          int GetDimension (int index, int level) const override;
          int GetNumLevelBytes (int level) const override;
          int GetNumTotalBytes () const noexcept override;
          int GetLevelOffset (int level) const override;

	protected:
            int GetMaxLevels() const override;

	private:
		using FloatColour = Colour<float>;
		using TextureLevelData = TextureLevelData<3>;

    private:
        void ResetDimension(int dimension0,int dimension1,int dimension2);
		  void DoGenerateMipmaps() override;
		  void ComputeNumLevelBytes() override;
		  void VerifyNumLevels() override;
        void GenerateNextMipmap (int width, int height, int thickness, const char* texels,
                                 int widthNext, int heightNext, int thicknessNext,char* texelsNext);
        int CalculateNumLevelBytes(int dimension0,int dimension1,int dimension2);
        
          void LoadLevelData(const CoreTools::BufferSourceSharedPtr& source) override;
		  void SaveLevelData (const CoreTools::BufferTargetSharedPtr& target) const override;
          int GetLevelDataStreamingSize() const noexcept override;

		  void SaveLevelDataToFile (WriteFileManager& outFile) const override;
		  void LoadLevelDataFromFile (ReadFileManager& inFile) override;
        
    private:
        TextureLevelData m_TextureLevelData;
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_3D_IMPL_H
