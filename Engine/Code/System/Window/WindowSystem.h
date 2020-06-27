// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:38)

#ifndef SYSTEM_WINDOW_WINDOW_SYSTEM_H
#define SYSTEM_WINDOW_WINDOW_SYSTEM_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "Fwd/WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h" 

#include <iostream>

namespace System
{
	// ϵͳ��غ�����

	void SYSTEM_DEFAULT_DECLARE GetWindowSystemInfo(WindowSystemInfo& systemInfo) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetNumaProcessorNodeNumber(WindowUChar processor, WindowUCharPtr nodeNumber) noexcept;

	void SYSTEM_DEFAULT_DECLARE DebugBreak() noexcept;
	void SYSTEM_DEFAULT_DECLARE Exit() noexcept;
	int SYSTEM_DEFAULT_DECLARE SystemCommand(const char* command) noexcept;

	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemCurrentDirectory(WindowDWord bufferLength, TChar* buffer) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	SetSystemCurrentDirectory(const TChar* pathName) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	GetSystemUserName(TChar* buffer, WindowDWord* bufferCount) noexcept;

	WindowBool SYSTEM_DEFAULT_DECLARE BoolConversion(bool value) noexcept;
	void SYSTEM_DEFAULT_DECLARE BoolConversion(WindowBool value, bool* result) noexcept;

	template<typename T>
	T GetSystemInput()
	{
		T value{ };
		std::cin >> value;
		return value;
	}
}

#endif // SYSTEM_WINDOW_WINDOW_SYSTEM_H
