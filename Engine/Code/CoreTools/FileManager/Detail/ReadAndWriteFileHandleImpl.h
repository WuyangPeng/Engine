///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:37)

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