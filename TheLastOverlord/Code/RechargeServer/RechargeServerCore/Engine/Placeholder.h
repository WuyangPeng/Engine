// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 18:00)

#ifndef RECHARGE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define RECHARGE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "RechargeServer/RechargeServerCore/RechargeServerCoreDll.h"

#include "RechargeServer/RechargeServerCore/Macro/ExportMacro.h"  

namespace RechargeServerCore
{
	class RECHARGE_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // RECHARGE_SERVER_CORE_ENGINE_PLACEHOLDER_H
