///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/02 22:00)

#include "Example/BookCpp/StandardCppIOStreamsAndLocales/StandardCppIOStreamsAndLocalesExport.h"

#include "Preface.h"
#include "Example/BookCpp/StandardCppIOStreamsAndLocales/Helper/StandardCppIOStreamsAndLocalesClassInvariantMacro.h"

#include <iostream>

using std::cout;
using std::endl;

BookStandardLibrary::StandardCppIOStreamsAndLocales::Preface::Preface() noexcept
{
    STANDARD_CPP_IO_STREAMS_AND_LOCALES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookStandardLibrary::StandardCppIOStreamsAndLocales, Preface)

void BookStandardLibrary::StandardCppIOStreamsAndLocales::Preface::Main() const  
{
    STANDARD_CPP_IO_STREAMS_AND_LOCALES_CLASS_IS_VALID_CONST_9;

    cout << "Hello world" << endl;
}
