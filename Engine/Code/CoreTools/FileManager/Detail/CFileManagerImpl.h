//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 16:58)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

// 支持读取或写入二进制文件。
// 如果你没有打开文件写入，调用子程序WriteToFile将产生错误。
// 如果你没有打开文件读取，调用子程序ReadFromFile将产生错误。
// 这个类封装了_tfopen_s的文件操作：fclose、fread和fwrite等。

// 所有的数据文件都存储为little endian格式，因为大多数平台都是little endian。
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

        // 输入
        [[nodiscard]] virtual size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data);
        // 输出
        [[nodiscard]] virtual size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);
        // 输入
        [[nodiscard]] virtual int GetCharacter();
        // 输入
        [[nodiscard]] virtual bool UnGetCharacter(int character);
        // 输出
        [[nodiscard]] virtual bool PutCharacter(int character);
        // 输出
        [[nodiscard]] virtual bool PutString(const std::string& str);
        // 输入
        [[nodiscard]] virtual std::string GetString(int count);

        [[nodiscard]] bool IsEOF() noexcept;
        [[nodiscard]] bool Flush() noexcept;
        [[nodiscard]] bool Seek(long offset, FileSeek whence) noexcept;
        [[nodiscard]] PosType GetPosition();
        [[nodiscard]] bool SetPosition(PosType position) noexcept;
        [[nodiscard]] long Tell() noexcept;
        void Rewind() noexcept;
        [[nodiscard]] bool Setvbuf(FileSetvBuf type, size_t size) noexcept;

    private:
        void Open();
        void Close() noexcept;

    private:
        FILE* m_File;
        System::String m_FileName;
        System::String m_Mode;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
