///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:42)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateVcxprojImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTestingTemplateVcxprojImpl::extension{ SYSTEM_TEXT(".vcxproj"s) };

AssistTools::GenerateTestingTemplateVcxprojImpl::GenerateTestingTemplateVcxprojImpl(const System::String& templateFileName,
                                                                                    const System::String& projectName,
                                                                                    const System::String& moduleName,
                                                                                    const System::String& includeName,
                                                                                    const System::String& testingIncludeName,
                                                                                    const System::String& debugLibName,
                                                                                    const System::String& releaseLibName)
    : ParentType{ templateFileName, extension },
      projectName{ projectName },
      moduleName{ moduleName },
      includeName{ includeName },
      testingIncludeName{ testingIncludeName },
      debugLibName{ debugLibName },
      releaseLibName{ releaseLibName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateVcxprojImpl)

void AssistTools::GenerateTestingTemplateVcxprojImpl::GenerateTo(const System::String& resourceDirectory,
                                                                 const System::String& solutionName,
                                                                 const System::String& newModuleName,
                                                                 const System::String& newIncludeName,
                                                                 const System::String& newTestingIncludeName,
                                                                 const System::String& newDebugLibName,
                                                                 const System::String& newReleaseLibName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{};
    newVariable.emplace(projectName, solutionName);
    newVariable.emplace(moduleName, newModuleName);
    newVariable.emplace(includeName, newIncludeName);
    newVariable.emplace(testingIncludeName, newTestingIncludeName);
    newVariable.emplace(debugLibName, newDebugLibName);
    newVariable.emplace(releaseLibName, newReleaseLibName);

    return ParentType::Generate(resourceDirectory, solutionName + newModuleName + GetTesting(), newVariable);
}

/*
示例模板：
<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|Win32">
      <Configuration>Debug</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|Win32">
      <Configuration>Release</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <ProjectGuid>{53AA2778-5CF8-4BEC-BB96-75BD12D8E678}</ProjectGuid>
    <Keyword>Win32Proj</Keyword>
    <RootNamespace>%NewProjectName%Testing</RootNamespace>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration">
    <ConfigurationType>Application</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <WholeProgramOptimization>true</WholeProgramOptimization>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings">
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <LinkIncremental>true</LinkIncremental>
    <OutDir>$(ProjectDir)..\..\..\$(Configuration)Windows\</OutDir>
    <TargetName>$(ProjectName)D</TargetName>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <LinkIncremental>false</LinkIncremental>
    <OutDir>$(ProjectDir)..\..\..\$(Configuration)Windows\</OutDir>
  </PropertyGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <ClCompile>
      <PrecompiledHeader>
      </PrecompiledHeader>
      <WarningLevel>Level4</WarningLevel>
      <Optimization>Disabled</Optimization>
      <PreprocessorDefinitions>OPEN_USE_MEMORY;OPEN_ASSERT;OPEN_CLASS_INVARIANT;WIN32;_DEBUG;_WINDOWS;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <AdditionalIncludeDirectories>$(%GameIncludeName%);$(%TestingIncludeName%);%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
      <TreatWarningAsError>true</TreatWarningAsError>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
      <AdditionalLibraryDirectories>$(ProjectDir)..\..\..\$(Configuration)Windows\;$(EngineDebugLib);$(GameDebugLib);$(%DebugLibName%);%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
    </Link>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <ClCompile>
      <WarningLevel>Level4</WarningLevel>
      <PrecompiledHeader>
      </PrecompiledHeader>
      <Optimization>MaxSpeed</Optimization>
      <FunctionLevelLinking>true</FunctionLevelLinking>
      <IntrinsicFunctions>true</IntrinsicFunctions>
      <PreprocessorDefinitions>WIN32;NDEBUG;_WINDOWS;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <AdditionalIncludeDirectories>$(%GameIncludeName%);$(%TestingIncludeName%);%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
      <TreatWarningAsError>true</TreatWarningAsError>
    </ClCompile>
    <Link>
      <SubSystem>Console</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <AdditionalLibraryDirectories>$(ProjectDir)..\..\..\$(Configuration)Windows\;$(EngineReleaseLib);$(GameReleaseLib);$(%ReleaseLibName%);%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
    </Link>
  </ItemDefinitionGroup>
  <ItemGroup>
    <None Include="Configuration\EnvironmentVariable.json">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
    <None Include="Configuration\Log.json">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
    <None Include="Configuration\Testing.json">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
    <None Include="Resource\Update.txt">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%NewProjectName%Testing\%NewProjectName%%ModuleName%Testing\TestingHelper.cpp" />
    <ClCompile Include="..\..\..\Code\%NewProjectName%Testing\%NewProjectName%%ModuleName%Testing\TestingLib.cpp" />
    <ClCompile Include="..\..\..\Code\%NewProjectName%Testing\%NewProjectName%%ModuleName%Testing\TestingMain.cpp" />
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%NewProjectName%Testing\%NewProjectName%%ModuleName%Testing\Testing.h" />
    <ClInclude Include="..\..\..\Code\%NewProjectName%Testing\%NewProjectName%%ModuleName%Testing\TestingHelper.h" />
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>
*/