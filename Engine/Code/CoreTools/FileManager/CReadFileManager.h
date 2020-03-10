// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 14:19)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CReadFileManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CReadFileManager : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(CReadFileManager);
		using String = System::String;
		using PosType = System::PosType;
		using FileSeek = System::FileSeek;
		using FileSetvBuf = System::FileSetvBuf;

	public:
		explicit CReadFileManager(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		int GetFileByteSize() const;

		// 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
		void Read(size_t itemSize, void* data);
		void Read(size_t itemSize, size_t itemsNumber, void* data);

		int GetCharacter() noexcept;
		bool UnGetCharacter(int character) noexcept;
		std::string GetString(int count);
		bool IsEOF() noexcept;
		bool Flush() noexcept;
		bool Seek(long offset, FileSeek whence) noexcept;
		PosType GetPosition();
		bool SetPosition(PosType position) noexcept;
		long Tell() noexcept;
		void Rewind() noexcept;
		bool Setvbuf(FileSetvBuf type, size_t size) noexcept;

	private:
		IMPL_TYPE_DECLARE(CReadFileManager);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
