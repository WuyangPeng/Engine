/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:44)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <map>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StringReplacingImpl final
    {
    public:
        using ClassType = StringReplacingImpl;

        using String = System::String;

    public:
        explicit StringReplacingImpl(const std::string& configurationFileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetReplacing(const String& original) const;

    private:
        using Replacing = std::map<String, String>;

    private:
        void InitReplacing(const std::string& configurationFileName);

    private:
        Replacing replacing;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H
