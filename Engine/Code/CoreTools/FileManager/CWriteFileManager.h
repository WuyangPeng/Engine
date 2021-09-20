//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:25)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(CWriteFileManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CWriteFileManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(CWriteFileManager);
        using String = System::String;
        using PosType = System::PosType;
        using FileSeek = System::FileSeek;
        using FileSetvBuf = System::FileSetvBuf;

    public:
        explicit CWriteFileManager(const String& fileName);
        ~CWriteFileManager() noexcept = default;
        CWriteFileManager(const CWriteFileManager& rhs) noexcept = delete;
        CWriteFileManager& operator=(const CWriteFileManager& rhs) noexcept = delete;
        CWriteFileManager(CWriteFileManager&& rhs) noexcept = delete;
        CWriteFileManager& operator=(CWriteFileManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint32_t GetFileByteSize() const;

        // 当且仅当写入的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

        [[nodiscard]] bool PutCharacter(int character);
        [[nodiscard]] bool PutString(const std::string& str);
        [[nodiscard]] bool IsEOF() noexcept;
        [[nodiscard]] bool Flush() noexcept;
        [[nodiscard]] bool Seek(long offset, FileSeek whence) noexcept;
        [[nodiscard]] PosType GetPosition();
        [[nodiscard]] bool SetPosition(PosType position) noexcept;
        [[nodiscard]] long Tell() noexcept;
        void Rewind() noexcept;
        [[nodiscard]] bool Setvbuf(FileSetvBuf type, size_t size) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_H
