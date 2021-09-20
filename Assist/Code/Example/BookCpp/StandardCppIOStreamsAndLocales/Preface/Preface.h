///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/02 22:00)

#ifndef STANDARD_CPP_IO_STREAMS_AND_LOCALES_PREFACE_BALANCE_H
#define STANDARD_CPP_IO_STREAMS_AND_LOCALES_PREFACE_BALANCE_H

#include "Example/BookCpp/StandardCppIOStreamsAndLocales/StandardCppIOStreamsAndLocalesDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookStandardLibrary
{
    namespace StandardCppIOStreamsAndLocales
    {
        class STANDARD_CPP_IO_STREAMS_AND_LOCALES_DEFAULT_DECLARE Preface final
        {
        public:
            using ClassType = Preface;

        public:
            Preface() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const;
        };
    }
}

#endif  // STANDARD_CPP_IO_STREAMS_AND_LOCALES_PREFACE_BALANCE_H
