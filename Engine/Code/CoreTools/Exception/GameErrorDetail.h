///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:02)

#ifndef CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H
#define CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H

#include "GameError.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename E>
CoreTools::GameError<E>::GameError(const FunctionDescribed& functionDescribed, const LastError& lastError, E errorCode, const String& message)
    : ParentType{ functionDescribed, lastError, message }, errorCode{ errorCode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename E>
CoreTools::GameError<E>::GameError(const FunctionDescribed& functionDescribed, WindowError lastError, E errorCode, const String& message)
    : ParentType{ functionDescribed, lastError, message }, errorCode{ errorCode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename E>
bool CoreTools::GameError<E>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename E>
E CoreTools::GameError<E>::GetErrorCode() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return errorCode;
}

template <typename E>
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
System::String CoreTools::GameError<E>::GetErrorCodeDescribed() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    using namespace std::literals;

    const auto errorCodeDescribed = SYSTEM_TEXT("错误码 = "s) + System::ToString(System::EnumCastUnderlying(errorCode));

    EXCEPTION_TRY
    {
        const auto errorName = StringConversion::MultiByteConversionStandard(typeid(ClassType).name());

        return SYSTEM_TEXT("异常名："s) + errorName + SYSTEM_TEXT("，"s) + errorCodeDescribed + SYSTEM_TEXT("，"s);
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)

    return errorCodeDescribed;
}

#endif  // CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H