// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_FWD_H
#define SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_FWD_H  

namespace System
{
	bool GetEnvironment(const String& variableName, TChar*& environmentVariable) noexcept;
	void FreeEnvironment(TChar*& environmentVariable) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_ENVIRONMENT_VARIABLE_FWD_H