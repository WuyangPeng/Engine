///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/15 10:23)

#ifndef CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMapping.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CodeMappingAnalysisImpl final
    {
    public:
        using ClassType = CodeMappingAnalysisImpl;

        using String = System::String;

    public:
        explicit CodeMappingAnalysisImpl(String fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetElement(const String& codeKey) const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();

    private:
        String fileName;
        CodeMapping codeMapping;
        BasicTree mainTree;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_IMPL_H
