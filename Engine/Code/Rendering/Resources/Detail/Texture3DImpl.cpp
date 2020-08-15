// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 14:39)

#include "Rendering/RenderingExport.h"

#include "Texture3DImpl.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/ColourConvertTo.h"
#include "Rendering/DataTypes/ColourConvertFrom.h"
#include "Rendering/Resources/TextureLevelDataDetail.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

#include <vector>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
 #include SYSTEM_WARNING_DISABLE(26455)
using std::vector;

Rendering::Texture3DImpl
    ::Texture3DImpl(TextureFormat format, int dimension0,int dimension1,int dimension2,int numLevels,BufferUsage usage)
	:ParentType{ format, TextureFlags::Texture3D, usage, numLevels },m_TextureLevelData{ CalculateNumDimensions(TextureFlags::Texture3D) }
{
    RENDERING_ASSERTION_0(0 < dimension0, "dimension0 必须是正数\n");
    RENDERING_ASSERTION_0(0 < dimension1, "dimension1 必须是正数\n");
    RENDERING_ASSERTION_0(0 < dimension2, "dimension2 必须是正数\n");
    
    ResetDimension(dimension0,dimension1,dimension2);
    VerifyNumLevels();
    ComputeNumLevelBytes();
	ResetTextureBufferNum();
    
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture3DImpl
	::Texture3DImpl()
	:ParentType{ TextureFormat::A8R8G8B8, TextureFlags::Texture3D, BufferUsage::Texture, 0 },m_TextureLevelData{ CalculateNumDimensions(TextureFlags::Texture3D) }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::Texture3DImpl
    ::ResetDimension(int dimension0,int dimension1,int dimension2)
{
    m_TextureLevelData.SetDimension(0,0,dimension0);
    m_TextureLevelData.SetDimension(1,0,dimension1);
    m_TextureLevelData.SetDimension(2,0,dimension2);
    
 const auto maxLevels = GetMaxLevels();
    const auto numLevels = GetNumLevels();
    
    RENDERING_ASSERTION_0(0 <= numLevels && numLevels <= maxLevels, "numLevels无效！\n");
    
    if (numLevels == 0)
    {
		// 用户希望的最大数量的级别。
        SetNumLevels(maxLevels);
    }
}

int Rendering::Texture3DImpl
    ::GetMaxLevels() const
{
	auto logDimension0 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetWidth());
	auto logDimension1 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetHeight());
	auto logDimension2 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetThickness());
	auto maxLevels = logDimension0;
    
    if(maxLevels < logDimension1)
    {
        maxLevels = logDimension1;
    }
    
    if(maxLevels < logDimension2)
    {
        maxLevels = logDimension2;
    }
    
    return maxLevels + 1;
}

// private
void Rendering::Texture3DImpl
    ::ComputeNumLevelBytes ()
{
const	auto type = GetTextureType();
	auto dimension0 = GetWidth ();
	auto dimension1 = GetHeight ();
	auto dimension2 = GetThickness ();
        const auto numLevels = GetNumLevels();
    
    for (auto level = 0; level < numLevels; ++level)
    {
        m_TextureLevelData.SetNumLevelBytes(level, CalculateNumLevelBytes(dimension0,dimension1,dimension2));
        m_TextureLevelData.SetDimension(0,level,dimension0);
        m_TextureLevelData.SetDimension(1,level,dimension1);
        m_TextureLevelData.SetDimension(2,level,dimension2);
        
        if (1 < dimension0)
        {
            dimension0 >>= 1;
        }
        
        if (1 < dimension1)
        {
            dimension1 >>= 1;
        }
        
        if (1 < dimension2)
        {
            dimension2 >>= 1;
        }
    }
    
	m_TextureLevelData.RecountNumTotalBytes(numLevels, type);
    m_TextureLevelData.RecountLevelOffsets(numLevels);
}

// private
int  Rendering::Texture3DImpl
    ::CalculateNumLevelBytes(int dimension0,int dimension1,int dimension2)
{
	const auto format = GetFormat();
    
    return  GetPixelSize(format) * dimension0 * dimension1 * dimension2;
}

// private
void Rendering::Texture3DImpl
    ::VerifyNumLevels()
{
    CoreTools::DoNothing();
	const auto format = GetFormat();
const	auto numLevels = GetNumLevels();
    
    if (format == TextureFormat::R32F || format == TextureFormat::G32R32F || format == TextureFormat::A32B32G32R32F)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_1(false, "对于32位float纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
    else if (format == TextureFormat::DXT1 || format == TextureFormat::DXT3 || format == TextureFormat::DXT5)
    {
        RENDERING_ASSERTION_1(false, "对于3D纹理没有DXT压缩\n");
        SetNumLevels(1);
    }
    else if (format == TextureFormat::D24S8)
    {
        RENDERING_ASSERTION_1(false, "深度纹理必须是2D\n");
        SetNumLevels(1);
    }
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,Texture3DImpl)

int Rendering::Texture3DImpl
    ::GetNumDimensions () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumDimensions ();
}

int Rendering::Texture3DImpl
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetDimension (index,level);
}

int Rendering::Texture3DImpl
    ::GetNumLevelBytes (int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumLevelBytes (level);
}

