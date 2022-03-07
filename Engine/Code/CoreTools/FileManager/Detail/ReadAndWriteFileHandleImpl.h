///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:31)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadAndWriteFileHandleImpl final : public FileHandleImpl
    {
    public:
        using ClassType = ReadAndWriteFileHandleImpl;
        using ParentType = FileHandleImpl;

    public:
        explicit ReadAndWriteFileHandleImpl(const String& fileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_IMPL_H