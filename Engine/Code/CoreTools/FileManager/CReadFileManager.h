/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:53)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(CReadFileManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CReadFileManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(CReadFileManager);

        using String = System::String;
        using PosType = System::PosType;
        using FileSeek = System::FileSeek;
        using FileSetVBuffer = System::FileSetVBuffer;

    public:
        explicit CReadFileManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFileByteSize() const;

        /// 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

        NODISCARD int GetCharacter();
        NODISCARD bool UnGetCharacter(int character);
        NODISCARD std::string GetString(int count);
        NODISCARD bool IsEof() noexcept;
        NODISCARD bool Flush() noexcept;
        NODISCARD bool Seek(long offset, FileSeek whence) noexcept;
        NODISCARD PosType GetPosition();
        NODISCARD bool SetPosition(PosType position) noexcept;
        NODISCARD long Tell() noexcept;
        NODISCARD bool SetVBuffer(FileSetVBuffer type, size_t size) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
