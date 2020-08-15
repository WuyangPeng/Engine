// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 15:03)

#include "Rendering/RenderingExport.h"

#include "TextureImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <vector>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
using std::vector;

int Rendering::TextureImpl
    ::sm_NumDimensions[System::EnumCastUnderlying(TextureFlags::Quantity)] 
{
    1,  // TextureType::Texture1D
    2,  // TextureType::Texture2D
    3,  // TextureType::Texture3D
    2   // TextureType::TextureCube
};

int Rendering::TextureImpl
    ::sm_PixelSize[System::EnumCastUnderlying(TextureFormat::Quantity)] 
{
    0,   // TextureFormat::None
    2,   // TextureFormat::R5G6B5
    2,   // TextureFormat::A1R5G5B5
    2,   // TextureFormat::A4R4G4B4
    1,   // TextureFormat::A8
    1,   // TextureFormat::L8
    2,   // TextureFormat::A8L8
    3,   // TextureFormat::R8G8B8
    4,   // TextureFormat::A8R8G8B8
    4,   // TextureFormat::A8B8G8R8
    2,   // TextureFormat::L16
    4,   // TextureFormat::G16R16
    8,   // TextureFormat::A16B16G16R16
    2,   // TextureFormat::R16F
    4,   // TextureFormat::G16R16F
    8,   // TextureFormat::A16B16G16R16F
    4,   // TextureFormat::R32F
    8,   // TextureFormat::G32R32F
    16,  // TextureFormat::A32B32G32R32F,
    0,   // TextureFormat::DXT1 (特殊处理)
    0,   // TextureFormat::DXT3 (特殊处理)
    0,   // TextureFormat::DXT5 (特殊处理)
    4    // TextureFormat::D24S8
};

bool Rendering::TextureImpl
    ::sm_Mipmapable[System::EnumCastUnderlying(TextureFormat::Quantity)] 
{
    false,  // TextureFormat::None
    true,   // TextureFormat::R5G6B5
    true,   // TextureFormat::A1R5G5B5
    true,   // TextureFormat::A4R4G4B4
    true,   // TextureFormat::A8
    true,   // TextureFormat::L8
    true,   // TextureFormat::A8L8
    true,   // TextureFormat::R8G8B8
    true,   // TextureFormat::A8R8G8B8
    true,   // TextureFormat::A8B8G8R8
    true,   // TextureFormat::L16
    true,   // TextureFormat::G16R16
    true,   // TextureFormat::A16B16G16R16
    true,   // TextureFormat::R16F
    true,   // TextureFormat::G16R16F
    true,   // TextureFormat::A16B16G16R16F
    false,  // TextureFormat::R32F
    false,  // TextureFormat::G32R32F
    false,  // TextureFormat::A32B32G32R32F,
    true,   // TextureFormat::DXT1 (特殊处理)
    true,   // TextureFormat::DXT3 (特殊处理)
    true,   // TextureFormat::DXT5 (特殊处理)
    false   // TextureFormat::D24S8
};

int Rendering::TextureImpl
	::sm_ItemSize[System::EnumCastUnderlying(TextureFormat::Quantity)] 
{
	0,   // TextureFormat::None
	2,   // TextureFormat::R5G6B5
	2,   // TextureFormat::A1R5G5B5
	2,   // TextureFormat::A4R4G4B4
	1,   // TextureFormat::A8
	1,   // TextureFormat::L8
	1,   // TextureFormat::A8L8
	1,   // TextureFormat::R8G8B8
	1,   // TextureFormat::A8R8G8B8
	1,   // TextureFormat::A8B8G8R8
	2,   // TextureFormat::L16
	2,   // TextureFormat::G16R16
	2,   // TextureFormat::A16B16G16R16
	2,   // TextureFormat::R16F
	2,   // TextureFormat::G16R16F
	2,   // TextureFormat::A16B16G16R16F
	4,   // TextureFormat::R32F
	4,   // TextureFormat::G32R32F
	4,  // TextureFormat::A32B32G32R32F,
	1,   // TextureFormat::DXT1 
	1,   // TextureFormat::DXT3 
	1,   // TextureFormat::DXT5
	4    // TextureFormat::D24S8
};

Rendering::TextureImpl
    ::TextureImpl (TextureFormat format, TextureFlags type,BufferUsage usage,int numLevels)
	: m_TextureData{ format,type,usage,numLevels }, m_TextureUserField{}, m_Data{ CalculateItemSize(format) }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureImpl
    ::~TextureImpl()
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,TextureImpl)

Rendering::TextureFormat Rendering::TextureImpl
    ::GetFormat () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureData.GetFormat();
}

Rendering::TextureFlags Rendering::TextureImpl
    ::GetTextureType () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureData.GetTextureType();
}

Rendering::BufferUsage Rendering::TextureImpl
    ::GetUsage () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureData.GetUsage();
}

int Rendering::TextureImpl
    ::GetNumLevels () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureData.GetNumLevels();
}

int Rendering::TextureImpl
    ::GetPixelSize () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
  const auto format = GetFormat();
    
    return GetPixelSize(format);
}

