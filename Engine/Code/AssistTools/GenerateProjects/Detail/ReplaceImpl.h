///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 09:43)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_REPLACE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_REPLACE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE ReplaceImpl
    {
    public:
        using ClassType = ReplaceImpl;

        using String = System::String;
        using StringView = System::StringView;

    public:
        ReplaceImpl(StringView keyCode, String parameter) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD StringView GetKeyCode() const noexcept;
        NODISCARD String GetParameter() const;

    private:
        StringView keyCode;
        String parameter;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_REPLACE_IMPL_H
