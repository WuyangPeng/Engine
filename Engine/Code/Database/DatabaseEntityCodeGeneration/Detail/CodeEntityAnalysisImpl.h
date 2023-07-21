///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:01)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_ANALYSIS_IMPL_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_ANALYSIS_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "Database/DatabaseEntityCodeGeneration/CodeEntityClass.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE CodeEntityAnalysisImpl final
    {
    public:
        using ClassType = CodeEntityAnalysisImpl;

        using String = System::String;
        using Container = std::vector<CodeEntityClass>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit CodeEntityAnalysisImpl(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetNamespaceName() const;
        NODISCARD ContainerConstIter GetBegin() const noexcept;
        NODISCARD ContainerConstIter GetEnd() const noexcept;

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;
        using FieldContainer = CodeEntityClass::FieldContainer;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();
        void InsertCodeEntity(const String& entityClassName, const BasicTree& basicTree);
        NODISCARD FieldContainer GetFieldContainer(const BasicTree& entityTree);
        NODISCARD static String GetNamespaceName(const std::string& fileName);

    private:
        String namespaceName;
        std::string fileName;
        Container container;
        BasicTree mainTree;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_ANALYSIS_IMPL_H
