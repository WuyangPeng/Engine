///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 11:17)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateModuleVcxprojImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateModuleVcxprojImpl::extension{ SYSTEM_TEXT(".vcxproj") };

AssistTools::GenerateTemplateModuleVcxprojImpl::GenerateTemplateModuleVcxprojImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& moduleName, const System::String& includeName)
    : ParentType{ templateFileName, extension }, solutionName{ solutionName }, moduleName{ moduleName }, includeName{ includeName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateModuleVcxprojImpl)

void AssistTools::GenerateTemplateModuleVcxprojImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newModuleName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { solutionName, newSolutionName }, { moduleName, newModuleName }, { includeName, newIncludeName } };

    return ParentType::Generate(resourceDirectory, newSolutionName + newModuleName, newVariable);
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
    <ProjectGuid>{E4E3B6D7-D870-4FF1-977C-A1062AB3F55E}</ProjectGuid>
    <Keyword>Win32Proj</Keyword>
    <RootNamespace>%DllProjectName%%ModuleName%</RootNamespace>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
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
    <None Include="Resource\Update.txt">
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</ExcludedFromBuild>
      <ExcludedFromBuild Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">true</ExcludedFromBuild>
    </None>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Engine\Engine.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Engine\EngineFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Engine\Placeholder.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%Dll.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%Export.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%Fwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%Import.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%Lib.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\%DllProjectName%%ModuleName%NoImport.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Macro\ExportMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Macro\%DllProjectName%%ModuleName%ClassInvariantMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Macro\%DllProjectName%%ModuleName%CustomAssertMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Macro\Macro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Macro\MacroFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Macro\UserMacro.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\DllLib.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\DllMain.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ModuleName%\Engine\Placeholder.cpp" />
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>
*/