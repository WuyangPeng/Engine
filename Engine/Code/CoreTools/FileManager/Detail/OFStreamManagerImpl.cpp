// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamManagerImpl.h"
#include "OFStreamSeekManager.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/Format.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::locale;
using namespace std::literals;

CoreTools::OFStreamManagerImpl
	::OFStreamManagerImpl(const String& fileName, bool addition)
	:m_OStream{}, m_FileName{ fileName }
{
	if (!m_FileName.empty())
	{
		OpenFile(addition);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("文件名为空！"s));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::OFStreamManagerImpl
	::OpenFile(bool addition)
{
	OFileStream::openmode mode{ OFileStream::out };
	if (addition)
	{
		mode |= OFileStream::app;
	}

	m_OStream.open(m_FileName.c_str(), mode);

	if (!m_OStream)
	{
		THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("打开文件%1%失败！")) % m_FileName).str());
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::OFStreamManagerImpl
	::IsValid() const noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		if (!m_FileName.empty() && m_OStream)
			return true;
		else
			return false;
		#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26492)
CoreTools::OFStreamManagerImpl::PosType CoreTools::OFStreamManagerImpl
	::GetOFStreamSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	const OFileStream::pos_type errorPosition{ -1 };

	auto thisImpl = const_cast<OFStreamManagerImpl*>(this);

	OFStreamSeekManager manager{ thisImpl->m_OStream };

	thisImpl->SeekEnd();

	const auto endPosition = thisImpl->m_OStream.tellp();

	if (endPosition != errorPosition)
		return endPosition;
	else
		return 0;
}
#include STSTEM_WARNING_POP

// private
void CoreTools::OFStreamManagerImpl
	::SeekEnd()
{
	m_OStream.seekp(0, OFileStream::end);
}

CoreTools::OFStreamManagerImpl& CoreTools::OFStreamManagerImpl
	::operator<<(const String& message)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_OStream << message;

	return *this;
}

void CoreTools::OFStreamManagerImpl
	::SetSimplifiedChinese()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

#if !defined(TCRE_USE_GCC)
	locale chs{ "chs" };

	m_OStream.imbue(chs);
#endif // !defined(TCRE_USE_GCC)
}
