///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/01 22:41)

#ifndef EXTENDED_STL_PREFACE_SEVEN_SIGNS_OF_A_GOOD_CPP_LIBRARY_DECLARATION_H
#define EXTENDED_STL_PREFACE_SEVEN_SIGNS_OF_A_GOOD_CPP_LIBRARY_DECLARATION_H

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookStandardLibrary
{
    namespace ExtendedSTL
    {
#ifdef SYSTEM_PLATFORM_WIN32

        class DIR
        {
        };

        DIR* opendir(const std::string& dir) noexcept;

        struct dirent
        {
            const char* d_name;
        };

        dirent* readdir(DIR* dir) noexcept;

        void closedir(DIR* dir) noexcept;

        template <typename T>
        T Max(const T& t1, const T& t2)
        {
            return t1 < t2 ? t2 : t1;
        }

        class DynamicLibrary
        {
        public:
            DynamicLibrary(const std::string& pathName) noexcept;
        };

#endif  // SYSTEM_PLATFORM_WIN32
    }
}

#endif  // EXTENDED_STL_PREFACE_SEVEN_SIGNS_OF_A_GOOD_CPP_LIBRARY_DECLARATION_H
