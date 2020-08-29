// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 14:28)

#include "Rendering/RenderingExport.h"

#include "Texture1DImpl.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/ColourConvertTo.h"
#include "Rendering/DataTypes/ColourConvertFrom.h"
#include "Rendering/Resources/TextureLevelDataDetail.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <vector>

using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26486)
Rendering::Texture1DImpl
    ::Texture1DImpl(TextureFormat format, int dimension0,int numLevels,BufferUsage usage)
	:ParentType{ format, TextureFlags::Texture1D, usage, numLevels }, m_TextureLevelData{ CalculateNumDimensions(TextureFlags::Texture1D) }
{
    RENDERING_ASSERTION_0(0 < dimension0, "Dimension0 ����������\n");
    
    ResetDimension(dimension0);
    VerifyNumLevels();
    ComputeNumLevelBytes();
	ResetTextureBufferNum();
    
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture1DImpl
	::Texture1DImpl()
	:ParentType{ TextureFormat::A8R8G8B8, TextureFlags::Texture1D, BufferUsage::Texture, 0 },
	 m_TextureLevelData{ CalculateNumDimensions(TextureFlags::Texture1D) }
{   
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::Texture1DImpl
    ::ResetDimension(int dimension0)
{
    m_TextureLevelData.SetDimension(0,0,dimension0);
    
    const auto maxLevels = GetMaxLevels();
    const auto numLevels = GetNumLevels();
    
    RENDERING_ASSERTION_0(0 <= numLevels && numLevels <= maxLevels, "numLevels��Ч��\n");
    
    if (numLevels == 0)
    {   
		// �û�ϣ������������ļ���
        SetNumLevels(maxLevels);
    }
}

int Rendering::Texture1DImpl
    ::GetMaxLevels() const
{
	auto logDimension0 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetLength());
    const auto maxLevels = logDimension0 + 1;
    
    return maxLevels;
}

// private
void Rendering::Texture1DImpl
    ::ComputeNumLevelBytes ()
{
    const auto format = GetFormat();
    const auto type = GetTextureType();
      auto dimension0 = GetLength();
    const auto numLevels = GetNumLevels();
    
    for (auto level = 0; level < numLevels; ++level)
    {
        m_TextureLevelData.SetNumLevelBytes(level,GetPixelSize(format) * dimension0);
        m_TextureLevelData.SetDimension(0,level,dimension0);
        
        if (1 < dimension0)
        {
            dimension0 >>= 1;
        }
    }
    
	m_TextureLevelData.RecountNumTotalBytes(numLevels, type);
    m_TextureLevelData.RecountLevelOffsets(numLevels);
}

// private
void Rendering::Texture1DImpl
    ::VerifyNumLevels()
{
    CoreTools::DoNothing();
    const	auto format = GetFormat();
    const auto numLevels = GetNumLevels();
    
    if (format == TextureFormat::R32F || format == TextureFormat::G32R32F || format == TextureFormat::A32B32G32R32F)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_1(false, "����32λfloat����û��mipmaps\n");
            SetNumLevels(1);
        }
    }
    else if (format == TextureFormat::DXT1 || format == TextureFormat::DXT3 ||  format == TextureFormat::DXT5)
    {
        RENDERING_ASSERTION_1(false, "����1D����û��DXTѹ��\n");
        SetNumLevels(1);
    }
    else if (format == TextureFormat::D24S8)
    {
        RENDERING_ASSERTION_1(false, "������������2D��\n");
        SetNumLevels(1);
    }
}
 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,Texture1DImpl)

int Rendering::Texture1DImpl
    ::GetNumDimensions () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumDimensions ();
}

int Rendering::Texture1DImpl
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetDimension (index,level);
}

int Rendering::Texture1DImpl
    ::GetNumLevelBytes (int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumLevelBytes (level);
}

int Rendering::Texture1DImpl
    ::GetNumTotalBytes () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumTotalBytes ();
}

int Rendering::Texture1DImpl
    ::GetLevelOffset (int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetLevelOffset (level);
}

int Rendering::Texture1DImpl
    ::GetLength () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return GetDimension(0, 0);
}

void Rendering::Texture1DImpl
	::DoGenerateMipmaps()
{
	const auto numLevels = GetNumLevels();
	auto length = GetLength();
	auto texels = GetWriteData();
	for (auto level = 1; level < numLevels; ++level)
	{
		auto texelsNext = GetTextureData(level);
            const auto lengthNext = GetDimension(0, level);

		GenerateNextMipmap(length, texels, lengthNext, texelsNext);

		length = lengthNext;
		texels = texelsNext;
	}
}

char* Rendering::Texture1DImpl
    ::GetTextureData (int level) 
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "��Ч�ȼ���GetTextureData\n");

	return GetWriteData() + GetLevelOffset(level);
}

const char* Rendering::Texture1DImpl
	::GetTextureData( int level ) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "��Ч�ȼ���GetTextureData\n");

	return GetReadOnlyData() + GetLevelOffset(level);
}

void Rendering::Texture1DImpl
    ::GenerateNextMipmap (int length, const char* texels,int lengthNext, char* texelsNext)
{
	// ������ʱ�洢���ɵ�mipmaps��
    texelsNext;
        texels;
        length;
    
	const auto format = GetFormat();
    
	// ���ش�ԭ����ʽת��Ϊ32λRGBA��
	auto fromFunction = ColourConvertFrom::GetConvertFromFunction(format);

	// ���ش�32λRGBA����ת��Ϊ������ʽ��
        auto toFunction = ColourConvertTo::GetConvertToFunction(format);

    
    if(fromFunction != nullptr && toFunction != nullptr)
    {
        vector<char> fromVector; // ����texels����
       

        auto colour = fromFunction(fromVector);
        
		// �͵ش�����һ��miplevel��
        for (auto index = 0; index < lengthNext; ++index)
        {
            const auto base = 2 * index;
            colour[index] = 0.5f * colour[base] + 0.5f * colour[base + 1];
        }

          vector<char> toVector =  toFunction(colour);

        // ����texelsNext
    }
}

void Rendering::Texture1DImpl
    ::LoadLevelData (CoreTools::BufferSource& source)
{
    m_TextureLevelData.Load(source);
}

void Rendering::Texture1DImpl
    ::SaveLevelData (CoreTools::BufferTarget& target) const
{
    m_TextureLevelData.Save(target);
}

int Rendering::Texture1DImpl
    ::GetLevelDataStreamingSize () const
{
    return m_TextureLevelData.GetStreamingSize();
}

void Rendering::Texture1DImpl
	::SaveLevelDataToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TextureLevelData.SaveToFile(outFile);
}

void Rendering::Texture1DImpl
	::LoadLevelDataFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_9;

	return m_TextureLevelData.ReadFromFile(inFile);
}




#include STSTEM_WARNING_POP