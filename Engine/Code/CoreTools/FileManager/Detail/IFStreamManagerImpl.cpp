// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.3 (2020/03/03 19:27)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManagerImpl.h"
#include "IFStreamSeekManager.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include <sstream>

using std::locale;

CoreTools::IFStreamManagerImpl
	::IFStreamManagerImpl(const String& fileName)
	:m_IStream{ fileName }, m_FileName{ fileName }
{
	if (!m_IStream)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("打开文件") + m_FileName + SYSTEM_TEXT("失败！"));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::IFStreamManagerImpl
	::IsValid() const noexcept
{
	if (!m_FileName.empty() && m_IStream)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::String CoreTools::IFStreamManagerImpl
	::BackupFile() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto newName = GetBackupName();
	System::OFileStream os{ newName,System::OFileStream::app };

	if (os)
	{
		CopyContentToStream(&os);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("备份文件失败！"));
	}

	return newName;
}

// private
System::String CoreTools::IFStreamManagerImpl
	::GetBackupName() const
{
	String newName{ m_FileName };

	const String dot{ SYSTEM_TEXT(".") };
	 
	auto nowTime = boost::posix_time::second_clock::local_time(); 

	Error::Format basicFormat{ SYSTEM_TEXT("(%1%).") };
	basicFormat % boost::posix_time::to_iso_string_type<System::TChar>(nowTime);

	boost::replace_last(newName, dot, basicFormat.str()); 

	return newName;
}

// priavte
void CoreTools::IFStreamManagerImpl
	::CopyContentToStream(OStream* osPtr) const
{
	CORE_TOOLS_ASSERTION_0(osPtr != nullptr, "指针无效");

	auto thisImpl = const_cast<IFStreamManagerImpl*>(this);
	IFStreamSeekManager manager{ thisImpl->m_IStream };

	auto loc = m_IStream.getloc();

	osPtr->imbue(loc);

	*osPtr << m_IStream.rdbuf();
}

System::String CoreTools::IFStreamManagerImpl
	::GetFileContent() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	System::OStringStream os{};

	if (os)
	{
		CopyContentToStream(&os);
		return os.str();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("获取文件内容失败！"));
	}
}

void CoreTools::IFStreamManagerImpl
	::SetSimplifiedChinese()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

#if !defined(TCRE_USE_GCC)
	locale chs{ "chs" };
	m_IStream.imbue(chs);
#endif // !defined(TCRE_USE_GCC)
}
