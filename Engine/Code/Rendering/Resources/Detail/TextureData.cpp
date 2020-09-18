// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 14:56)

#include "Rendering/RenderingExport.h"

#include "TextureData.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::TextureData
    ::TextureData (TextureFormat format, TextureFlags type,BufferUsage usage, int numLevels) noexcept
	: m_Format{ format }, m_Type{ type }, m_Usage{ usage }, m_NumLevels{ numLevels }
{
   	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureData
	::TextureData() noexcept
	: m_Format{ TextureFormat::Quantity }, m_Type{ TextureFlags::Quantity }, m_Usage{ BufferUsage::Quantity }, m_NumLevels{ 0 }
{
   	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::TextureData
    ::IsValid() const noexcept
{
    if(0 <= m_NumLevels)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

Rendering::TextureFormat Rendering::TextureData
    ::GetFormat () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Format;
}

Rendering::TextureFlags Rendering::TextureData
    ::GetTextureType () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Type;
}

Rendering::BufferUsage Rendering::TextureData
    ::GetUsage () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Usage;
}

int Rendering::TextureData
    ::GetNumLevels () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_NumLevels;
}

bool Rendering::TextureData
    ::IsCompressed () const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Format == TextureFormat::DXT1 || m_Format == TextureFormat::DXT3 || m_Format == TextureFormat::DXT5;
}

void Rendering::TextureData
	::SetNumLevels( int numLevels ) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_NumLevels = numLevels;
}

void Rendering::TextureData
    ::Load( CoreTools::BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_1;
    
	source.ReadEnum(m_Format);
	source.ReadEnum(m_Type);
	source.ReadEnum(m_Usage);
    source.Read(m_NumLevels);    

	if (m_Format < TextureFormat::First && TextureFormat::Max <= m_Format && m_Type < TextureFlags::Texture1D &&
		TextureFlags::Quantity <= m_Type && m_Usage < BufferUsage::Static && BufferUsage::Quantity <= m_Usage && m_NumLevels < 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理数据不正确。\n"s));
	} 
}

void Rendering::TextureData
    ::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
   
    target->WriteEnum(m_Format);
        target->WriteEnum(m_Type);
    target->WriteEnum(m_Usage);
    target->Write(m_NumLevels);    
}

int Rendering::TextureData ::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;    
  
    auto size = CORE_TOOLS_STREAM_SIZE(m_Format);

    size += CORE_TOOLS_STREAM_SIZE(m_Type);
    size += CORE_TOOLS_STREAM_SIZE(m_Usage);
    size += CORE_TOOLS_STREAM_SIZE(m_NumLevels);   
    
    return size;
}

void Rendering::TextureData
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1; 

const	auto format = System::EnumCastUnderlying(m_Format);
	outFile.Write(sizeof(int), &format);

	const auto type = System::EnumCastUnderlying(m_Type);
	outFile.Write(sizeof(int), &type);

const	auto usage = System::EnumCastUnderlying(m_Usage);
	outFile.Write(sizeof(int), &usage);

	outFile.Write(sizeof(int), &m_NumLevels);
}

void Rendering::TextureData
	::ReadFromFile( ReadFileManager& inFile ) 
{
	auto format = 0;
	auto type = 0;
	auto usage = 0;
	auto numLevels = 0;

	inFile.Read(sizeof(int), &format);
	inFile.Read(sizeof(int), &type);
	inFile.Read(sizeof(int), &usage);
	inFile.Read(sizeof(int), &numLevels);

	if(System::EnumCastUnderlying(TextureFormat::First) <= format && format < System::EnumCastUnderlying(TextureFormat::Max) &&
	   System::EnumCastUnderlying(TextureFlags::Texture1D) <= type && type < System::EnumCastUnderlying(TextureFlags::Quantity) &&
	   System::EnumCastUnderlying(BufferUsage::Static) <= usage && usage < System::EnumCastUnderlying(BufferUsage::Quantity) && 0 <= numLevels)
	{
		m_Format = System::UnderlyingCastEnum<TextureFormat>(format);
		m_Type = System::UnderlyingCastEnum<TextureFlags>(type);
		m_Usage = System::UnderlyingCastEnum<BufferUsage>(usage);
		m_NumLevels = numLevels;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理数据不正确。\n"s));
	}
}

#include STSTEM_WARNING_POP 
