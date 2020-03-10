// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:35)

// Լ�����������С������ȣ�����������Ӳ���ܹ����������
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

#include "CoreTools/CoreToolsDll.h"
#include "System/Helper/UnusedMacro.h"

namespace CoreTools
{
	template<typename T>
	struct SizeOf
	{
		enum
		{
			Value = sizeof(T)
		};
	};

	template<>
	struct SizeOf<void>
	{
		enum
		{
			Value = 0
		};
	};

	template <typename T1, typename T2>
	struct MustBeSameSize
	{
		~MustBeSameSize()
		{
			void(*ptr)() = Constranints;

			SYSTEM_UNUSED_ARG(ptr);
		}

	private:
		static void Constranints()
		{
			const auto T1NotSameSizeAsT2 = static_cast<uint32_t>(SizeOf<T1>::Value == SizeOf<T2>::Value);

			int i[T1NotSameSizeAsT2];

			SYSTEM_UNUSED_ARG(i);
		}
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
