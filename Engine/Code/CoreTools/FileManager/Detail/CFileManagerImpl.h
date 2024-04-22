/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:28)

#ifndef CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#include <string>

/// 支持读取或写入二进制文件。
/// 如果你没有打开文件写入，调用子程序WriteToFile将产生错误。
/// 如果你没有打开文件读取，调用子程序ReadFromFile将产生错误。
/// 这个类封装了_tfopen_s的文件操作：fclose、fread和fwrite等。
///
/// 所有的数据文件都存储为little endian格式，因为大多数平台都是little endian。
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
        using FileSetVBuffer = System::FileSetVBuffer;

    public:
        CFileManagerImpl(const String& fileName, const String& mode);
        virtual ~CFileManagerImpl() noexcept;

        CFileManagerImpl(const CFileManagerImpl& rhs) = delete;
        CFileManagerImpl& operator=(const CFileManagerImpl& rhs) = delete;
        CFileManagerImpl(CFileManagerImpl&& rhs) noexcept = delete;
        CFileManagerImpl& operator=(CFileManagerImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD OffType GetFileLength() const;

        /// @param data 必须至少有itemSize * itemsNumber大小。
        /// @param itemSize 每个数据项的大小（以字节为单位），有效值为1、2、4、8。
        /// @param itemsNumber 要读取的数据项的数量。

        /// 输入
        NODISCARD virtual size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data);
        /// 输出
        NODISCARD virtual size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);

        /// 输入
        NODISCARD virtual int GetCharacter();
        /// 输入
        NODISCARD virtual bool UnGetCharacter(int character);
        /// 输出
        NODISCARD virtual bool PutCharacter(int character);
        /// 输出
        NODISCARD virtual bool PutString(const std::string& str);
        /// 输入
        NODISCARD virtual std::string GetString(int count);

        /// 辅助函数
        NODISCARD bool IsEof() const noexcept;
        NODISCARD bool Flush() const noexcept;
        NODISCARD bool Seek(long offset, FileSeek whence) const noexcept;
        NODISCARD PosType GetPosition() const;
        NODISCARD bool SetPosition(PosType position) const noexcept;
        NODISCARD long Tell() const noexcept;
        NODISCARD bool SetVBuffer(FileSetVBuffer type, size_t size) const noexcept;

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
