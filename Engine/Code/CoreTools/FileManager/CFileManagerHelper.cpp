// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 17:03)

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
	// ���뻺����������ڡ���֤�û���������ָ�����ֽ����ǲ����ܵġ�
	CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
	CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

	String mode{ binaryFile ? SYSTEM_TEXT("wb") : SYSTEM_TEXT("wt") };

	CFileManagerImpl manager{ fileName,mode };

	manager.WriteToFile(sizeof(char), bufferSize, buffer);
}

// static
void CoreTools::CFileManagerHelper
	::AppendToFile(const String& fileName, bool binaryFile, int bufferSize, const char* buffer)
{
	// ���뻺����������ڡ���֤�û���������ָ�����ֽ����ǲ����ܵġ�
	CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
	CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

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

