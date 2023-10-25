///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:31)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CopyFileToolsImpl
    {
    public:
        using ClassType = CopyFileToolsImpl;

        using String = System::String;
        using FactoryType = CopyFileToolsFactory;

    public:
        CopyFileToolsImpl() noexcept = default;
        virtual ~CopyFileToolsImpl() noexcept = default;

        CopyFileToolsImpl(const CopyFileToolsImpl& rhs) = delete;
        CopyFileToolsImpl& operator=(const CopyFileToolsImpl& rhs) = delete;
        CopyFileToolsImpl(CopyFileToolsImpl&& rhs) noexcept = delete;
        CopyFileToolsImpl& operator=(CopyFileToolsImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H
