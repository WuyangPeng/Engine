///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:21)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

/// ֧�ֶ�ȡ��д��������ļ���
/// �����û�д��ļ�д�룬�����ӳ���WriteToFile����������
/// �����û�д��ļ���ȡ�������ӳ���ReadFromFile����������
/// ������װ��_tfopen_s���ļ�������fclose��fread��fwrite�ȡ�

/// ���е������ļ����洢Ϊlittle endian��ʽ����Ϊ�����ƽ̨����little endian��
///
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CFileManagerImpl
    {
    public:
        using ClassType = CFileManagerImpl;
        using String = System::String;
        using OffType = System::OffType;
        using PosType = System::PosType;
        using FileSeek = System::FileSeek;
        using FileSetVBuf = System::FileSetVBuffer;

    public:
        CFileManagerImpl(const String& fileName, const String& mode);
        virtual ~CFileManagerImpl() noexcept;

        CFileManagerImpl(const CFileManagerImpl& rhs) = delete;
        CFileManagerImpl& operator=(const CFileManagerImpl& rhs) = delete;
        CFileManagerImpl(CFileManagerImpl&& rhs) noexcept = delete;
        CFileManagerImpl& operator=(CFileManagerImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD OffType GetFileLength() const;

        // ����
        NODISCARD virtual size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data);
        // ���
        NODISCARD virtual size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);
        // ����
        NODISCARD virtual int GetCharacter();
        // ����
        NODISCARD virtual bool UnGetCharacter(int character);
        // ���
        NODISCARD virtual bool PutCharacter(int character);
        // ���
        NODISCARD virtual bool PutString(const std::string& str);
        // ����
        NODISCARD virtual std::string GetString(int count);

        NODISCARD bool IsEof() noexcept;
        NODISCARD bool Flush() noexcept;
        NODISCARD bool Seek(long offset, FileSeek whence) noexcept;
        NODISCARD PosType GetPosition();
        NODISCARD bool SetPosition(PosType position) noexcept;
        NODISCARD long Tell() noexcept;
        void Rewind() noexcept;
        NODISCARD bool SetVBuffer(FileSetVBuf type, size_t size) noexcept;

    private:
        void Open();
        void Close() const noexcept;

    private:
        FILE* file;
        String fileName;
        String mode;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
