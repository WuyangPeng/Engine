// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 13:41)

#ifndef RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H
#define RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TextureLevelData.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

template <int WindowSize>
Rendering::TextureLevelData<WindowSize>
	::TextureLevelData( int numDimensions )
	:m_NumDimensions{ numDimensions }, m_NumTotalBytes{ 0 }
{
	for (auto level = 0; level < TextureMaximumMipmapLevels;++level)
	{
	    for (auto i = 0; i < WindowSize; ++i)
        {
		     m_Dimension[i][level] = 0;		 
        }

		m_NumLevelBytes[level] = 0;
		m_LevelOffsets[level] = 0;
	}

	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <int WindowSize>
bool Rendering::TextureLevelData<WindowSize>
	::IsValid() const noexcept
{
	if(0 <= m_NumLevelBytes && m_NumDimensions == WindowSize)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>
	::GetNumDimensions() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumDimensions;
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>
	::GetDimension( int index, int level ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < WindowSize && 0 <= level && level < TextureMaximumMipmapLevels,  "索引错误！");
    
    return m_Dimension[index][level];
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
	::SetDimension( int index, int level,int dimension )
{
	RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < WindowSize && 0 <= level && level < TextureMaximumMipmapLevels,"索引错误！");
    
    m_Dimension[index][level] = dimension;
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>
	::GetNumLevelBytes( int level ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");
    
    return m_NumLevelBytes[level];
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>
	::GetNumTotalBytes() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_NumTotalBytes;
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>
	::GetLevelOffset( int level ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");
    
    return m_LevelOffsets[level];
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
	::SetNumLevelBytes( int level,int numLevelBytes )
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");
    
    m_NumLevelBytes[level] = numLevelBytes;
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
	::RecountNumTotalBytes(int numLevels, TextureFlags type)
{
	RENDERING_CLASS_IS_VALID_1;

	m_NumTotalBytes = 0;
	for (auto level = 0; level < numLevels; ++level)
	{		
		m_NumTotalBytes += m_NumLevelBytes[level];		
	}

	if (type == TextureFlags::TextureCube)
    {
       m_NumTotalBytes *= 6;
    }
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
	::RecountLevelOffsets( int numLevels )
{
	RENDERING_CLASS_IS_VALID_1;

	m_LevelOffsets[0] = 0;
	for (auto level = 0; level < numLevels - 1; ++level)
	{
		m_LevelOffsets[level + 1] = m_LevelOffsets[level] + m_NumLevelBytes[level];
	}
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
    ::Load( CoreTools::BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_1;

	source.Read(m_NumDimensions);

	for(auto i = 0;i < WindowSize;++i)
	{
		source.Read(TextureMaximumMipmapLevels, m_Dimension[i]);
	}   

	source.Read(TextureMaximumMipmapLevels, m_NumLevelBytes);
	source.Read(m_NumTotalBytes);
	source.Read(TextureMaximumMipmapLevels, m_LevelOffsets);
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
    ::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.Write(m_NumDimensions);

	for(auto i = 0;i < WindowSize;++i)
	{
		target.WriteWithoutNumber(TextureMaximumMipmapLevels,m_Dimension[i]);
	}   

    target.WriteWithoutNumber(TextureMaximumMipmapLevels,m_NumLevelBytes);
    target.Write(m_NumTotalBytes);
    target.WriteWithoutNumber(TextureMaximumMipmapLevels,m_LevelOffsets);
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;    

	auto size = CORE_TOOLS_STREAM_SIZE(m_NumDimensions);

    size += WindowSize * TextureMaximumMipmapLevels * CORE_TOOLS_STREAM_SIZE(m_Dimension[0][0]);   
    size += TextureMaximumMipmapLevels * CORE_TOOLS_STREAM_SIZE(m_NumLevelBytes[0]);
    size += CORE_TOOLS_STREAM_SIZE(m_NumTotalBytes);
    size += TextureMaximumMipmapLevels * CORE_TOOLS_STREAM_SIZE(m_LevelOffsets[0]);

    return size;
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1; 
	
	outFile.Write(sizeof(int),&m_NumDimensions);

	for(auto i = 0;i < WindowSize;++i)
	{
		outFile.Write(sizeof(int),TextureMaximumMipmapLevels, m_Dimension[i]);
	}   

    outFile.Write(sizeof(int),TextureMaximumMipmapLevels, m_NumLevelBytes);
    outFile.Write(sizeof(int),&m_NumTotalBytes);
    outFile.Write(sizeof(int),TextureMaximumMipmapLevels, m_LevelOffsets);
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_1; 

	auto oldNumDimensions = m_NumDimensions;
	auto oldNumTotalBytes = m_NumTotalBytes;

	inFile.Read(sizeof(int),&m_NumDimensions);

	for(auto i = 0;i < WindowSize;++i)
	{
		inFile.Read(sizeof(int),TextureMaximumMipmapLevels,  m_Dimension[i]);
	}   

	inFile.Read(sizeof(int),TextureMaximumMipmapLevels, m_NumLevelBytes);
	inFile.Read(sizeof(int),&m_NumTotalBytes);
	inFile.Read(sizeof(int),TextureMaximumMipmapLevels,m_LevelOffsets);

	if(m_NumDimensions != WindowSize || m_NumTotalBytes < 0)
	{
		m_NumDimensions = oldNumDimensions;
		m_NumTotalBytes = oldNumTotalBytes;
		
		THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理等级数据不正确。\n"));		
	}
}

#endif // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H

