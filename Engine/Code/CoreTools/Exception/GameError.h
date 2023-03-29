///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:02)

#ifndef CORE_TOOLS_EXCEPTION_GAME_ERROR_H
#define CORE_TOOLS_EXCEPTION_GAME_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "Error.h"

namespace CoreTools
{
    template <typename E>
    class GameError : public Error
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be an enum.");

        using ClassType = GameError<E>;
        using ParentType = Error;

    public:
        GameError(const FunctionDescribed& functionDescribed, const LastError& lastError, E errorCode, const String& message);
        GameError(const FunctionDescribed& functionDescribed, WindowError lastError, E errorCode, const String& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD E GetErrorCode() const noexcept;

        NODISCARD String GetError() const override;

    protected:
        NODISCARD virtual String GetErrorCodeDescribed() const;

    private:
        E errorCode;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_GAME_ERROR_H