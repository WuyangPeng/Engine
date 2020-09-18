// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 09:45)

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
 
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;
     
		// ��ȡ���㼶��mipmap������ά�ȡ�
        int GetWidth () const;
        int GetHeight () const;

		// ������������
        char* GetTextureData (int level);
		const char* GetTextureData (int level) const;
        
          int GetNumDimensions() const noexcept override;
          int GetDimension (int index, int level) const override;
          int GetNumLevelBytes (int level) const override;
          int GetNumTotalBytes() const noexcept override;
          int GetLevelOffset (int level) const override;

	protected:
		  int GetMaxLevels() const override;

    private:
		using FloatColour = Colour<float>;
		using TextureLevelData = TextureLevelData<2>;

	private:
        void ResetDimension(int dimension0,int dimension1);
		  void DoGenerateMipmaps() override;
		  void ComputeNumLevelBytes() override;
		  void VerifyNumLevels() override;
        void GenerateNextMipmap (int width, int height, const char* texels, int widthNext, int heightNext, char* texelsNext);
        int CalculateNumLevelBytes(int dimension0,int dimension1);
        
          void LoadLevelData (CoreTools::BufferSource& source) override;
		  void SaveLevelData (const CoreTools::BufferTargetSharedPtr& target) const override;
          int GetLevelDataStreamingSize() const noexcept override;

		  void SaveLevelDataToFile (WriteFileManager& outFile) const override;
		  void LoadLevelDataFromFile (ReadFileManager& inFile) override;
        
    private:
        TextureLevelData m_TextureLevelData;
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_1D_IMPL_H
