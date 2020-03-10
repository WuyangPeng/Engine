// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.1 (2019/12/02 18:34)
// ≥ı º∞Ê±æ£∫0.0.1.1

#include "System/SystemExport.h"

#include "FormatErrorMessage.h"
#include "Flags/FormatMessageFlags.h"
#include "System/Helper/PragmaWarning.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/SystemOutput/Data/LanguageIDData.h"

System::WindowDWord	System
	::FormatErrorMessage(FormatMessageOption flag, FormatMessageWidth widthFlag, WindowConstVoidPtr source, WindowError messageID,
						 const LanguageIDData& languageID, TChar* buffer, WindowDWord size, va_list* arguments) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	 
	return ::FormatMessage(EnumCastUnderlying(flag) | EnumCastUnderlying(widthFlag), source, EnumCastUnderlying(messageID), languageID.GetLanguageID(), buffer, size, arguments);
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FormatErrorMessage(WindowHLocal& errorMessage, WindowError lastError) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	const auto size = FormatErrorMessage(messageOption, messageWidth, nullptr, lastError, languageID, reinterpret_cast<TChar*>(&errorMessage), 0, nullptr);
#include STSTEM_WARNING_POP

	return size != 0;
}

System::WindowDWord System
	::FormatErrorMessage(WindowError lastError, TChar* buffer, WindowDWord size) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

	return FormatErrorMessage(messageOption, messageWidth, nullptr, lastError, languageID, buffer, size, nullptr);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
bool System
	::FormatErrorMessage(WindowHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	const auto size = FormatErrorMessage(messageOption, messageWidth, module, lastError, languageID, reinterpret_cast<TChar*>(&errorMessage), 0, nullptr);
#include STSTEM_WARNING_POP

	return size != 0;
}

System::WindowDWord System
	::FormatErrorMessage(DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowDWord size) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

	return FormatErrorMessage(messageOption, messageWidth, module, lastError, languageID, buffer, size, nullptr);
}
#include STSTEM_WARNING_POP

System::WindowDWord System
	::FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, WindowPtrDWord* arguments) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::ArgumentArray;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
	constexpr auto windowError = WindowError::Success;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, buffer, size, reinterpret_cast<va_list*>(arguments));
#include STSTEM_WARNING_POP 
}

System::WindowDWord System
	::FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, va_list* arguments) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromString;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
	constexpr auto windowError = WindowError::Success;

	return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, buffer, size, arguments);
}

System::WindowDWord System
	::FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, WindowPtrDWord* arguments) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::ArgumentArray | FormatMessageOption::AllocateBuffer;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
	constexpr auto windowError = WindowError::Success;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, reinterpret_cast<TChar*>(&resultMessage), 0, reinterpret_cast<va_list*>(arguments));
#include STSTEM_WARNING_POP 
}

System::WindowDWord System
	::FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, va_list* arguments) noexcept
{
	const LanguageIDData languageID{};
	constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::AllocateBuffer;
	constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
	constexpr auto windowError = WindowError::Success;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, reinterpret_cast<TChar*>(&resultMessage), 0, arguments);
#include STSTEM_WARNING_POP 
}
