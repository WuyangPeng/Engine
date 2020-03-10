// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:48)

#include "System/SystemExport.h"

#include "LoadResourceTools.h"
#include "System/Window/WindowSystem.h"
#include "System/SystemOutput/Data/LanguageIDData.h"

System::DynamicLinkResource System
	::FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FindResource(module, name, type);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkResource System
	::FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32		
	return ::FindResourceEx(module, type, name, language.GetLanguageID());
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System
	::LoadResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LoadResource(module, resourceInfo);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LockResource(resourceData);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::SizeofResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept
{
#ifdef WIN32
	return ::SizeofResource(module, resourceInfo);
#else // !WIN32
	return false;
#endif // WIN32
}

bool System
	::UpdateResourceInLibrary(WindowHandle update, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
							  const LanguageIDData& language, WindowVoidPtr resourceLock, WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::UpdateResource(update, type, name, language.GetLanguageID(), resourceLock, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::BeginUpdateResourceInLibrary(const DynamicLinkCharType* fileName, bool deleteExistingResources) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::BeginUpdateResource(fileName, BoolConversion(deleteExistingResources));
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EndUpdateResourceInLibrary(WindowHandle update, bool discard) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EndUpdateResource(update, BoolConversion(discard)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::LoadStringInLibrary(WindowHInstance instance, WindowUInt id, DynamicLinkCharType* buffer, int size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LoadString(instance, id, buffer, size);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
