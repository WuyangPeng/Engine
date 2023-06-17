///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 11:19)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateVcxprojImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateVcxprojImpl::extension{ SYSTEM_TEXT(".vcxproj"s) };

AssistTools::GenerateTemplateVcxprojImpl::GenerateTemplateVcxprojImpl(const System::String& templateFileName, const System::String& projectName, const System::String& includeName)
    : ParentType{ templateFileName, extension }, projectName{ projectName }, includeName{ includeName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateVcxprojImpl)

void AssistTools::GenerateTemplateVcxprojImpl::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { projectName, solutionName }, { includeName, newIncludeName } };

    return ParentType::Generate(resourceDirectory, solutionName, newVariable);
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
    <RootNamespace>%ExeProjectName%</RootNamespace>
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
      <AdditionalIncludeDirectories>$(%IncludeName%);%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
      <TreatWarningAsError>true</TreatWarningAsError>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
      <AdditionalLibraryDirectories>$(ProjectDir)..\..\..\$(Configuration)Windows\;$(EngineDebugLib);$(GameDebugLib);%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
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
      <AdditionalIncludeDirectories>$(%IncludeName%);%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
      <TreatWarningAsError>true</TreatWarningAsError>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <GenerateDebugInformation>true</GenerateDebugInformation>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <AdditionalLibraryDirectories>$(ProjectDir)..\..\..\$(Configuration)Windows\;$(EngineReleaseLib);$(GameReleaseLib);%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>
    </Link>
  </ItemDefinitionGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%.h" />
    <ClInclude Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Helper.h" />
    <ClInclude Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Message.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Helper.cpp" />
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Lib.cpp" />
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Main.cpp" />
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Message.cpp" />
  </ItemGroup>
  <ItemGroup>
    <None Include="Configuration\EnvironmentVariable.json">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
    <None Include="Configuration\Log.json">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
    <None Include="Resource\Update.txt">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>
*/