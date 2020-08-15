// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:05)

#include "Rendering/RenderingExport.h"

#include "TextureUserField.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(6386)
#include SYSTEM_WARNING_DISABLE(6385)
Rendering::TextureUserField
    ::TextureUserField ()     noexcept
{
	for (auto i = 0; i < TextureMaxUserFields; ++i)
	{
		m_UserField[i] = 0;
	}
	
   	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,TextureUserField)

void Rendering::TextureUserField
    ::SetUserField (int index, int userField)
{
	RENDERING_CLASS_IS_VALID_9;
	RENDERING_ASSERTION_0(0 <= index && index < TextureMaxUserFields, "À˜“˝¥ÌŒÛ£°");
    
    m_UserField[index] = userField;
}

int Rendering::TextureUserField
    ::GetUserField (int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < TextureMaxUserFields,  "À˜“˝¥ÌŒÛ£°");
    
    return m_UserField[index];
}

void Rendering::TextureUserField
    ::Load( CoreTools::BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_9;
    
	source.Read(TextureMaxUserFields, m_UserField);   
}

void Rendering::TextureUserField
    ::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
   
    target.WriteWithoutNumber(TextureMaxUserFields,m_UserField);    
}

int Rendering::TextureUserField
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;    
  
    return TextureMaxUserFields * CORE_TOOLS_STREAM_SIZE(m_UserField[0]);
}

void Rendering::TextureUserField
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9; 

	outFile.Write(sizeof(int),TextureMaxUserFields,m_UserField);
}

void Rendering::TextureUserField
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_9;  

	inFile.Read(sizeof(int),TextureMaxUserFields,m_UserField);
}
#include STSTEM_WARNING_POP