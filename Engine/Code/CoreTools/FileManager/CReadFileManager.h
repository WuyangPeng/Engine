///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:25)

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

        // ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
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
        void Rewind() noexcept;
        NODISCARD bool SetVBuffer(FileSetVBuffer type, size_t size) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