int Rendering::Texture3DImpl
    ::GetNumTotalBytes () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetNumTotalBytes ();
}

int Rendering::Texture3DImpl
    ::GetLevelOffset (int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureLevelData.GetLevelOffset (level);
}

int Rendering::Texture3DImpl
    ::GetWidth () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return GetDimension(0, 0);
}

int Rendering::Texture3DImpl
    ::GetHeight () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return GetDimension(1, 0);
}

int Rendering::Texture3DImpl
    ::GetThickness () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return GetDimension(2, 0);
}

void Rendering::Texture3DImpl
    ::DoGenerateMipmaps ()
{
	const auto numLevels = GetNumLevels();
	auto width = GetWidth();
	auto height = GetHeight();
	auto thickness = GetThickness();
	auto texels = GetWriteData();
    for (auto level = 1; level < numLevels; ++level)
    {
		auto texelsNext = GetTextureData(level);
	const	auto widthNext = GetDimension(0,level);
	const	auto heightNext = GetDimension(1,level);
	const	auto thicknessNext = GetDimension(2,level);
        
        GenerateNextMipmap(width, height,thickness,texels, widthNext,heightNext, thicknessNext,texelsNext);

        width = widthNext;
        height = heightNext;
        thickness = thicknessNext;
        texels = texelsNext;
    }
}

char* Rendering::Texture3DImpl
    ::GetTextureData (int level) 
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetData\n");

	return const_cast<char*>(static_cast<const ClassType*>(this)->GetTextureData(level));
}

const char* Rendering::Texture3DImpl
	::GetTextureData( int level ) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetTextureData\n");

	return GetReadOnlyData() + GetLevelOffset(level);
}

void Rendering::Texture3DImpl
    ::GenerateNextMipmap (int width, int height,int thickness,const char* texels,int widthNext, int heightNext,int thicknessNext, char* texelsNext)
{
const	auto widthHeight = width * height;
    
	// 用于临时存储生成的mipmaps。
    vector<FloatColour> colour(widthHeight * thickness);
    
const	auto format = GetFormat();
    
	// 像素从原生格式转换为32位RGBA。
	auto fromFunction = ColourConvertFrom::sm_FromFunction[System::EnumCastUnderlying(format)];

	// 像素从32位RGBA纹理转换为本机格式。
	auto toFunction = ColourConvertTo::sm_ToFunction[System::EnumCastUnderlying(format)];
    
    if(fromFunction != nullptr && toFunction != nullptr)
    {
	const	auto numTexels = widthHeight * thickness;
        
        fromFunction(numTexels, texels, &colour[0]);
        
		// 就地创建下一个miplevel。
        for (auto thicknessIndex = 0; thicknessIndex < thicknessNext; ++thicknessIndex)
        {
            for (auto heightIndex = 0; heightIndex < heightNext; ++heightIndex)
            {
                for (auto widthIndex = 0; widthIndex < widthNext; ++widthIndex)
                {
				const	auto index = widthIndex + widthNext * (heightIndex + heightNext * thicknessIndex);
				const	auto base = 2 * (widthIndex + width *  (heightIndex + height * thicknessIndex));
				const	auto fourthIndex = base + width + 1;
				const	auto eighthIndex = base + width + widthHeight + 1;
                    
					if(eighthIndex < boost::numeric_cast<int>(colour.size()))
					{
						colour[index] = 0.125f * colour[base] + 
						                0.125f * colour[base + 1] +
										0.125f * colour[base + width] + 
										0.125f * colour[fourthIndex] +
										0.125f * colour[base + widthHeight] +
										0.125f * colour[base + widthHeight + 1] +
										0.125f * colour[base + width + widthHeight] +
										0.125f * colour[eighthIndex];
					}
					else if(fourthIndex < boost::numeric_cast<int>(colour.size()))
					{
						colour[index] = 0.25f * colour[base] + 
						                0.25f * colour[base + 1] +
										0.25f * colour[base + width] + 
										0.25f * colour[fourthIndex];
					}
					else
					{
						colour[index] = 0.5f * colour[base] + 
						                0.5f * colour[base + 1];
					} 
                }
            }
        }

	const	auto numTexelsNext = widthNext * heightNext * thicknessNext;
        
        toFunction(numTexelsNext,  &colour[0], texelsNext);
    }
}

void Rendering::Texture3DImpl
    ::LoadLevelData (CoreTools::BufferSource& source)
{
    m_TextureLevelData.Load(source);
}

void Rendering::Texture3DImpl
    ::SaveLevelData (CoreTools::BufferTarget& target) const
{
    m_TextureLevelData.Save(target);
}

int Rendering::Texture3DImpl
    ::GetLevelDataStreamingSize () const
{
    return m_TextureLevelData.GetStreamingSize();
}

void Rendering::Texture3DImpl
	::SaveLevelDataToFile (WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_TextureLevelData.SaveToFile(outFile);
}

void Rendering::Texture3DImpl
	::LoadLevelDataFromFile (ReadFileManager& inFile)
{
	RENDERING_CLASS_IS_VALID_9;

	m_TextureLevelData.ReadFromFile(inFile);
}

#include STSTEM_WARNING_POP