// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:40)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"

#include <boost/noncopyable.hpp>
#include <string> 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE FileHandleImpl : private boost::noncopyable
	{
	public:
		using ClassType = FileHandleImpl;
		using String = System::String;
		using FileHandle = System::WindowHandle;
		using FileHandleShareMode = System::FileHandleShareMode;
		using FileHandleDesiredAccess = System::FileHandleDesiredAccess;
		using FileHandleCreationDisposition = System::FileHandleCreationDisposition;

	public:
		FileHandleImpl(const System::String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation);
		virtual ~FileHandleImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		uint64_t GetFileLength() const;

		virtual void ReadFromFile(size_t itemSize, size_t itemsNumber, void* data);
		virtual void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);
		virtual void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data);

	private:
		String m_FileName;
		FileHandle m_File;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H