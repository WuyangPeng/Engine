//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/26 11:17)

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

        [[nodiscard]] const String GetReplacing(const String& original) const;

    private:
        using Replacing = std::map<String, String>;

    private:
        void InitReplacing(const std::string& configurationFileName);

    private:
        Replacing m_Replacing;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_IMPL_H
