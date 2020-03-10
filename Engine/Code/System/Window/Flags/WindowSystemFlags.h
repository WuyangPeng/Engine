// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:35)

#ifndef SYSTEM_WINDOW_WINDOW_SYSTEM_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_SYSTEM_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <TlHelp32.h>
#endif // SYSTEM_PLATFORM_WIN32

namespace SYSTEM_PLATFORM_WIN32
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class Toolhelp32
	{
		SnapHeapList = TH32CS_SNAPHEAPLIST,
		SnapProcess = TH32CS_SNAPPROCESS,
		SnapThread = TH32CS_SNAPTHREAD,
		SnapModule = TH32CS_SNAPMODULE,
		SnapModule32 = TH32CS_SNAPMODULE32,
		SnapAll = TH32CS_SNAPALL,
		Inherit = TH32CS_INHERIT,
	};

	enum class DirectoryEntries
	{
		Export = IMAGE_DIRECTORY_ENTRY_EXPORT,
		Import = IMAGE_DIRECTORY_ENTRY_IMPORT,
		Resource = IMAGE_DIRECTORY_ENTRY_RESOURCE,
		Exception = IMAGE_DIRECTORY_ENTRY_EXCEPTION,
		Security = IMAGE_DIRECTORY_ENTRY_SECURITY,
		Basereloc = IMAGE_DIRECTORY_ENTRY_BASERELOC,
		Debug = IMAGE_DIRECTORY_ENTRY_DEBUG,
		Architecture = IMAGE_DIRECTORY_ENTRY_ARCHITECTURE,
		GlobalPtr = IMAGE_DIRECTORY_ENTRY_GLOBALPTR,
		Tls = IMAGE_DIRECTORY_ENTRY_TLS,
		LoadConfig = IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG,
		BoundImport = IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT,
		Iat = IMAGE_DIRECTORY_ENTRY_IAT,
		DelayImport = IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT,
		ComDescriptor = IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR,
	};

	enum class ComboBoxNotification
	{
		Errspace = CBN_ERRSPACE,
		Selchange = CBN_SELCHANGE,
		Dblclk = CBN_DBLCLK,
		Setfocus = CBN_SETFOCUS,
		Killfocus = CBN_KILLFOCUS,
		Editchange = CBN_EDITCHANGE,
		Editupdate = CBN_EDITUPDATE,
		Dropdown = CBN_DROPDOWN,
		Closeup = CBN_CLOSEUP,
		Selendok = CBN_SELENDOK,
		Selendcancel = CBN_SELENDCANCEL,
	};

#else // !SYSTEM_PLATFORM_WIN32

	enum class Toolhelp32
	{
		SnapHeapList = 0x00000001,
		SnapProcess = 0x00000002,
		SnapThread = 0x00000004,
		SnapModule = 0x00000008,
		SnapModule32 = 0x00000010,
		SnapAll = SnapHeapList | SnapProcess | SnapThread | SnapModule,
		Inherit = 0x80000000,
	};

	enum class DirectoryEntries
	{
		Export = 0,
		Import = 1,
		Resource = 2,
		Exception = 3,
		Security = 4,
		Basereloc = 5,
		Debug = 6,
		Architecture = 7,
		GlobalPtr = 8,
		Tls = 9,
		LoadConfig = 10,
		BoundImport = 11,
		Iat = 12,
		DelayImport = 13,
		ComDescriptor = 14,
	};

	enum class ComboBoxNotification
	{
		Errspace = -1,
		Selchange = 1,
		Dblclk = 2,
		Setfocus = 3,
		Killfocus = 4,
		Editchange = 5,
		Editupdate = 6,
		Dropdown = 7,
		Closeup = 8,
		Selendok = 9,
		Selendcancel = 10,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_WINDOW_WINDOW_SYSTEM_FLAGS_H
