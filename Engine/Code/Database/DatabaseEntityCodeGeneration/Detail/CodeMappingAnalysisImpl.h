///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:38)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_ANALYSIS_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_ANALYSIS_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "Database/DatabaseEntityCodeGeneration/CodeMapping.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CodeMappingAnalysisImpl final
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

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_ANALYSIS_IMPL_H
