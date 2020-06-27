// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 17:03)

#include "CoreTools/CoreToolsExport.h"

#include "CFileManagerHelper.h"
#include "Environment.h"
#include "Detail/CFileManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

// static
const CoreTools::FileBuffer CoreTools::CFileManagerHelper
	::LoadFromFile(const String& fileName, bool binaryFile)
{
	String mode{ binaryFile ? SYSTEM_TEXT("rb") : SYSTEM_TEXT("rt") };

	CFileManagerImpl manager{ fileName,mode };

	auto bufferSize = boost::numeric_cast<size_t>(manager.GetFileLength());
	FileBuffer buffer{ bufferSize };

	manager.ReadFromFile(sizeof(char), buffer.GetSize(), buffer.GetBufferBegin());

	return buffer;
}

// static
void CoreTools::CFileManagerHelper
	::SaveIntoFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
	// 输入缓冲区必须存在。验证该缓冲区具有指定的字节数是不可能的。
	CORE_TOOLS_ASSERTION_0(buffer != nullptr, "传入的指针为空！");
	CORE_TOOLS_ASSERTION_2(0 < bufferSize, "传入的缓冲区大小小于或等于零！");

	String mode{ binaryFile ? SYSTEM_TEXT("wb") : SYSTEM_TEXT("wt") };

	CFileManagerImpl manager{ fileName,mode };

	manager.WriteToFile(sizeof(char), bufferSize, buffer);
}

// static
void CoreTools::CFileManagerHelper
	::AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
	// 输入缓冲区必须存在。验证该缓冲区具有指定的字节数是不可能的。
	CORE_TOOLS_ASSERTION_0(buffer != nullptr, "传入的指针为空！");
	CORE_TOOLS_ASSERTION_2(0 < bufferSize, "传入的缓冲区大小小于或等于零！");

	String mode{ binaryFile ? SYSTEM_TEXT("ab") : SYSTEM_TEXT("at") };

	CFileManagerImpl manager{ fileName,mode };

	manager.WriteToFile(sizeof(char), bufferSize, buffer);
}

const CoreTools::FileBuffer CoreTools::CFileManagerHelper
	::LoadFromFileUseEnvironment(const String& fileName, bool binaryFile)
{
	auto fullFileName = ENVIRONMENT_SINGLETON.GetPathReading(fileName);

	return LoadFromFile(fullFileName, binaryFile);
}

