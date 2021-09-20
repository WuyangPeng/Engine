///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:41)

#include "StandardCppIOStreamsAndLocalesPrefaceTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/StandardCppIOStreamsAndLocales/Helper/StandardCppIOStreamsAndLocalesClassInvariantMacro.h"
#include "Example/BookCpp/StandardCppIOStreamsAndLocales/Preface/Preface.h"

BookStandardLibrary::StandardCppIOStreamsAndLocales::StandardCppIOStreamsAndLocalesPrefaceTesting::StandardCppIOStreamsAndLocalesPrefaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    STANDARD_CPP_IO_STREAMS_AND_LOCALES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary::StandardCppIOStreamsAndLocales, StandardCppIOStreamsAndLocalesPrefaceTesting)

void BookStandardLibrary::StandardCppIOStreamsAndLocales::StandardCppIOStreamsAndLocalesPrefaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookStandardLibrary::StandardCppIOStreamsAndLocales::StandardCppIOStreamsAndLocalesPrefaceTesting::MainTest()  
{
    const Preface preface{};

    preface.Main();
}
