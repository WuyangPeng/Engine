///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/01 23:34)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "SevenSignsOfAGoodCppLibraryDeclaration.h"

#ifdef SYSTEM_PLATFORM_WIN32

using std::string;

BookStandardLibrary::ExtendedSTL::DIR* BookStandardLibrary::ExtendedSTL::opendir([[maybe_unused]] const string& dir) noexcept
{
    return nullptr;
}

BookStandardLibrary::ExtendedSTL::dirent* BookStandardLibrary::ExtendedSTL::readdir([[maybe_unused]] DIR* dir) noexcept
{
    return nullptr;
}

void BookStandardLibrary::ExtendedSTL::closedir([[maybe_unused]] DIR* dir) noexcept
{
}

BookStandardLibrary::ExtendedSTL::DynamicLibrary::DynamicLibrary([[maybe_unused]] const string& pathName) noexcept
{
}

#endif  // SYSTEM_PLATFORM_WIN32