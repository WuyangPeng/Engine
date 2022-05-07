///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:58)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/EngineConfiguration/StringReplacing.h"

#include <string>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateDirectoryImpl
    {
    public:
        using ClassType = GenerateTemplateDirectoryImpl;

    public:
        GenerateTemplateDirectoryImpl(const System::String& directory, const std::string& configurationFileName);
        virtual ~GenerateTemplateDirectoryImpl() = default;
        GenerateTemplateDirectoryImpl(const GenerateTemplateDirectoryImpl& rhs) = default;
        GenerateTemplateDirectoryImpl& operator=(const GenerateTemplateDirectoryImpl& rhs) = default;
        GenerateTemplateDirectoryImpl(GenerateTemplateDirectoryImpl&& rhs) noexcept = default;
        GenerateTemplateDirectoryImpl& operator=(GenerateTemplateDirectoryImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        NODISCARD System::String GetDirectory() const;
        static NODISCARD System::String GetForwardSlash();
        static NODISCARD System::String GetEngineDirectory();
        static NODISCARD System::String GetProjectName();
        static NODISCARD System::String GetCoreName();
        static NODISCARD System::String GetModuleName();
        static NODISCARD System::String GetExeProjectName();
        static NODISCARD System::String GetDllProjectName();
        static NODISCARD System::String GetIncludeName();
        static NODISCARD System::String GetLogFileName();
        static NODISCARD System::String GetConfigurationDirectory();
        static NODISCARD System::String GetManagerName();
        static NODISCARD System::String GetResource();
        static NODISCARD System::String GetUpdate();
        static NODISCARD System::String GetCodeDirectory();
        static NODISCARD System::String GetTesting();
        static NODISCARD System::String GetDebugLibName();
        static NODISCARD System::String GetReleaseLibName();
        static NODISCARD System::String GetTestingIncludeName();
        static NODISCARD System::String GetNewProjectName();
        static NODISCARD System::String GetGameIncludeName();

        NODISCARD System::String GetReplacing(const System::String& original) const;

    private:
        System::String directory;
        CoreTools::StringReplacing stringReplacing;

        static const System::String forwardSlash;
        static const System::String engineDirectory;
        static const System::String codeDirectory;
        static const System::String projectName;
        static const System::String coreName;
        static const System::String moduleName;
        static const System::String exeProjectName;
        static const System::String dllProjectName;
        static const System::String includeName;
        static const System::String logFileName;
        static const System::String configurationDirectory;
        static const System::String managerName;
        static const System::String resource;
        static const System::String update;
        static const System::String testing;
        static const System::String debugLibName;
        static const System::String releaseLibName; 
        static const System::String gameIncludeName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DIRECTORY_IMPL_H
