// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.4 (2020/03/11 18:55)

// 网络库单元测试包含以下模块：
// 1.	Helper（帮助）
// 2.	Interface（网络库接口）
// 3.	Configuration（网络库配置）
// 4.	ACEWrappers（ACE包装器）
// 5.	BoostWrappers（boost包装器）
// 6.	NetworkWrappers（Network包装器）
// 7.	SocketWrappers（socket包装器）
// 8.	NetworkMessage（网络消息）
// 9.	Openssl（Openssl）

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Network/NetworkLib.h"

  #ifdef NETWORK_USE_ACE
    #ifdef _DEBUG
        #pragma comment(lib, "ACEd.lib")
    #else  // !_DEBUG
        #pragma comment(lib, "ACE.lib")
    #endif  // _DEBUG
#endif  // NETWORK_USE_ACE
