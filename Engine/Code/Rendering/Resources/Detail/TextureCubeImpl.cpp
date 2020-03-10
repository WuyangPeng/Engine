// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 14:50)

#include "Rendering/RenderingExport.h"

#include "TextureCubeImpl.h"
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

Rendering::TextureCubeImpl
    ::TextureCubeImpl(TextureFormat format, int dimension,int numLevels,BufferUsage usage)
	:ParentType{ format, TextureFlags::TextureCube, usage, numLevels },
	 m_TextureLevelData{ CalculateNumDimensions(TextureFlags::TextureCube) }
{
    RENDERING_ASSERTION_0(0 < dimension, "dimension 必须是正数\n");
    
    ResetDimension(dimension);
    VerifyNumLevels();
    ComputeNumLevelBytes();
	ResetTextureBufferNum();
    
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureCubeImpl
	::TextureCubeImpl()
	:ParentType{ TextureFormat::A8R8G8B8, TextureFlags::TextureCube, BufferUsage::Texture, 0 },
	m_TextureLevelData{ CalculateNumDimensions(TextureFlags::TextureCube) }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::TextureCubeImpl
    ::ResetDimension(int dimension)
{
    m_TextureLevelData.SetDimension(0,0,dimension);
    m_TextureLevelData.SetDimension(1,0,dimension);
    
    auto maxLevels = GetMaxLevels();
	auto numLevels = GetNumLevels();
    
    RENDERING_ASSERTION_0(0 <= numLevels && numLevels <= maxLevels, "numLevels无效！\n");
    
    if (numLevels == 0)
    {
        SetNumLevels(maxLevels);
    }
}

int Rendering::TextureCubeImpl
    ::GetMaxLevels() const
{
	auto logDimension = Mathematics::BitHacks::Log2OfPowerOfTwo(GetWidth());
    
    return logDimension + 1;
}

// private
void Rendering::TextureCubeImpl
    ::ComputeNumLevelBytes ()
{
	auto type = GetTextureType();
	auto dimension0 = GetWidth ();
	auto dimension1 = GetHeight ();
	auto numLevels = GetNumLevels();
    
    for (auto level = 0; level < numLevels; ++level)
    {
        m_TextureLevelData.SetNumLevelBytes(level,CalculateNumLevelBytes(dimension0));
        m_TextureLevelData.SetDimension(0,level,dimension0);
        m_TextureLevelData.SetDimension(1,level,dimension1);
        
        if (1 < dimension0)
        {
            dimension0 >>= 1;
        }
        
        if (1 < dimension1)
        {
            dimension1 >>= 1;
        }
    }

	m_TextureLevelData.RecountNumTotalBytes(numLevels, type);
    m_TextureLevelData.RecountLevelOffsets(numLevels);
}

// private
int Rendering::TextureCubeImpl
    ::CalculateNumLevelBytes(int dimension)
{
	auto format = GetFormat();
    
    if (format == TextureFormat::DXT1)
    {
		auto max0 = dimension / 4;
        if (max0 < 1)
        {
            max0 = 1;
        }
		auto max1 = dimension / 4;
        if (max1 < 1)
        {
            max1 = 1;
        }
        
        return 8 * max0 * max1;
    }
    else if (format == TextureFormat::DXT3 || format == TextureFormat::DXT5)
    {
		auto max0 = dimension / 4;
        if (max0 < 1)
        {
            max0 = 1;
        }
		auto max1 = dimension / 4;
        if (max1 < 1)
        {
            max1 = 1;
        }
        
        return 16 * max0 * max1;
    }
    else
    {
        return GetPixelSize(format) * dimension * dimension;
    }
}

// private
void Rendering::TextureCubeImpl
    ::VerifyNumLevels()
{
	auto format = GetFormat();
	auto numLevels = GetNumLevels();
    
    if (format == TextureFormat::R32F || format == TextureFormat::G32R32F ||  format == TextureFormat::A32B32G32R32F)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_1(false, "对于32位float纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
    else if (format == TextureFormat::D24S8)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_1(false, "深度纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
}

Rendering::TextureCubeImpl
    ::~TextureCubeImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,TextureCubeImpl)

int Rendering::TextureCubeImpl
    ::GetNumDimensions () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumDimensions ();
}

int Rendering::TextureCubeImpl
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetDimension (index,level);
}

int Rendering::TextureCubeImpl
    ::GetNumLevelBytes (int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumLevelBytes (level);
}

