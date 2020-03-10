// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 15:20)

#include "CoreTools/CoreToolsExport.h"

#include "DeleteFileToolsImpl.h"
#include "System/FileManager/File.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"

CoreTools::DeleteFileToolsImpl
	::DeleteFileToolsImpl(const String& fileName)
	:m_FileName{ StringConversion::StandardConversionCFileString(fileName) }, m_Deleted{ System::RemoveSystemFile(m_FileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::DeleteFileToolsImpl
	::~DeleteFileToolsImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	if (!m_Deleted && !System::RemoveSystemFile(m_FileName))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("…æ≥˝Œƒº˛") << m_FileName << SYSTEM_TEXT(" ß∞‹")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeleteFileToolsImpl)




