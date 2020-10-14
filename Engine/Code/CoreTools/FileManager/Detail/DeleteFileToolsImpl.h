//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 17:27)

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

        DeleteFileToolsImpl(const DeleteFileToolsImpl&) = delete;
        DeleteFileToolsImpl& operator=(const DeleteFileToolsImpl&) = delete;
        DeleteFileToolsImpl(DeleteFileToolsImpl&&) noexcept = delete;
        DeleteFileToolsImpl& operator=(DeleteFileToolsImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        CFileString m_FileName;
        bool m_Deleted;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H
