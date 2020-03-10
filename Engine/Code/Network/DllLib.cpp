// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/09 19:17)

// 网络库（Network）封装了引擎的网络层调用。
// 网络库位于引擎的第三层，只允许调用引擎中的System、CoreTools库，并使用boost、stlsoft和ACE工具库。

// 网络库包含以下模块：
// 1.	Helper（帮助）
// 2.	Configuration（网络库配置）
// 3.	NetworkMessage（网络消息）
// 4.	Interface（网络库接口）
// 5.	ACEWrappers（ACE包装器）
// 6.	BoostWrappers（boost包装器）
// 7.	NetworkWrappers（Network包装器）
// 8.	SocketWrappers（socket包装器）
// 9.	Openssl（Openssl）

#include "Network/NetworkExport.h"

#include "Network/Network.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_NETWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_NETWORK_STATIC

	namespace Network
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_NETWORK_STATIC