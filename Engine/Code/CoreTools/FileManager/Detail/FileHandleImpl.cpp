// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 15:22)

#include "CoreTools/CoreToolsExport.h"

#include "FileHandleImpl.h"
#include "System/FileManager/File.h"
#include "System/Helper/PragmaWarning/Format.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::FileHandleImpl
	::FileHandleImpl(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation)
	:m_FileName{ fileName }, m_File{ System::CreateSystemFile(fileName,access, shareMode,creation) }
{
	if (!System::IsFileHandleValid(m_File))
	{
		THROW_EXCEPTION((Error::Format{ SYSTEM_TEXT("打开文件“%1%”失败！") } % m_FileName).str());
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::FileHandleImpl
	::~FileHandleImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	if (!System::CloseSystemFile(m_File))
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
			<< SYSTEM_TEXT("关闭文件")
			<< m_FileName
			<< SYSTEM_TEXT("失败！")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::FileHandleImpl
	::IsValid() const noexcept
{
	if (System::IsFileHandleValid(m_File))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint64_t CoreTools::FileHandleImpl
	::GetFileLength() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	uint64_t size{};

	if (System::GetFileLength(m_File, size))
	{
		return size;
	}
	else
	{
		THROW_WINDOWS_EXCEPTION;
	}
}

void CoreTools::FileHandleImpl
	::ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备写入的数据无效！");

	System::WindowDWord in{ 0 };
	auto readNumber = boost::numeric_cast<System::WindowDWord>(itemSize * itemsNumber);

	if (!System::ReadSystemFile(m_File, data, readNumber, &in) || in != readNumber)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("读入文件数据错误！"));
	}
}

void CoreTools::FileHandleImpl
	::WriteToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备读取的数据无效！");

	System::WindowDWord out{ 0 };
	auto writeNumber = boost::numeric_cast<System::WindowDWord>(itemSize * itemsNumber);

	if (!System::WriteSystemFile(m_File, data, writeNumber, &out) || out != writeNumber)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数据写入文件错误！"));
	}
}

void CoreTools::FileHandleImpl
	::AppendToFile(size_t itemSize, size_t itemsNumber, const void* data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
	CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备读取的数据无效！");

	System::WindowDWord out{ 0 };
	auto writeNumber = boost::numeric_cast<System::WindowDWord>(itemSize * itemsNumber);

	if (!System::AppendSystemFile(m_File, data, writeNumber, &out) || out != writeNumber)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数据写入文件错误！"));
	}
}
