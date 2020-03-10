// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FWD_H
#define SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FWD_H

#include "MemoryToolsFlagsFwd.h"
#include "System/FileManager/Using/FileUsing.h"

namespace System
{
	WindowHandle CreateSystemFileMapping(WindowHandle file, MemoryProtect protect, FileMapProtection otherProtect, WindowDWord maximumSizeHigh, 
										 WindowDWord maximumSizeLow, const wchar_t* name, bool* isExists) noexcept;
	bool CloseFileMapping(WindowHandle fileMappingHandle) noexcept;
	WindowHandle OpenSystemFileMapping(FileMapDesiredAccess desiredAccess, bool inheritHandle, const wchar_t* name) noexcept;

	WindowHandle CreateSystemFileMappingNuma(WindowHandle file, WindowSecurityAttributesPtr fileMappingAttributes, MemoryProtect protect,
											 FileMapProtection otherProtect, WindowDWord maximumSizeHigh, WindowDWord maximumSizeLow,
											 const wchar_t* name, WindowDWord preferred) noexcept;

	WindowVoidPtr MapSystemViewOfFile(WindowHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowDWord maximumSizeHigh,
									  WindowDWord maximumSizeLow, WindowSize numberOfBytesToMap) noexcept;

	WindowVoidPtr MapSystemViewOfFile(WindowHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowDWord maximumSizeHigh,
									  WindowDWord maximumSizeLow, WindowSize numberOfBytesToMap, WindowVoidPtr baseAddress) noexcept;

	bool FlushSystemViewOfFile(WindowVoidPtr baseAddress, WindowSize numberOfBytesToFlush) noexcept;
	bool UnmapSystemViewOfFile(WindowVoidPtr baseAddress) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FWD_H