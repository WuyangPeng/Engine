/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 21:38)

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
