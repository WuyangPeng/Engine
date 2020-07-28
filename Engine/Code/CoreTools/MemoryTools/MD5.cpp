// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/21 13:33)

#include "CoreTools/CoreToolsExport.h"

#include "MD5.h"
#include "MD5Context.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>
#include <sstream>
#include <iomanip>
#include <vector>

using std::string;
using std::stringstream;
using std::setw;
using std::setfill;
using std::vector;
using std::hex;
using std::uppercase;
using std::array;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)

CoreTools::MD5
	::MD5()
	:m_MD5Context{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MD5)

void CoreTools::MD5
	::MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length, uint8_t* digest)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(digest != nullptr, "·µ»ØµÄ»º³åÇøÎª¿Õ£¡");

	m_MD5Context.MD5Init();

	m_MD5Context.MD5Update(buffer, length);

	return m_MD5Context.MD5Final(digest);
}

const string CoreTools::MD5
	::MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	array<uint8_t, sm_DigestSize> digest{};

	MessageDigestAlgorithm5(buffer, length, digest.data());

	return GetHexDigestWithLowercase(digest.data());
}

const string CoreTools::MD5
	::MessageDigestAlgorithm5(const string& source)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_MD5Context.MD5Init();

	if (!source.empty())
	{
		vector<char> buffer{ source.begin(),source.end() };

		m_MD5Context.MD5Update(reinterpret_cast<const uint8_t*>(buffer.data()),boost::numeric_cast<uint32_t>(buffer.size()));
	}
	else
	{
		m_MD5Context.MD5Update(nullptr, 0);
	}

	array<uint8_t, sm_DigestSize> digest{};

	m_MD5Context.MD5Final(digest.data());

	return GetHexDigestWithLowercase(digest.data());
}

const string CoreTools::MD5
	::GetHexDigestWithUppercase(const uint8_t* digest)
{
	stringstream ss{};

	for (auto i = 0; i < sm_DigestSize; ++i)
	{
		ss << hex << uppercase << setw(2) << setfill('0')
		   << static_cast<uint32_t>(digest[i]);
	}

	return ss.str();
}

const string CoreTools::MD5
	::GetHexDigestWithLowercase(const uint8_t* digest)
{
	stringstream ss{};

	for (auto i = 0; i < sm_DigestSize; ++i)
	{
		ss << hex << setw(2) << setfill('0')
		   << static_cast<uint32_t>(digest[i]);
	}

	return ss.str();
}

int CoreTools::MD5
	::GetDigestSize() noexcept
{
	return sm_DigestSize;
}
#include STSTEM_WARNING_POP