//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:29)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ReadAndWriteFileHandleImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadAndWriteFileHandle final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ReadAndWriteFileHandle);
        using String = System::String;

    public:
        explicit ReadAndWriteFileHandle(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t GetFileLength() const;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        IMPL_TYPE_DECLARE(ReadAndWriteFileHandle);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H