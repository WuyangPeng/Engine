// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

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
		// �����Ŀ�����㹻����֧�����Ӧ�ó���������Ӧ�ó��򴥷��˶��ԣ��޸����ֵȻ�����±��롣
		// ��Ŀ���Ǳ���ִ���ڼ�premain��postmain�Ķ�̬���䣬�Ӷ�ʹ������׹���͸����ڴ�ʹ�������
		static constexpr auto sm_MaxElements = 256;

		static int sm_NumInitializers;
		static Initializer sm_Initializers[sm_MaxElements];

		static int sm_NumTerminators;
		static Terminator sm_Terminators[sm_MaxElements];
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_INIT_TERM_H
