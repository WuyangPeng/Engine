///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 14:10)

#ifndef CORE_TOOLS_TEXT_PARSING_PATH_SPLIT_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_PATH_SPLIT_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE PathSplitParsing final
    {
    public:
        using ClassType = PathSplitParsing;

        using String = System::String;

    public:
        explicit PathSplitParsing(String path);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetNameSpace() const;
        NODISCARD String GetCSVClassName() const;

    private:
        using SplitContainer = std::vector<String>;

    private:
        void Parsing();
        void ParsingNameSpace(const SplitContainer& splitContainer);
        void ParsingClassName(const SplitContainer& splitContainer);
        NODISCARD SplitContainer SplitPath() const;

    private:
        String path;
        String nameSpace;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_PATH_SPLIT_PARSING_H