// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:35)

// Լ����������POD
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H

#include "CoreTools/CoreToolsDll.h"
#include "System/Helper/UnusedMacro.h"

namespace CoreTools
{
	template <typename T>
	struct MustBePod
	{
		~MustBePod()
		{
			void(*ptr)() = Constranints;

			SYSTEM_UNUSED_ARG(ptr);
		}

	private:
		static void Constranints()
		{
			union
			{
				T TIsNotPODType;
			} unionType;

			SYSTEM_UNUSED_ARG(unionType);
		}
	};

	template <typename T>
	struct MustBePodOrVoid
	{
		~MustBePodOrVoid()
		{
			void(*ptr)() = Constranints;

			SYSTEM_UNUSED_ARG(ptr);
		}

	private:
		static void Constranints()
		{
			union
			{
				T TIsNotPODTypeOrVoid;
			} unionType;

			SYSTEM_UNUSED_ARG(unionType);
		}
	};

	template <>
	struct MustBePodOrVoid<void>
	{

	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H






