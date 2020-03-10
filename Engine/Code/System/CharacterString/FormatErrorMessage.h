// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:22)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"

namespace System
{
	// ��ʽ��������Ϣ��

	WindowDWord	SYSTEM_DEFAULT_DECLARE FormatErrorMessage(FormatMessageOption flag, FormatMessageWidth widthFlag, WindowConstVoidPtr source, WindowError messageID,
														  const LanguageIDData& languageID, TChar* buffer, WindowDWord size, va_list* arguments) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowHLocal& errorMessage, WindowError lastError) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowError lastError, TChar* buffer, WindowDWord size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowDWord size) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, WindowPtrDWord* arguments) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, va_list* arguments) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, WindowPtrDWord* arguments) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, va_list* arguments) noexcept;

	constexpr WindowDWord MakeSoftwareException(Severity severity, Facility facility, WindowDWord exception) noexcept
	{
		// �쳣��
		constexpr WindowDWord exceptionShift{ 0 };

		// �豸��
		constexpr WindowDWord facilityShift{ 16 };

		// ������(0)    
		constexpr WindowDWord reservedShift{ 28 };

		// MS(0) �� �Զ���(1)
		constexpr WindowDWord customerShift{ 29 };

		// ������
		constexpr WindowDWord severityShift{ 30 };

		return (EnumCastUnderlying(severity) << severityShift) | (1 << customerShift) | (0 << reservedShift) |
			   (EnumCastUnderlying(facility) << facilityShift) | (exception << exceptionShift);
	}
}

#endif // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
