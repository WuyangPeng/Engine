/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:33)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileHandleImpl
    {
    public:
        using ClassType = FileHandleImpl;

        using String = System::String;
        using FileHandle = System::WindowsHandle;
        using FileHandleShareMode = System::FileHandleShareMode;
        using FileHandleDesiredAccess = System::FileHandleDesiredAccess;
        using FileHandleCreationDisposition = System::FileHandleCreationDisposition;

    public:
        FileHandleImpl(const System::String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation);
        virtual ~FileHandleImpl() noexcept;

        FileHandleImpl(const FileHandleImpl& rhs) = delete;
        FileHandleImpl operator=(const FileHandleImpl& rhs) = delete;
        FileHandleImpl(FileHandleImpl&& rhs) noexcept = delete;
        FileHandleImpl operator=(FileHandleImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD uint64_t GetFileLength() const;

        /// @param data ����������itemSize * itemsNumber��С��
        /// @param itemSize ÿ��������Ĵ�С�����ֽ�Ϊ��λ������ЧֵΪ1��2��4��8��
        /// @param itemsNumber Ҫ��ȡ���������������
        virtual void ReadFromFile(size_t itemSize, size_t itemsNumber, void* data);
        virtual void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);
        virtual void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        String fileName;
        FileHandle file;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H