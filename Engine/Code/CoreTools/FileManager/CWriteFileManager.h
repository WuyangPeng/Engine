//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:25)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CWriteFileManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CWriteFileManager final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(CWriteFileManager);
        using String = System::String;
        using PosType = System::PosType;
        using FileSeek = System::FileSeek;
        using FileSetvBuf = System::FileSetvBuf;

    public:
        explicit CWriteFileManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint32_t GetFileByteSize() const;

        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
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
        IMPL_TYPE_DECLARE(CWriteFileManager);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_H
