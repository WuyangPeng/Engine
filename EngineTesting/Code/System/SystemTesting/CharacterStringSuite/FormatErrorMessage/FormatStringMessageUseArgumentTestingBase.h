/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:03)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_ARGUMENT_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_ARGUMENT_TESTING_BASE_H

#include "FormatMessageTestingBase.h"

#include <array>

namespace System
{
    class FormatStringMessageUseArgumentTestingBase : public FormatMessageTestingBase
    {
    public:
        using ClassType = FormatStringMessageUseArgumentTestingBase;
        using ParentType = FormatMessageTestingBase;

    public:
        explicit FormatStringMessageUseArgumentTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto argumentSize = 6u;
        using ArgumentType = std::array<WindowsDWordPtrSizeType, argumentSize>;

    protected:
        NODISCARD static String GetMessageFormat();
        NODISCARD static String GetMessageFormatResult();
        NODISCARD static String GetMessageVaList();
        NODISCARD static String GetMessageVaListResult();
        NODISCARD WindowsDWordPtrSizeType* GetArgumentsData() noexcept;

    private:
        NODISCARD static WindowsDWordPtrSizeType ReinterpretCast(const TChar* argument) noexcept;

    private:
        ArgumentType arguments;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_ARGUMENT_TESTING_BASE_H