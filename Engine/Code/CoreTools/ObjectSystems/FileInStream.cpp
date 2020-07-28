// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:52)

#include "CoreTools/CoreToolsExport.h"

#include "FileInStream.h"
#include "OutTopLevel.h"
#include "Stream.h"
#include "BufferInStream.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/VersionInformation/Version.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
using std::make_shared;

CoreTools::FileInStream
	::FileInStream(const String& fileName)
	:m_InTopLevel{}
{
	Load(fileName);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::FileInStream
	::Load(const System::String& fileName)
{
	ReadFileManager manager{ fileName };

	auto readSize = manager.GetFileByteSize();

	// 获取该文件的版本。
	auto version = Version::GetVersion();

	const auto length = version.length();
	if (readSize < boost::numeric_cast<int>(length + 1))
	{
		THROW_EXCEPTION(fileName + SYSTEM_TEXT("版本字符串不存在或者存储的版本字符串不够大"));
	}

	BufferInStream::FileBufferPtr bufferInformation{ make_shared<FileBuffer>(readSize) };

	manager.Read(sizeof(char), boost::numeric_cast<int>(bufferInformation->GetSize()), bufferInformation->GetBufferBegin());

	string fileVersion{ bufferInformation->GetBufferBegin(), length };

	// 比较所需的文件版本。
	if (fileVersion != version)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("版本字符串不匹配！"s));
	}

	// 从缓冲区重构场景图。
	BufferInStream stream{ bufferInformation,boost::numeric_cast<int>(length) };

	m_InTopLevel = stream.GetTopLevel();
}

 

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileInStream)

CoreTools::InTopLevel CoreTools::FileInStream
	::GetInTopLevel() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_InTopLevel;
}



