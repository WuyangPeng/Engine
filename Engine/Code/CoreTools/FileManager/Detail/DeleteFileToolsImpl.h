/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:39)

#ifndef CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DeleteFileToolsImpl final
    {
    public:
        using ClassType = DeleteFileToolsImpl;

        using String = System::String;
        using CFileString = System::CFileString;

    public:
        explicit DeleteFileToolsImpl(const String& fileName);
        ~DeleteFileToolsImpl() noexcept;

        DeleteFileToolsImpl(const DeleteFileToolsImpl& rhs) = delete;
        DeleteFileToolsImpl& operator=(const DeleteFileToolsImpl& rhs) = delete;
        DeleteFileToolsImpl(DeleteFileToolsImpl&& rhs) noexcept = delete;
        DeleteFileToolsImpl& operator=(DeleteFileToolsImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        CFileString fileName;
        bool deleted;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H
