// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 14:01)

#ifndef LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "LoginServer/LoginServerCore/LoginServerCoreDll.h"

#include "LoginServer/LoginServerCore/Macro/ExportMacro.h"  

namespace LoginServerCore
{
	class LOGIN_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // LOGIN_SERVER_CORE_ENGINE_PLACEHOLDER_H