int Rendering::TextureCubeImpl
    ::GetNumTotalBytes () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumTotalBytes ();
}

int Rendering::TextureCubeImpl
    ::GetLevelOffset (int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetLevelOffset (level);
}

int Rendering::TextureCubeImpl
    ::GetWidth () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return GetDimension(0, 0);
}

int Rendering::TextureCubeImpl
    ::GetHeight () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return GetDimension(1, 0);
}

void Rendering::TextureCubeImpl
    ::DoGenerateMipmaps ()
{
    RENDERING_CLASS_IS_VALID_9; 
    
	for (auto face = 0; face < 6; ++face)
	{
		auto numLevels = GetNumLevels();
		auto dimension = GetWidth();

		auto faceOffset = face * GetNumTotalBytes() / 6;
		auto texels = GetWriteData() + faceOffset;

		for (auto level = 1; level < numLevels; ++level)
		{
			auto texelsNext = GetTextureData(face,level);
			auto dimensionNext = GetDimension(0,level);

			GenerateNextMipmap(dimension, texels, dimensionNext, texelsNext);

			dimension = dimensionNext;
			texels = texelsNext;
		}
	}   
}

char* Rendering::TextureCubeImpl
    ::GetTextureData (int face,int level) 
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetData\n");
    RENDERING_ASSERTION_0(0 <= face && face < 6, "无效面在GetData\n");
    
	return const_cast<char*>(static_cast<const ClassType*>(this)->GetTextureData(face,level));
}

const char* Rendering::TextureCubeImpl
	::GetTextureData( int face,int level ) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetData\n");
	RENDERING_ASSERTION_0(0 <= face && face < 6, "无效面在GetData\n");

	auto faceOffset = face * GetNumTotalBytes() / 6;
	return GetReadOnlyData() + faceOffset + GetLevelOffset(level);
}

void Rendering::TextureCubeImpl
    ::GenerateNextMipmap (int dimension, const char* texels, int dimensionNext, char* texelsNext)
{
    vector<FloatColour> colour(dimension * dimension);
    
	auto format = GetFormat();
  
	auto fromFunction = ColourConvertFrom::sm_FromFunction[System::EnumCastUnderlying(format)];

	auto toFunction = ColourConvertTo::sm_ToFunction[System::EnumCastUnderlying(format)];
    
    if(fromFunction != nullptr && toFunction != nullptr)
    {
		auto numTexels = dimension * dimension;
        
        fromFunction(numTexels, texels, &colour[0]);
        
        for (auto heightIndex = 0; heightIndex < dimensionNext; ++heightIndex)
        {
            for (auto widthIndex = 0; widthIndex < dimensionNext; ++widthIndex)
            {
				auto index = widthIndex + dimensionNext * heightIndex;
				auto base = 2 * (widthIndex + dimension * heightIndex);
				auto fourthIndex = base + dimension + 1;
                
				if (fourthIndex < boost::numeric_cast<int>(colour.size()))
				{
					colour[index] = 0.25f * colour[base] + 
					                0.25f * colour[base + 1] +
									0.25f * colour[base + dimension] +
									0.25f * colour[fourthIndex];
				}
				else
				{
					colour[index] = 0.5f * colour[base] + 
					                0.5f * colour[base + 1];
				}
            }
        }

		auto numTexelsNext = dimensionNext * dimensionNext;
        
        toFunction(numTexelsNext,  &colour[0], texelsNext);
    }
}

void Rendering::TextureCubeImpl
    ::LoadLevelData (CoreTools::BufferSource& source)
{
    m_TextureLevelData.Load(source);
}

void Rendering::TextureCubeImpl
    ::SaveLevelData (CoreTools::BufferTarget& target) const
{
    m_TextureLevelData.Save(target);
}

int Rendering::TextureCubeImpl
    ::GetLevelDataStreamingSize () const
{
    return m_TextureLevelData.GetStreamingSize();
}

void Rendering::TextureCubeImpl
	::SaveLevelDataToFile (WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_TextureLevelData.SaveToFile(outFile);
}

void Rendering::TextureCubeImpl
	::LoadLevelDataFromFile (ReadFileManager& inFile)
{
	RENDERING_CLASS_IS_VALID_9;

	m_TextureLevelData.ReadFromFile(inFile);
}

void Rendering::TextureCubeImpl
	::ExpandFileBufferSize()
{
	ExpandFileBufferSizeOnCube();
}

