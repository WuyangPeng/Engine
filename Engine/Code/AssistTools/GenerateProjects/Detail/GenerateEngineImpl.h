///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 20:34)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"

#include <map>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateEngineImpl
    {
    public:
        using ClassType = GenerateEngineImpl;

        using String = System::String;

    public:
        GenerateEngineImpl(const String& input, String output);

        CLASS_INVARIANT_DECLARE;

        void Generate() const;

    private:
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;
        using ReplaceType = std::map<String, String>;

    private:
        void GenerateTop() const;
        void GenerateBinary(const String& configuration) const;
        void GenerateRun() const;
        void GenerateDoxygen() const;
        void GenerateDoc() const;
        void GenerateBat() const;
        void GenerateCode() const;
        void GenerateWindows() const;

        void GenerateBinaryConfiguration(const String& configuration, const String& staticDescribe) const;

        void GenerateRunBat() const;
        void GenerateRunBat(const String& moduleName) const;

        void GenerateCodeProject() const;
        void GenerateCodeHelper() const;

        void GenerateCodeModule() const;
        void GenerateCodeModule(const GameModule& gameModule) const;
        void GenerateCodeModuleCore(const GameModule& gameModule) const;
        void GenerateCodeModuleMiddleLayer(const GameModule& gameModule) const;
        void GenerateCodeModuleExe(const GameModule& gameModule) const;
        void GenerateCodeModuleCoreEngine(const GameModule& gameModule) const;
        void GenerateCodeModuleCoreHelper(const GameModule& gameModule) const;
        void GenerateCodeModuleMiddleLayerHelper(const GameModule& gameModule) const;
        void GenerateCodeModuleMiddleLayerInput(const GameModule& gameModule) const;
        void GenerateCodeModuleMiddleLayer(const GameModule& gameModule, const MiddleLayerModule& middleLayerModule) const;

        void GenerateWindowsProject() const;
        void GenerateWindowsProjectVcxproj() const;
        void GenerateWindowsProjectModule(const GameModule& gameModule) const;

        void GenerateWindowsProjectResource() const;
        void GenerateWindowsProjectResourceTodo() const;
        void GenerateWindowsProjectConfiguration() const;

        void GenerateWindowsProjectModuleCore(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleExe(const GameModule& gameModule) const;

        void GenerateWindowsProjectModuleCoreResource(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleMiddleLayerResource(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleExeResource(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleExeConfiguration(const GameModule& gameModule) const;

        void GenerateWindowsProjectModuleCoreResourceTodo(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleMiddleLayerResourceTodo(const GameModule& gameModule) const;
        void GenerateWindowsProjectModuleExeResourceTodo(const GameModule& gameModule) const;

        void Generate(const String& inputFileName, const String& outputFileName) const;
        void Generate(const String& inputFileName, const String& outputFileName, const ReplaceType& replace) const;
        void Generate(const String& inputFileName, const String& outputFileName, bool isClient) const;
        void GenerateUtf8(const String& inputFileName, const String& outputFileName) const;
        void GenerateUtf8(const String& inputFileName, const String& outputFileName, const ReplaceType& replace) const;

    private:
        String input;
        String output;
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_ENGINE_IMPL_H
