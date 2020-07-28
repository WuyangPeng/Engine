// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:38)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"

#include <boost/noncopyable.hpp>
#include <string>

// ֧�ֶ�ȡ��д��������ļ���
// �����û�д��ļ�д�룬�����ӳ���WriteToFile����������
// �����û�д��ļ���ȡ�������ӳ���ReadFromFile����������
// ������װ��_tfopen_s���ļ�������fclose��fread��fwrite�ȡ�

// ���е������ļ����洢Ϊlittle endian��ʽ����Ϊ�����ƽ̨����little endian��
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
		virtual ~CFileManagerImpl() noexcept;

		CFileManagerImpl(const CFileManagerImpl&) = delete;
		CFileManagerImpl& operator=(const CFileManagerImpl&) = delete;
		CFileManagerImpl(CFileManagerImpl&&) noexcept = delete;
		CFileManagerImpl& operator=(CFileManagerImpl&&) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		OffType GetFileLength() const;

		// ����
		virtual size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) ;
		// ��� 
		virtual size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);
		// ����
		virtual int GetCharacter() ;
		// ����
		virtual bool UnGetCharacter(int character) ;
		// ��� 
		virtual bool PutCharacter(int character);
		// ��� 
		virtual bool PutString(const std::string& str);
		// ����
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
