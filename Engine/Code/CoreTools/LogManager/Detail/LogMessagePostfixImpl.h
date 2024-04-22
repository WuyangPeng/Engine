/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:51)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

    namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogMessagePostfixImpl final
    {
    public:
        using ClassType = LogMessagePostfixImpl;

        using String = System::String;

    public:
        LogMessagePostfixImpl(AppenderPrint appenderPrint, LogLevel level, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetPostfix() const;
        NODISCARD int GetPostfixSize() const;

    private:
        void GeneratePostfix();
        void GenerateFunctionDescribedPostfix();

    private:
        String postfix;
        AppenderPrint appenderPrint;
        LogLevel level;
        FunctionDescribed functionDescribed;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_IMPL_H
