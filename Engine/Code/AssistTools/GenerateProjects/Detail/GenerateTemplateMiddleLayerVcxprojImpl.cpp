///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 11:15)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMiddleLayerVcxprojImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateMiddleLayerVcxprojImpl::extension{ SYSTEM_TEXT(".vcxproj"s) };

AssistTools::GenerateTemplateMiddleLayerVcxprojImpl::GenerateTemplateMiddleLayerVcxprojImpl(const System::String& templateFileName, const System::String& projectName, const System::String& managerName, const System::String& includeName)
    : ParentType{ templateFileName, extension }, projectName{ projectName }, managerName{ managerName }, includeName{ includeName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateMiddleLayerVcxprojImpl)

void AssistTools::GenerateTemplateMiddleLayerVcxprojImpl::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { projectName, solutionName }, { managerName, newManagerName }, { includeName, newIncludeName } };

    return ParentType::Generate(resourceDirectory, solutionName + newManagerName, newVariable);
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
    <ProjectGuid>{B123CF0F-DC70-4582-A1B3-77C54B2010F2}</ProjectGuid>
    <Keyword>Win32Proj</Keyword>
    <RootNamespace>%DllProjectName%%ManagerName%</RootNamespace>
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
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegence.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegenceFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegenceManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\Audio.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\AudioFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\AudioManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystems.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystemsFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystemsManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\Event.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\EventFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\EventManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayer.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerDll.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerExport.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerImport.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerLib.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerNoImport.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUI.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUIFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUIManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\Input.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\InputFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\InputManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\InputManagerDetail.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\ExportMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\%DllProjectName%MiddleLayerClassInvariantMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\%DllProjectName%MiddleLayerCustomAssertMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\Macro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\MacroFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\UserMacro.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\Message.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\MessageFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\MessageManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\Network.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\NetworkFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\NetworkManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogic.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogicFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogicManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModelling.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModellingFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModellingManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\Rendering.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\RenderingFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\RenderingManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\Resource.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\ResourceFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\ResourceManager.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\System.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\SystemFwd.h" />
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\SystemManager.h" />
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegenceManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\AudioManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystemsManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\DllLib.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\DllMain.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\EventManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUIManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\MessageManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\NetworkManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogicManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModellingManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\RenderingManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\ResourceManager.cpp" />
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\SystemManager.cpp" />
  </ItemGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>
*/