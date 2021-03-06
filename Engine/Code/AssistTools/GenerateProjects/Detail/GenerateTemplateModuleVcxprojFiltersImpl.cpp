// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 15:37)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateModuleVcxprojFiltersImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateModuleVcxprojFiltersImpl
	::sm_Extension(SYSTEM_TEXT(".vcxproj.filters"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateModuleVcxprojFiltersImpl
::GenerateTemplateModuleVcxprojFiltersImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& moduleName)
	:ParentType(templateFileName, sm_Extension), m_SolutionName(solutionName), m_ModuleName(moduleName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateModuleVcxprojFiltersImpl)

void AssistTools::GenerateTemplateModuleVcxprojFiltersImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newModuleName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1; 

	VariableType newVariable;
	newVariable.insert(make_pair(m_SolutionName, newSolutionName));
	newVariable.insert(make_pair(m_ModuleName, newModuleName));

	return ParentType::Generate (resourceDirectory, newSolutionName + newModuleName, newVariable);
}

/*
示例模板：
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="源文件">
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
    <Filter Include="头文件">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hpp;hxx;hm;inl;inc;xsd</Extensions>
    </Filter>
    <Filter Include="资源文件">
      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>
      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>
    </Filter>
    <Filter Include="Macro 头文件">
      <UniqueIdentifier>{2568c3c7-748d-400d-919c-9010c41965ac}</UniqueIdentifier>
    </Filter>
    <Filter Include="System 头文件">
      <UniqueIdentifier>{cea07251-dd36-4d76-bc1f-9fc8375048c0}</UniqueIdentifier>
    </Filter>
    <Filter Include="System 源文件">
      <UniqueIdentifier>{a74e036c-6060-4d05-88f8-fef5d2728105}</UniqueIdentifier>
    </Filter>
    <Filter Include="Resource 头文件">
      <UniqueIdentifier>{53d3d6c1-29b4-4af2-bc72-f56bc250d878}</UniqueIdentifier>
    </Filter>
    <Filter Include="Resource 源文件">
      <UniqueIdentifier>{c478207c-75af-4ffc-b38c-828739dff4c6}</UniqueIdentifier>
    </Filter>
    <Filter Include="Rendering 头文件">
      <UniqueIdentifier>{af557de0-2918-45b2-b22c-d8b3a42fbe0b}</UniqueIdentifier>
    </Filter>
    <Filter Include="Rendering 源文件">
      <UniqueIdentifier>{7fbbfba7-84e4-4dff-9384-a6889f5119ab}</UniqueIdentifier>
    </Filter>
    <Filter Include="PhysicalModelling 头文件">
      <UniqueIdentifier>{4f4d252f-9fbe-49f1-ab9a-3a80aefaf65a}</UniqueIdentifier>
    </Filter>
    <Filter Include="PhysicalModelling 源文件">
      <UniqueIdentifier>{5f83cdbe-95ec-4912-a672-26687d1c84af}</UniqueIdentifier>
    </Filter>
    <Filter Include="ObjectLogic 头文件">
      <UniqueIdentifier>{b01fe609-8870-4046-82ef-f3c7ae4390f9}</UniqueIdentifier>
    </Filter>
    <Filter Include="ObjectLogic 源文件">
      <UniqueIdentifier>{90fc8e7f-037e-4b7b-b0d3-b48ddd0f9906}</UniqueIdentifier>
    </Filter>
    <Filter Include="Network 头文件">
      <UniqueIdentifier>{8b932109-b8e8-4d89-bfa6-665ad6fb0ace}</UniqueIdentifier>
    </Filter>
    <Filter Include="Network 源文件">
      <UniqueIdentifier>{ade9ea96-19ed-4574-a0ea-ea6c1172b1af}</UniqueIdentifier>
    </Filter>
    <Filter Include="Message 头文件">
      <UniqueIdentifier>{ec609e40-ef43-41a9-8849-06ce50365c25}</UniqueIdentifier>
    </Filter>
    <Filter Include="Message 源文件">
      <UniqueIdentifier>{b39503d0-05f3-4b77-949a-bb36067766b5}</UniqueIdentifier>
    </Filter>
    <Filter Include="Input 头文件">
      <UniqueIdentifier>{e6db37fa-9ed9-41a4-b864-8ad78b3eb20f}</UniqueIdentifier>
    </Filter>
    <Filter Include="Input 模板文件">
      <UniqueIdentifier>{700e3886-c745-44c0-a0f0-2f50360a38c1}</UniqueIdentifier>
    </Filter>
    <Filter Include="Input 源文件">
      <UniqueIdentifier>{b5007146-a72f-4fc6-a96e-62775aa77ce9}</UniqueIdentifier>
    </Filter>
    <Filter Include="GUI 头文件">
      <UniqueIdentifier>{103e50ab-7021-4d86-a7cd-f1d4e56f8fbd}</UniqueIdentifier>
    </Filter>
    <Filter Include="GUI 源文件">
      <UniqueIdentifier>{e941651f-b1c9-46ab-bd00-797470af6103}</UniqueIdentifier>
    </Filter>
    <Filter Include="Event 头文件">
      <UniqueIdentifier>{3e8f247c-7574-47bd-b6e5-46608bf25406}</UniqueIdentifier>
    </Filter>
    <Filter Include="Event 源文件">
      <UniqueIdentifier>{92e9eb82-9f9d-4f65-bdda-a05a869d69cc}</UniqueIdentifier>
    </Filter>
    <Filter Include="CameraSystems 头文件">
      <UniqueIdentifier>{9e1ddb3b-8e32-41ca-a8b1-e773b6c05e18}</UniqueIdentifier>
    </Filter>
    <Filter Include="CameraSystems 源文件">
      <UniqueIdentifier>{e4a5f17b-fdc4-46ca-ae41-c728ea2caad0}</UniqueIdentifier>
    </Filter>
    <Filter Include="Audio 头文件">
      <UniqueIdentifier>{9138b8c8-d68c-46ca-be14-ecd6a76ccba6}</UniqueIdentifier>
    </Filter>
    <Filter Include="Audio 源文件">
      <UniqueIdentifier>{4067a294-283c-4974-a9d9-182e1ca42875}</UniqueIdentifier>
    </Filter>
    <Filter Include="ArtificialIntellegence 头文件">
      <UniqueIdentifier>{eb35e5bd-6ad8-4b58-a9d4-32d9460aecfb}</UniqueIdentifier>
    </Filter>
    <Filter Include="ArtificialIntellegence 源文件">
      <UniqueIdentifier>{a8c88c4c-1821-4984-a5af-38dbc7317b7a}</UniqueIdentifier>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <None Include="Resource\Update.txt">
      <Filter>资源文件</Filter>
    </None>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerDll.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerExport.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerFwd.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerImport.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerLib.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayerNoImport.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\%DllProjectName%MiddleLayerClassInvariantMacro.h">
      <Filter>Macro 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\%DllProjectName%MiddleLayerCustomAssertMacro.h">
      <Filter>Macro 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\Macro.h">
      <Filter>Macro 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\MacroFwd.h">
      <Filter>Macro 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\UserMacro.h">
      <Filter>Macro 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Macro\ExportMacro.h">
      <Filter>Macro 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\%DllProjectName%MiddleLayer.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegence.h">
      <Filter>ArtificialIntellegence 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegenceFwd.h">
      <Filter>ArtificialIntellegence 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegenceManager.h">
      <Filter>ArtificialIntellegence 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\AudioFwd.h">
      <Filter>Audio 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\AudioManager.h">
      <Filter>Audio 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\Audio.h">
      <Filter>Audio 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystems.h">
      <Filter>CameraSystems 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystemsFwd.h">
      <Filter>CameraSystems 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystemsManager.h">
      <Filter>CameraSystems 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\Event.h">
      <Filter>Event 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\EventFwd.h">
      <Filter>Event 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\EventManager.h">
      <Filter>Event 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUIFwd.h">
      <Filter>GUI 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUIManager.h">
      <Filter>GUI 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUI.h">
      <Filter>GUI 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\Input.h">
      <Filter>Input 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\InputFwd.h">
      <Filter>Input 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\InputManager.h">
      <Filter>Input 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Input\InputManagerDetail.h">
      <Filter>Input 模板文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\MessageFwd.h">
      <Filter>Message 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\MessageManager.h">
      <Filter>Message 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\Message.h">
      <Filter>Message 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\NetworkManager.h">
      <Filter>Network 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\Network.h">
      <Filter>Network 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\NetworkFwd.h">
      <Filter>Network 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogic.h">
      <Filter>ObjectLogic 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogicFwd.h">
      <Filter>ObjectLogic 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogicManager.h">
      <Filter>ObjectLogic 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModellingManager.h">
      <Filter>PhysicalModelling 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModelling.h">
      <Filter>PhysicalModelling 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModellingFwd.h">
      <Filter>PhysicalModelling 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\RenderingFwd.h">
      <Filter>Rendering 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\Rendering.h">
      <Filter>Rendering 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\RenderingManager.h">
      <Filter>Rendering 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\Resource.h">
      <Filter>Resource 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\ResourceManager.h">
      <Filter>Resource 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\ResourceFwd.h">
      <Filter>Resource 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\SystemFwd.h">
      <Filter>System 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\SystemManager.h">
      <Filter>System 头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\System.h">
      <Filter>System 头文件</Filter>
    </ClInclude>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\DllLib.cpp">
      <Filter>源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\DllMain.cpp">
      <Filter>源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ArtificialIntellegence\ArtificialIntellegenceManager.cpp">
      <Filter>ArtificialIntellegence 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Audio\AudioManager.cpp">
      <Filter>Audio 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\CameraSystems\CameraSystemsManager.cpp">
      <Filter>CameraSystems 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Event\EventManager.cpp">
      <Filter>Event 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\GUI\GUIManager.cpp">
      <Filter>GUI 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Message\MessageManager.cpp">
      <Filter>Message 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Network\NetworkManager.cpp">
      <Filter>Network 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\ObjectLogic\ObjectLogicManager.cpp">
      <Filter>ObjectLogic 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\PhysicalModelling\PhysicalModellingManager.cpp">
      <Filter>PhysicalModelling 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Rendering\RenderingManager.cpp">
      <Filter>Rendering 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\Resource\ResourceManager.cpp">
      <Filter>Resource 源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%MiddleLayer\System\SystemManager.cpp">
      <Filter>System 源文件</Filter>
    </ClCompile> 
  </ItemGroup>
</Project>
*/