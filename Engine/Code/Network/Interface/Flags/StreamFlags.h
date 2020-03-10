// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/23 16:40)


#ifndef NETWORK_BOOST_WRAPPERS_STREAM_FLAGS_H
#define NETWORK_BOOST_WRAPPERS_STREAM_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
	enum class StreamReceive  
	{		
		Head = 0,
		Content = 1
	};	
}

#endif // NETWORK_BOOST_WRAPPERS_STREAM_FLAGS_H
