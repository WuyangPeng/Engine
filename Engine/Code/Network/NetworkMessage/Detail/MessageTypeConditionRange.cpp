// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 16:26)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionRange.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MessageTypeConditionRange
	::MessageTypeConditionRange(int beginVersion, int endVersion)
	:ParentType{}, m_BeginVersion{ beginVersion }, m_EndVersion{ endVersion }
{
	if (m_EndVersion < m_BeginVersion)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("起始版本号大于结束版本号。"));
	}

	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageTypeConditionRange
	::~MessageTypeConditionRange()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::MessageTypeConditionRange
	::IsValid() const noexcept
{
	if (m_BeginVersion <= m_EndVersion)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool Network::MessageTypeConditionRange
	::IsVersionsConform(int version) const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_BeginVersion <= version && version <= m_EndVersion;
}

int Network::MessageTypeConditionRange
	::GetMinVersion() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_BeginVersion;
}

int Network::MessageTypeConditionRange
	::GetMaxVersion() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_EndVersion;
}

