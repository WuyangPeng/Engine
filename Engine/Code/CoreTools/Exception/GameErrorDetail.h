///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/30 17:06)

#ifndef CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H
#define CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H

#include "GameError.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
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
const System::String CoreTools::GameError<E>::GetError() const
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
const System::String CoreTools::GameError<E>::GetErrorCodeDescribed() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto errorCodeDescribed = SYSTEM_TEXT("������ = ") + System::ToString(System::EnumCastUnderlying(errorCode));

    EXCEPTION_TRY
    {
        auto errorName = StringConversion::MultiByteConversionStandard(typeid(ClassType).name());

        return SYSTEM_TEXT("�쳣����") + errorName + SYSTEM_TEXT("��") + errorCodeDescribed;
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools);

    return errorCodeDescribed;
}

#endif  // CORE_TOOLS_EXCEPTION_GAME_ERROR_DETAIL_H