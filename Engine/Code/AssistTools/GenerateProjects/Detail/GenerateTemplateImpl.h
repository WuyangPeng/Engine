///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:02)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <map>
#include <string>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateImpl;
        using VariableType = std::map<System::String, System::String>;

    public:
        GenerateTemplateImpl(const System::String& templateFileName, const System::String& extension);
        virtual ~GenerateTemplateImpl() noexcept = default;
        GenerateTemplateImpl(const GenerateTemplateImpl& rhs) = default;
        GenerateTemplateImpl& operator=(const GenerateTemplateImpl& rhs) = default;
        GenerateTemplateImpl(GenerateTemplateImpl&& rhs) noexcept = default;
        GenerateTemplateImpl& operator=(GenerateTemplateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        NODISCARD static System::String GetTesting();

        void Generate(const System::String& resourceDirectory,
                      const System::String& newProjectName,
                      const VariableType& newVariable) const;

    private:
        using VariableValueType = VariableType::value_type;

    private:
        NODISCARD static System::String ReadFile(const System::String& templateFileName);

        void NewDirectory(const System::String& directory) const;

    private:
        static const System::String forwardSlash;

        System::String fileContent;
        System::String extension;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_IMPL_H
