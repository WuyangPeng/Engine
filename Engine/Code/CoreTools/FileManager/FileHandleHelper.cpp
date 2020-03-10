// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 17:13)

#include "CoreTools/CoreToolsExport.h"

#include "FileHandleHelper.h"
#include "Environment.h"
#include "Detail/ReadFileHandleImpl.h"
#include "Detail/WriteFileHandleImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <boost/numeric/conversion/cast.hpp>

using boost::numeric_cast;

// static
const CoreTools::FileBuffer CoreTools::FileHandleHelper
	::LoadFromFile(const String& fileName)
{
	ReadFileHandleImpl handle{ fileName };

	auto bufferSize = boost::numeric_cast<size_t>(handle.GetFileLength());
	FileBuffer buffer{ bufferSize };

	handle.ReadFromFile(sizeof(char), buffer.GetSize(), buffer.GetBufferBegin());

	return buffer;
}

// static
void CoreTools::FileHandleHelper
	::SaveIntoFile(const String& fileName, int bufferSize, const char* buffer)
{
	CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
	CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

	WriteFileHandleImpl handle{ fileName };

	handle.WriteToFile(sizeof(char), bufferSize, buffer);
}

// static
void CoreTools::FileHandleHelper
	::AppendToFile(const String& fileName, int bufferSize, const char* buffer)
{
	CORE_TOOLS_ASSERTION_0(buffer != nullptr, "�����ָ��Ϊ�գ�");
	CORE_TOOLS_ASSERTION_2(0 < bufferSize, "����Ļ�������СС�ڻ�����㣡");

	WriteFileHandleImpl handle{ fileName,System::FileHandleCreationDisposition::OpenAlways };

	handle.AppendToFile(sizeof(char), bufferSize, buffer);
}

const CoreTools::FileBuffer CoreTools::FileHandleHelper
	::LoadFromFileUseEnvironment(const String& fileName)
{
	auto fullFileName = ENVIRONMENT_SINGLETON.GetPathReading(fileName);

	return LoadFromFile(fullFileName);
}

