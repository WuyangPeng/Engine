// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 14:17)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_LENGTH_FLAGS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_LENGTH_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
	enum class BuffBlockSize
	{
		Size256 = 256,
		Size512 = Size256 << 1,
		Size1024 = Size512 << 1,
		Size2048 = Size512 << 2,
		Size4096 = Size512 << 3,
		Size8K = Size512 << 4,
		Size16K = Size512 << 5,
		Size32K = Size512 << 6,
		Size64K = Size512 << 7,
		Size128K = Size512 << 8,
		Size256K = Size512 << 9,
		Size512K = Size512 << 10,
		Automatic,
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_LENGTH_FLAGS_H
