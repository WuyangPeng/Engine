// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:56)

#include "System/SystemExport.h"

#include "File.h"
#include "Flags/FileFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowSystem.h"
#include "System/Window/LastPlatformError.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/Helper/EnumCast.h"

bool System
	::RemoveSystemFile(const CFileString& fileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::DeleteFile(fileName.c_str()) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	if (::remove(fileName.c_str()) == 0)
		return true;
	else
		return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, WindowSecurityAttributesPtr securityAttributes, FileHandleCreationDisposition creation,
					    FileHandleAttributes attributes, FileHandleOther other, FileHandleSecurity security, WindowHandle templateFile) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::CreateFile(fileName.c_str(), EnumCastUnderlying(access), EnumCastUnderlying(shareMode), securityAttributes,
						EnumCastUnderlying(creation), EnumCastUnderlying(attributes) | EnumCastUnderlying(other) | EnumCastUnderlying(security), templateFile);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(access);
	SYSTEM_UNUSED_ARG(shareMode);
	SYSTEM_UNUSED_ARG(securityAttributes);
	SYSTEM_UNUSED_ARG(creation);
	SYSTEM_UNUSED_ARG(attributes);
	SYSTEM_UNUSED_ARG(other);
	SYSTEM_UNUSED_ARG(security);
	SYSTEM_UNUSED_ARG(templateFile);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation) noexcept
{
	return CreateSystemFile(fileName, access, shareMode, nullptr, creation, FileHandleAttributes::Normal, FileHandleOther::SequentialScan, FileHandleSecurity::Default, nullptr);
}

System::WindowHandle System
	::CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation,
					   FileHandleAttributes attributes, FileHandleOther other, FileHandleSecurity security) noexcept
{
	return CreateSystemFile(fileName, access, shareMode, nullptr, creation, attributes, other, security, nullptr);
}

bool System
	::CloseSystemFile(WindowHandle file) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::CloseHandle(file) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool  System
	::IsFileHandleValid(WindowHandle file) noexcept
{
	if (file != nullptr && file != g_InvalidHandleValue)
		return true;
	else
		return false;
}

bool System
	::GetFileLength(WindowHandle file, uint64_t& fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	WindowDWord fileSizeHigh{ 0 };
	auto fileSizeLow = ::GetFileSize(file, &fileSizeHigh);
	const auto lastError = GetPlatformLastError();

	if (lastError == WindowError::Success || fileSizeLow != g_InvalidFileSize)
	{
		fileSize = (static_cast<uint64_t>(fileSizeHigh) << 32) + fileSizeLow;
		return true;
	}
	else
	{
		SetPlatformLastError(lastError);
		fileSize = 0;

		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetFileLength(WindowHandle file, WindowLargeIntegerPtr fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	#if defined(TCRE_USE_GCC)

		uint64_t size{ 0 };
		auto result = GetFileLength(file, size);

		if (result)
		{
			fileSize->QuadPart = size;
		}

		return result;

	#else // !TCRE_USE_GCC 

		if (::GetFileSizeEx(file, fileSize) != g_False)
			return true;
		else
			return false;

	#endif // TCRE_USE_GCC
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::ReadFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfBytesToRead);
	SYSTEM_UNUSED_ARG(numberOfBytesRead);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead) noexcept
{
	return ReadSystemFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, nullptr);
}

bool System
	::ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::ReadFileEx(file, buffer, numberOfBytesToRead, overlapped, completionRoutine) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfBytesToRead);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::WriteFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfBytesToWrite);
	SYSTEM_UNUSED_ARG(numberOfBytesWritten);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept
{
	return WriteSystemFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, nullptr);
}

bool System
	::WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::WriteFileEx(file, buffer, numberOfBytesToWrite, overlapped, completionRoutine) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfBytesToWrite);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AppendSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	

	WindowOverlapped overlapped{};

	overlapped.Offset = 0xFFFFFFFF;
	overlapped.OffsetHigh = 0xFFFFFFFF;

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26486)
	return WriteSystemFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, &overlapped);
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32

	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfBytesToWrite);
	SYSTEM_UNUSED_ARG(numberOfBytesWritten);

	return false;

#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CopySystemFile(const String& existingFileName, const String& newFileName) noexcept
{
	return CopySystemFile(existingFileName, newFileName, false);
}

bool System
	::CopySystemFile(const String& existingFileName, const String& newFileName, bool failIfExists) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
	if (::CopyFile(existingFileName.c_str(), newFileName.c_str(), BoolConversion(failIfExists)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(existingFileName);
	SYSTEM_UNUSED_ARG(newFileName);
	SYSTEM_UNUSED_ARG(failIfExists);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemFilePointer(WindowHandle file, WindowLong distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	newFilePointer->QuadPart = distanceToMove;

	newFilePointer->LowPart = ::SetFilePointer(file, newFilePointer->LowPart, &newFilePointer->HighPart, EnumCastUnderlying(moveMethod));

	const auto lastError = GetPlatformLastError();

	if (lastError != WindowError::Success && newFilePointer->LowPart == g_InvalidSetFilePointer)
	{
		SetPlatformLastError(lastError);
		newFilePointer->QuadPart = -1;
		return false;
	}

	return true;

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(distanceToMove);
	SYSTEM_UNUSED_ARG(newFilePointer);
	SYSTEM_UNUSED_ARG(moveMethod);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemFilePointer(WindowHandle file, WindowLargeInteger distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetFilePointerEx(file, distanceToMove, newFilePointer, EnumCastUnderlying(moveMethod)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(distanceToMove);
	SYSTEM_UNUSED_ARG(newFilePointer);
	SYSTEM_UNUSED_ARG(moveMethod);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetEndOfSystemFile(WindowHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::SetEndOfFile(file)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FlushSystemFileBuffers(WindowHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::FlushFileBuffers(file)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::MoveSystemFile(const String& oldFileName, const String& newFileName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::MoveFile(oldFileName.c_str(), newFileName.c_str())) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(oldFileName);
	SYSTEM_UNUSED_ARG(newFileName);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
