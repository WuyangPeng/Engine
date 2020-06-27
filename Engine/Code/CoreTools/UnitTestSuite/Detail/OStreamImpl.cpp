// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.0 (2020/04/08 14:33)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamImpl.h"  
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <fstream>

using std::cout;
using std::cerr;
using std::string;
using std::ostream;
using std::ofstream;
using std::make_shared;

CoreTools::OStreamImpl
	::OStreamImpl(bool isCout)
	:m_OStream{ }, m_IsCout{ isCout }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::OStreamImpl
	::OStreamImpl(const string& fileName)
	:m_OStream{ make_shared<ofstream>(fileName,ofstream::out | ofstream::app) }, m_IsCout{ false }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OStreamImpl)

ostream& CoreTools::OStreamImpl
	::GetStream()
{
	if (m_OStream)
	{
		return *m_OStream;
	}
	else
	{
		if (m_IsCout)
			return cout;
		else
			return cerr;
	}
}

bool CoreTools::OStreamImpl
	::IsCout() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_IsCout;
}

bool CoreTools::OStreamImpl
	::IsCerr() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (m_OStream)
	{
		return false;
	}
	else
	{
		return !m_IsCout;
	}	
}

bool CoreTools::OStreamImpl
	::IsFile() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (m_OStream)
	{
		return true;
	}
	else
	{
		return false;
	}
}

