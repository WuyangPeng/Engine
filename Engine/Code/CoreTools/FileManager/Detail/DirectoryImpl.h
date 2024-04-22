/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:31)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <array>

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
        using DirectoryType = std::array<System::TChar, System::gMaxPath>;

    private:
        NODISCARD static String GetDirectoryName(const String& directoryName);

    private:
        String directoryName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
