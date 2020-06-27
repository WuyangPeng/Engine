// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/08 23:46)

#ifndef SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H
#define SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace System
{
	// ��Ϣ��������Դ��ڡ�

	void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithChar(const char* outputString) noexcept;
	void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithWChar(const wchar_t* outputString) noexcept;
	void SYSTEM_DEFAULT_DECLARE OutputDebugStringWithTChar(const TChar* outputString) noexcept;
}

#endif // SYSTEM_SYSTEM_OUTPUT_OUTPUT_DEBUG_STRING_H