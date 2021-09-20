///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/02 22:00)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "ArrangementStyle.h"
#include "ArrangementStyleDeclaration.h"
#include "Example/BookCpp/ExtendedSTL/Helper/ExtendedSTLClassInvariantMacro.h"

#ifdef SYSTEM_PLATFORM_LINUX

    #include <unixstl/filesystem/readdir_sequence.hpp>

#endif  // SYSTEM_PLATFORM_LINUX

#include <iostream>

BookStandardLibrary::ExtendedSTL::ArrangementStyle::ArrangementStyle() noexcept
{
    EXTENDED_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookStandardLibrary::ExtendedSTL, ArrangementStyle)

void BookStandardLibrary::ExtendedSTL::ArrangementStyle::Main() const noexcept
{
    EXTENDED_STL_CLASS_IS_VALID_CONST_9;

#ifdef SYSTEM_PLATFORM_LINUX
    using RdsT = unixstl::readdir_sequence;
    RdsT files(".", RdsT::files);

    for (RdsT::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        std::cout << *b << std::endl;
    }

    for (RdsT::const_iterator b = files.begin(), e = files.end(); b != e; ++b)
    {
        std::cout << *b << std::endl;
    }

    std::copy(files.begin(), files.end(), std::ostream_iterator<RdsT::value_type>(std::cout, "\n"));

#endif  // SYSTEM_PLATFORM_LINUX
}
