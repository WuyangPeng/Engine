//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:24)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CReadFileManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CReadFileManager final : private boost::noncopyable
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

        [[nodiscard]] int GetFileByteSize() const;

        // ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

        [[nodiscard]] int GetCharacter();
        [[nodiscard]] bool UnGetCharacter(int character);
        [[nodiscard]] std::string GetString(int count);
        [[nodiscard]] bool IsEOF() noexcept;
        [[nodiscard]] bool Flush() noexcept;
        [[nodiscard]] bool Seek(long offset, FileSeek whence) noexcept;
        [[nodiscard]] PosType GetPosition();
        [[nodiscard]] bool SetPosition(PosType position) noexcept;
        [[nodiscard]] long Tell() noexcept;
        void Rewind() noexcept;
        [[nodiscard]] bool Setvbuf(FileSetvBuf type, size_t size) noexcept;

    private:
        IMPL_TYPE_DECLARE(CReadFileManager);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_H
