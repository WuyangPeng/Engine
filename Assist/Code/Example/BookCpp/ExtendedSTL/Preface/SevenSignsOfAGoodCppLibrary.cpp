///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/01 22:40)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "SevenSignsOfAGoodCppLibrary.h"
#include "SevenSignsOfAGoodCppLibraryDeclaration.h"
#include "Example/BookCpp/ExtendedSTL/Helper/ExtendedSTLClassInvariantMacro.h"

#ifdef SYSTEM_PLATFORM_LINUX

    #include <unixstl/filesystem/readdir_sequence.hpp>

#endif  // SYSTEM_PLATFORM_LINUX

BookStandardLibrary::ExtendedSTL::SevenSignsOfAGoodCppLibrary::SevenSignsOfAGoodCppLibrary() noexcept
{
    EXTENDED_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookStandardLibrary::ExtendedSTL, SevenSignsOfAGoodCppLibrary)

void BookStandardLibrary::ExtendedSTL::SevenSignsOfAGoodCppLibrary::Main() const  
{
    EXTENDED_STL_CLASS_IS_VALID_CONST_9;

#if 0
     int i1 = 1;
    long l1 = 11;
    Max(i1, l1);
#endif

    const char* pathName1 = "";
    const DynamicLibrary dl1(pathName1);

    const std::string pathName2 = "";
    const DynamicLibrary dl2(pathName2);
}

void BookStandardLibrary::ExtendedSTL::SevenSignsOfAGoodCppLibrary::CRemoveFile() const
{
    EXTENDED_STL_CLASS_IS_VALID_CONST_9;

    DIR* dir = opendir(".");
    if (dir != nullptr)
    {
        struct dirent* de;
        for (; (de = readdir(dir)) != nullptr;)
        {
            struct stat st;
            if (stat(de->d_name, &st) == 0 &&
                (st.st_mode & S_IFMT) == S_IFREG)
            {
                remove(de->d_name);
            }
        }

        closedir(dir);
    }
}

void BookStandardLibrary::ExtendedSTL::SevenSignsOfAGoodCppLibrary::STLSoftFile() const noexcept
{
    EXTENDED_STL_CLASS_IS_VALID_CONST_9;

#ifdef SYSTEM_PLATFORM_LINUX

    using namespace unixstl;

    readdir_sequence entries(".", readdir_sequence::files);
    std::for_each(entries.begin(), entries.end(), ::remove);

#endif  // SYSTEM_PLATFORM_LINUX
}
