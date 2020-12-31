//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 17:13)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CopyFileToolsImpl
    {
    public:
        using ClassType = CopyFileToolsImpl;
        using String = System::String;

    public:
        CopyFileToolsImpl() noexcept = default;
        virtual ~CopyFileToolsImpl() noexcept = default;

        CopyFileToolsImpl(const CopyFileToolsImpl&) = delete;
        CopyFileToolsImpl& operator=(const CopyFileToolsImpl&) = delete;
        CopyFileToolsImpl(CopyFileToolsImpl&&) noexcept = delete;
        CopyFileToolsImpl& operator=(CopyFileToolsImpl&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H
