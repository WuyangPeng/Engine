// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 0:12)	

#include "System/SystemExport.h"

#include "ViewOfFile.h" 
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/Window/LastPlatformError.h"
#include "System/Window/Flags/PlatformErrorFlags.h"

System::WindowHandle System
	::CreateSystemFileMapping(WindowHandle file, MemoryProtect protect, FileMapProtection otherProtect, WindowDWord maximumSizeHigh,
							  WindowDWord maximumSizeLow, const wchar_t* name, bool* isExists) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	auto handle = ::CreateFileMapping(file, nullptr, EnumCastUnderlying(protect) | EnumCastUnderlying(otherProtect), maximumSizeHigh, maximumSizeLow, name);
	if (isExists != nullptr)
	{
		const auto errorFlag = GetPlatformLastError();
		if (errorFlag == WindowError::AlreadyExists)
			*isExists = true;
		else
			*isExists = false;

		SetPlatformLastError(errorFlag);
	}

	return handle;

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(protect);
	SYSTEM_UNUSED_ARG(otherProtect);
	SYSTEM_UNUSED_ARG(maximumSizeHigh);
	SYSTEM_UNUSED_ARG(maximumSizeLow);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(isExists);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::OpenSystemFileMapping(FileMapDesiredAccess desiredAccess, bool inheritHandle, const wchar_t* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::OpenFileMapping(EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemFileMappingNuma(WindowHandle file, WindowSecurityAttributesPtr fileMappingAttributes, MemoryProtect protect,
								  FileMapProtection otherProtect, WindowDWord maximumSizeHigh, WindowDWord maximumSizeLow,
								  const wchar_t* name, WindowDWord preferred) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::CreateFileMappingNuma(file, fileMappingAttributes, EnumCastUnderlying(protect) | EnumCastUnderlying(otherProtect), maximumSizeHigh, maximumSizeLow, name, preferred);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileMappingAttributes);
	SYSTEM_UNUSED_ARG(protect);
	SYSTEM_UNUSED_ARG(otherProtect);
	SYSTEM_UNUSED_ARG(maximumSizeHigh);
	SYSTEM_UNUSED_ARG(maximumSizeLow);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(preferred);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::MapSystemViewOfFile(WindowHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowDWord maximumSizeHigh, WindowDWord maximumSizeLow, WindowSize numberOfBytesToMap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::MapViewOfFile(fileMappingObject, EnumCastUnderlying(desiredAccess), maximumSizeHigh, maximumSizeLow, numberOfBytesToMap);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileMappingObject);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(maximumSizeHigh);
	SYSTEM_UNUSED_ARG(maximumSizeLow);
	SYSTEM_UNUSED_ARG(numberOfBytesToMap);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::MapSystemViewOfFile(WindowHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowDWord maximumSizeHigh,
						  WindowDWord maximumSizeLow, WindowSize numberOfBytesToMap, WindowVoidPtr baseAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::MapViewOfFileEx(fileMappingObject, EnumCastUnderlying(desiredAccess), maximumSizeHigh, maximumSizeLow, numberOfBytesToMap, baseAddress);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileMappingObject);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(maximumSizeHigh);
	SYSTEM_UNUSED_ARG(maximumSizeLow);
	SYSTEM_UNUSED_ARG(numberOfBytesToMap);
	SYSTEM_UNUSED_ARG(baseAddress);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FlushSystemViewOfFile(WindowVoidPtr baseAddress, WindowSize numberOfBytesToFlush) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::FlushViewOfFile(baseAddress, numberOfBytesToFlush) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(baseAddress);
	SYSTEM_UNUSED_ARG(numberOfBytesToFlush);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UnmapSystemViewOfFile(WindowVoidPtr baseAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::UnmapViewOfFile(baseAddress) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(baseAddress);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseFileMapping(WindowHandle fileMappingHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::CloseHandle(fileMappingHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileMappingHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

