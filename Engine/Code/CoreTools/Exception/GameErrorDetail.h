/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 23:46)

#ifndef CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H
#define CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H

#include "GameError.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename E>
requires(std::is_enum_v<E>)
CoreTools::GameError<E>::GameError(const FunctionDescribed& functionDescribed, const LastError& lastError, E errorCode, const String& message)
    : ParentType{ functionDescribed, lastError, message }, errorCode{ errorCode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename E>
requires(std::is_enum_v<E>)
CoreTools::GameError<E>::GameError(const FunctionDescribed& functionDescribed, WindowError lastError, E errorCode, const String& message)
    : ParentType{ functionDescribed, lastError, message }, errorCode{ errorCode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E>
requires(std::is_enum_v<E>)
bool CoreTools::GameError<E>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E>
requires(std::is_enum_v<E>)
E CoreTools::GameError<E>::GetErrorCode() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return errorCode;
}

template <typename E>
requires(std::is_enum_v<E>)
System::String CoreTools::GameError<E>::GetError() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto error = GetErrorCodeDescribed();

    if (!error.empty())
    {
        error += SYSTEM_TEXT(" ");
    }

    error += ParentType::GetError();

    return error;
}

template <typename E>
requires(std::is_enum_v<E>)
System::String CoreTools::GameError<E>::GetErrorCodeDescribed() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto errorCodeDescribed = SYSTEM_TEXT("错误码 = ") + System::ToString(System::EnumCastUnderlying(errorCode));

    EXCEPTION_TRY
    {
        const auto errorName = StringConversion::MultiByteConversionStandard(typeid(ClassType).name());

        return SYSTEM_TEXT("异常名：") + errorName + SYSTEM_TEXT("，") + errorCodeDescribed + SYSTEM_TEXT("，");
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)

    return errorCodeDescribed;
}

#endif  // CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H