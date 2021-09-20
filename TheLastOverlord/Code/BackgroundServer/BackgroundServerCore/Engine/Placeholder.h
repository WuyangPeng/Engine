// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:05)

#ifndef BACKGROUND_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define BACKGROUND_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "BackgroundServer/BackgroundServerCore/BackgroundServerCoreDll.h"

#include "BackgroundServer/BackgroundServerCore/Macro/ExportMacro.h"  

namespace BackgroundServerCore
{
	class BACKGROUND_SERVER_CORE_DEFAULT_DECLARE Placeholder
	{
	public:
		using ClassType = Placeholder;

	public:
		Placeholder();

		CLASS_INVARIANT_DECLARE;
	};
}

#endif // BACKGROUND_SERVER_CORE_ENGINE_PLACEHOLDER_H
