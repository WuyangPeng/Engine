// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:37)

// Լ����������԰��±����
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H

#include "CoreTools/CoreToolsDll.h"
#include "System/Helper/UnusedMacro.h"

namespace CoreTools
{
	template <typename T>
	struct MustBeSubscriptable
	{
		~MustBeSubscriptable()
		{
			void(*ptr)(const T&) = Constranints;

			SYSTEM_UNUSED_ARG(ptr);
		}

	private:
		static void Constranints(const T& TIsNoSubscriptable)
		{
			auto size = sizeof(TIsNoSubscriptable[0]);

			SYSTEM_UNUSED_ARG(size);
			auto value = TIsNoSubscriptable[0];
			SYSTEM_UNUSED_ARG(value);
		}
	};

	template <typename T>
	struct MustBeSubscriptableAsDecayablePointer
	{
		~MustBeSubscriptableAsDecayablePointer()
		{
			void(*ptr)(const T&) = Constranints;

			SYSTEM_UNUSED_ARG(ptr);
		}

	private:
		static void Constranints(T const& TIsNoSubscriptableAsDecayablePointer)
		{
			auto size = sizeof(0[TIsNoSubscriptableAsDecayablePointer]);

			SYSTEM_UNUSED_ARG(size);
			SYSTEM_UNUSED_ARG(0[TIsNoSubscriptableAsDecayablePointer]);
		}
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SUBSCRIPTABLE_H