// static
int Rendering::TextureImpl
    ::GetPixelSize (TextureFormat format)
{
	if (TextureFormat::First <= format && format < TextureFormat::Quantity)
	{
		return sm_PixelSize[System::EnumCastUnderlying(format)];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界。\n"s));
	}
}

bool Rendering::TextureImpl
    ::IsCompressed () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureData.IsCompressed();
}

bool Rendering::TextureImpl
    ::IsMipmapable () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
const	auto format = GetFormat();

	if (TextureFormat::First <= format && format < TextureFormat::Quantity)
	{
		return sm_Mipmapable[System::EnumCastUnderlying(format)];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界。\n"s));
	}  
}

const char* Rendering::TextureImpl
    ::GetReadOnlyData () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;    
    
	return m_Data.GetReadOnlyData();
}

char* Rendering::TextureImpl
    ::GetWriteData()
{
    RENDERING_CLASS_IS_VALID_9;
    
	return m_Data.GetWriteData();
}

void Rendering::TextureImpl
    ::SetUserField (int index, int userField)
{
    RENDERING_CLASS_IS_VALID_9;
    
    return m_TextureUserField.SetUserField(index, userField);
}

int Rendering::TextureImpl
    ::GetUserField (int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_TextureUserField.GetUserField(index);
}

void Rendering::TextureImpl
    ::Load( CoreTools::BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;
    
    m_TextureData.Load(source);
    
    LoadLevelData(source);
    
    m_TextureUserField.Load(source);

	m_Data.Load(source);
}

void Rendering::TextureImpl
    ::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    
    m_TextureData.Save(target);
    
    SaveLevelData(target);
    
    m_TextureUserField.Save(target);

	m_Data.Save(target);		
}

int Rendering::TextureImpl
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
  
	auto size = m_TextureData.GetStreamingSize();

    size += GetLevelDataStreamingSize();
    size += m_TextureUserField.GetStreamingSize();
	size += m_Data.GetStreamingSize();
    
    return size;
}

// protected
void Rendering::TextureImpl
    ::SetNumLevels(int numLevels) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    
    m_TextureData.SetNumLevels(numLevels);
}

// static
int Rendering::TextureImpl
    ::CalculateNumDimensions (TextureFlags type)
{
	if (TextureFlags::Texture1D <= type && type < TextureFlags::Quantity)
	{
		return sm_NumDimensions[System::EnumCastUnderlying(type)];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界。\n"s));
	}
}

void Rendering::TextureImpl
	::SaveToFile(WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_TextureData.SaveToFile(outFile);
	SaveLevelDataToFile(outFile);
	m_TextureUserField.SaveToFile(outFile);
	m_Data.SaveToFile(outFile);
}

void Rendering::TextureImpl
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_9;

	// 已在LoadTexture读取
	// m_TextureData.ReadFromFile(inFile);
	// LoadLevelDataFromFile(inFile);

	m_TextureUserField.ReadFromFile(inFile);

const	auto numTotalBytes = GetNumTotalBytes();
	m_Data.Reset(numTotalBytes);
	m_Data.ReadFromFile(inFile);
}

void Rendering::TextureImpl
    ::ExpandFileBufferSize()
{
const	auto numTotalBytes = GetNumTotalBytes();
	const auto numLevel0Bytes = GetNumLevelBytes(0);
	m_Data.ExpandFileBufferSize(numTotalBytes, numLevel0Bytes);
}

void Rendering::TextureImpl
    ::ExpandFileBufferSizeOnCube()
{
	const auto numTotalBytes = GetNumTotalBytes();
	const auto numLevel0Bytes = GetNumLevelBytes(0);
	m_Data.ExpandFileBufferSizeOnCube(numTotalBytes, numLevel0Bytes);
}

void Rendering::TextureImpl
	::GenerateMipmaps()
{
	RENDERING_CLASS_IS_VALID_9;

	RecomputationLevelBytes();
	DoGenerateMipmaps();
}

bool Rendering::TextureImpl
	::HasMipmaps() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return GetNumLevels() == GetMaxLevels();
}

void Rendering::TextureImpl
	::RecomputationLevelBytes()
{
const	auto maxLevels = GetMaxLevels();
const	auto numLevels = GetNumLevels();
	if (numLevels != maxLevels)
	{
		SetNumLevels(maxLevels);
		VerifyNumLevels();
		ComputeNumLevelBytes();
		ExpandFileBufferSize();
	}
}

// static
int Rendering::TextureImpl
	::CalculateItemSize(TextureFormat format)
{
	if (TextureFormat::First <= format && format < TextureFormat::Quantity && 0 < sm_ItemSize[System::EnumCastUnderlying(format)])
	{
		return sm_ItemSize[System::EnumCastUnderlying(format)];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无效的纹理格式。\n"s));
	}	
}

// protected
void Rendering::TextureImpl
	::ResetTextureBufferNum()
{
const	auto numTotalBytes = GetNumTotalBytes();
	m_Data.Reset(numTotalBytes);
}

#include STSTEM_WARNING_POP