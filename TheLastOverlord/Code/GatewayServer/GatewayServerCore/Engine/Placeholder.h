// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 10:03)

#ifndef GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GatewayServer/GatewayServerCore/GatewayServerCoreDll.h"

#include "GatewayServer/GatewayServerCore/Macro/ExportMacro.h"  

namespace GatewayServerCore
{
	class GATEWAY_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H
