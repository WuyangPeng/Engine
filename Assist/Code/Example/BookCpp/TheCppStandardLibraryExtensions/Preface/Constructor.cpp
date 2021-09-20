///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#include "Example/BookCpp/TheCppStandardLibraryExtensions/TheCppStandardLibraryExtensionsExport.h"

#include "C.h"
#include "Constructor.h"
#include "Example/BookCpp/TheCppStandardLibraryExtensions/Helper/TheCppStandardLibraryExtensionsClassInvariantMacro.h"

BookBoost::TheCppStandardLibraryExtensions::Constructor::Constructor() noexcept
{
    THE_CPP_STANDARD_LIBRARY_EXTENSIONS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookBoost::TheCppStandardLibraryExtensions, Constructor)

void BookBoost::TheCppStandardLibraryExtensions::Constructor::Main() const noexcept
{
    THE_CPP_STANDARD_LIBRARY_EXTENSIONS_CLASS_IS_VALID_CONST_9;

    C c{};
}
