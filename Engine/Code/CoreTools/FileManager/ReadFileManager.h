/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:57)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ReadFileManagerInterface);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadFileManager final
    {
    public:
        using ReadFileManagerImpl = ReadFileManagerInterface;
        NON_COPY_TYPE_DECLARE(ReadFileManager);

        using String = System::String;

    public:
        explicit ReadFileManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFileByteSize() const;

        /// 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

        NODISCARD std::string LoadStdString();

    private:
        using StdStringBufferType = std::vector<char>;

    private:
        NODISCARD std::string LoadStdString(int length);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H
