// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE InitTerm
	{
	public:
		using ClassType = InitTerm;
		using Initializer = void(*)();
		using Terminator = void(*)();

	public:
		static void AddInitializer(Initializer function);
		static void ExecuteInitializers();
		static void AddTerminator(Terminator function);
		static void ExecuteTerminators();

	private:
		// 这个数目必须足够大，以支持你的应用程序。如果你的应用程序触发此断言，修改这个值然后重新编译。
		// 其目标是避免执行期间premain和postmain的动态分配，从而使其更容易管理和跟踪内存使用情况。
		static constexpr auto sm_MaxElements = 256;

		static int sm_NumInitializers;
		static Initializer sm_Initializers[sm_MaxElements];

		static int sm_NumTerminators;
		static Terminator sm_Terminators[sm_MaxElements];
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
