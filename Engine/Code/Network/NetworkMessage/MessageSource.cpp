// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/10 16:35)

#include "Network/NetworkExport.h"

#include "MessageSourceDetail.h" 
#include "MessageBuffer.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
Network::MessageSource
	::MessageSource(const MessageBufferSharedPtr& messageBuffer) noexcept
	:m_Source{ messageBuffer }, m_ParserStrategy{ messageBuffer->GetParserStrategy() }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageSource
	::MessageSource(MessageSource&& rhs) noexcept
	:m_Source{ move(rhs.m_Source) }, m_ParserStrategy{ rhs.m_ParserStrategy }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageSource& Network::MessageSource
	::operator=(MessageSource&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_1;

	m_Source = move(rhs.m_Source);
	m_ParserStrategy = rhs.m_ParserStrategy;

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::MessageSource
	::IsValid() const noexcept
{
	if (m_Source)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool Network::MessageSource
	::ReadBool()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	uint32_t value{ 0 };

	Read(value);

	return (value != 0);
}

void Network::MessageSource
	::ReadBool(int elementsNumber, bool* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		data[i] = ReadBool();
	}
}

string Network::MessageSource
	::ReadString()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	int32_t length{ 0 };
	Read(length);
	if (0 < length)
	{
		// ×Ö·û´®±»Ð´ÈëÎª4×Ö½ÚµÄ±¶Êý¡£
		auto padding = (length % 4);
		if (0 < padding)
		{
			padding = 4 - padding;
		}

		const char* const text = m_Source->GetCurrentReadBufferedPtr();
		string datum(text, length);

		m_Source->AddCurrentReadIndex(length + padding);

		return datum;
	}
	else
	{
		return "";
	}
}

void Network::MessageSource
	::ReadString(int elementsNumber, string* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		data[i] = ReadString();
	}
}

int Network::MessageSource ::GetBytesRead() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Source->GetCurrentReadIndex();
}

int Network::MessageSource
	::GetBytesTotal() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Source->GetCurrentWriteIndex();
}

void Network::MessageSource
	::IncrementBytesProcessed(int bytesNumber)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Source->AddCurrentReadIndex(bytesNumber);
}

void Network::MessageSource
	::Read(vector<string>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	int32_t elementsNumber{ 0 };

	Read(elementsNumber);

	if (0 < elementsNumber)
	{
		datum.resize(elementsNumber);
		ReadString(elementsNumber, datum.data());
	}
}

void Network::MessageSource
	::Read(string& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	datum = ReadString();
}



#include STSTEM_WARNING_POP


