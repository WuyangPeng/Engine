// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:54)

#ifndef SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_H
#define SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
	// ���������Ļ�ȡ��

	bool SYSTEM_DEFAULT_DECLARE GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept;
	void SYSTEM_DEFAULT_DECLARE FreeEnvironment(TChar*& environmentVariable) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_H