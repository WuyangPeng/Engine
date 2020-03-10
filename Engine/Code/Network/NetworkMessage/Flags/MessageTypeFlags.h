// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/10 14:17)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
	enum class VersionsCondition
	{
		Greater = 0,
		GreaterEequal = 1,
		Equality = 2,
		LessEequal = 3,
		Less = 4,
		Range = 5, // [ ] ����
		Specific = 6,
		All = 7,
	};

	enum class MultipleMessageByteType
	{
		String = 0,
		Uint64 = 1,
		Int64 = 2,
		Uint32 = 3,
		Int32 = 4,
		Uint16 = 5,
		Int16 = 6,
		Uint8 = 7,
		Int8 = 8,
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H
