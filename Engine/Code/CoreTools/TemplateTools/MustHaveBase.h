// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:37)

// 约束：类D是类B的派生类或相同类型
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H

#include "CoreTools/CoreToolsDll.h"
#include "System/Helper/UnusedMacro.h"

namespace CoreTools
{
	template <typename Derive, typename Base>
	struct MustHaveBase
	{
		~MustHaveBase()
		{
			void(*ptr)(Derive*, Base*) = Constranints;

			SYSTEM_UNUSED_ARG(ptr);
		}

	private:
		static void Constranints(Derive* derivePtr, Base* basePtr)
		{
			basePtr = derivePtr;

			SYSTEM_UNUSED_ARG(basePtr);
		}
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H

