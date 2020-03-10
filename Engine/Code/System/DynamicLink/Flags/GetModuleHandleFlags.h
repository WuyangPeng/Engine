// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:43)

#ifndef SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H
#define SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32  

	enum class GetModuleHandle
	{
		Default = 0, // �򵱵��øú���ʱ��ģ������ü����Զ�����
		Pin = GET_MODULE_HANDLE_EX_FLAG_PIN, // ģ��һֱӳ���ڵ��øú����Ľ����У�ֱ���ý��̽���
		UnchangedRefcount = GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, // ͬGetModuleHandle��ͬ�����������ü���
		FromAddress = GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, // moduleName��ģ���е�һ����ַ
	};

#else // !SYSTEM_PLATFORM_WIN32  

	enum class GetModuleHandle
	{
		Default = 0,
		Pin = 0x00000001,
		UnchangedRefcount = 0x00000002,
		FromAddress = 0x00000004,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_DYNAMIC_LINK_GET_MODULE_HANDLE_FLAGS_H
