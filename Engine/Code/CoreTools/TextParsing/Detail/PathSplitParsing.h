/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 18:05)

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