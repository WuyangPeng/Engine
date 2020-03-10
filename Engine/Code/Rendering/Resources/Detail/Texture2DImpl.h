// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 09:45)

#ifndef RENDERING_RESOURCES_TEXTURE_2D_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_2D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "Rendering/Resources/TextureLevelData.h"

namespace Rendering
{
	template <typename T>
	class Colour;

    class RENDERING_HIDDEN_DECLARE Texture2DImpl : public TextureImpl
    {
    public:
        using ClassType = Texture2DImpl;
		using ParentType = TextureImpl;
        
    public:
		Texture2DImpl();
		Texture2DImpl (TextureFormat format, int dimension0,int dimension1,int numLevels,BufferUsage usage = BufferUsage::Texture);
		virtual ~Texture2DImpl();
        
		CLASS_INVARIANT_VIRTUAL_DECLARE;
     
		// 获取第零级别mipmap产生的维度。
        int GetWidth () const;
        int GetHeight () const;

		// 访问纹理数据
        char* GetTextureData (int level);
		const char* GetTextureData (int level) const;
        
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
        void ResetDimension(int dimension0,int dimension1);
		virtual void DoGenerateMipmaps() override;
		virtual void ComputeNumLevelBytes() override;
		virtual void VerifyNumLevels() override;
        void GenerateNextMipmap (int width, int height, const char* texels, int widthNext, int heightNext, char* texelsNext);
        int CalculateNumLevelBytes(int dimension0,int dimension1);
        
        virtual void LoadLevelData (CoreTools::BufferSource& source) override;
		virtual void SaveLevelData (CoreTools::BufferTarget& target) const override;
		virtual int GetLevelDataStreamingSize () const override;

		virtual void SaveLevelDataToFile (WriteFileManager& outFile) const override;
		virtual void LoadLevelDataFromFile (ReadFileManager& inFile) override;
        
    private:
        TextureLevelData m_TextureLevelData;
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_1D_IMPL_H
