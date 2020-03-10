// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 13:38)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"

#include <boost/noncopyable.hpp>
#include <string>

// 支持读取或写入二进制文件。
// 如果你没有打开文件写入，调用子程序WriteToFile将产生错误。
// 如果你没有打开文件读取，调用子程序ReadFromFile将产生错误。
// 这个类封装了_tfopen_s的文件操作：fclose、fread和fwrite等。

// 所有的数据文件都存储为little endian格式，因为大多数平台都是little endian。
namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CFileManagerImpl : private boost::noncopyable
	{
	public:
		using ClassType = CFileManagerImpl;
		using String = System::String;
		using OffType = System::OffType;
		using PosType = System::PosType;
		using FileSeek = System::FileSeek;
		using FileSetvBuf = System::FileSetvBuf;

	public:
		CFileManagerImpl(const String& fileName, const String& mode);
		virtual ~CFileManagerImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		OffType GetFileLength() const;

		// 输入
		virtual size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept;
		// 输出 
		virtual size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept;
		// 输入
		virtual int GetCharacter() noexcept;
		// 输入
		virtual bool UnGetCharacter(int character) noexcept;
		// 输出 
		virtual bool PutCharacter(int character) noexcept;
		// 输出 
		virtual bool PutString(const std::string& str) noexcept;
		// 输入
		virtual std::string GetString(int count);

		bool IsEOF() noexcept;
		bool Flush() noexcept;
		bool Seek(long offset, FileSeek whence) noexcept;
		PosType GetPosition();
		bool SetPosition(PosType position) noexcept;
		long Tell() noexcept;
		void Rewind() noexcept;
		bool Setvbuf(FileSetvBuf type, size_t size) noexcept;

	private:
		void Open();
		void Close() noexcept;

	private:
		FILE* m_File;
		System::String m_FileName;
		System::String m_Mode;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
