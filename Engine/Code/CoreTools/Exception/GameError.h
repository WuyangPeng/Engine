///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 12:33)

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
        static_assert(std::is_enum<E>::value, "E must be an enum.");

        using ClassType = GameError<E>;
        using ParentType = Error;

    public:
        GameError(const FunctionDescribed& functionDescribed, const LastError& lastError, E errorCode, const String& message);
        GameError(const FunctionDescribed& functionDescribed, WindowError lastError, E errorCode, const String& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD E GetErrorCode() const noexcept;

        NODISCARD const String GetError() const override;

    protected:
        NODISCARD virtual const String GetErrorCodeDescribed() const;

    private:
        E errorCode;
    };
}

#endif  // CORE_TOOLS_EXCEPTION_GAME_ERROR_H