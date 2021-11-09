///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:02)

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

        DirectoryImpl(const DirectoryImpl& rhs) = delete;
        DirectoryImpl& operator=(const DirectoryImpl& rhs) = delete;
        DirectoryImpl(DirectoryImpl&& rhs) noexcept = delete;
        DirectoryImpl& operator=(DirectoryImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        String m_DirectoryName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
