//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 17:28)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DirectoryImpl final
    {
    public:
        using ClassType = DirectoryImpl;
        using String = System::String;

    public:
        explicit DirectoryImpl(const String& directoryName);
        ~DirectoryImpl() noexcept;

        DirectoryImpl(const DirectoryImpl&) = delete;
        DirectoryImpl& operator=(const DirectoryImpl&) = delete;
        DirectoryImpl(DirectoryImpl&&) noexcept = delete;
        DirectoryImpl& operator=(DirectoryImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        String m_DirectoryName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
