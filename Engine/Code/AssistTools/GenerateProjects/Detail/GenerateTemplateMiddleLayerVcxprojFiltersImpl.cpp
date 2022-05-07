///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/29 11:14)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMiddleLayerVcxprojFiltersImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateMiddleLayerVcxprojFiltersImpl::extension{ SYSTEM_TEXT(".vcxproj.filters"s) };

AssistTools::GenerateTemplateMiddleLayerVcxprojFiltersImpl::GenerateTemplateMiddleLayerVcxprojFiltersImpl(const System::String& templateFileName, const System::String& projectName, const System::String& managerName)
    : ParentType{ templateFileName, extension }, projectName{ projectName }, managerName{ managerName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateMiddleLayerVcxprojFiltersImpl)

void AssistTools::GenerateTemplateMiddleLayerVcxprojFiltersImpl::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { projectName, solutionName }, { managerName, newManagerName } };

    return ParentType::Generate(resourceDirectory, solutionName + newManagerName, newVariable);
}

/*
ʾ��ģ�壺
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="Դ�ļ�">
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
    <Filter Include="ͷ�ļ�">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hpp;hxx;hm;inl;inc;xsd</Extensions>
    </Filter>
    <Filter Include="��Դ�ļ�">
      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>
      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>
    </Filter>
    <Filter Include="Macro ͷ�ļ�">
      <UniqueIdentifier>{2568c3c7-748d-400d-919c-9010c41965ac}</UniqueIdentifier>
    </Filter>
    <Filter Include="Engine ͷ�ļ�">
      <UniqueIdentifier>{cea07251-dd36-4d76-bc1f-9fc8375048c0}</UniqueIdentifier>
    </Filter>
    <Filter Include="Engine Դ�ļ�">
      <UniqueIdentifier>{a74e036c-6060-4d05-88f8-fef5d2728105}</UniqueIdentifier>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <None Include="Resource\Update.txt">
      <Filter>��Դ�ļ�</Filter>
    </None>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%Dll.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%Export.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%Fwd.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%Import.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%Lib.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%NoImport.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Macro\%DllProjectName%%ManagerName%ClassInvariantMacro.h">
      <Filter>Macro ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Macro\%DllProjectName%%ManagerName%CustomAssertMacro.h">
      <Filter>Macro ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Macro\Macro.h">
      <Filter>Macro ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Macro\MacroFwd.h">
      <Filter>Macro ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Macro\UserMacro.h">
      <Filter>Macro ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Macro\ExportMacro.h">
      <Filter>Macro ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Engine\Engine.h">
      <Filter>Engine ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Engine\EngineFwd.h">
      <Filter>Engine ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\%DllProjectName%%ManagerName%.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Engine\%ManagerName%.h">
      <Filter>Engine ͷ�ļ�</Filter>
    </ClInclude>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\DllLib.cpp">
      <Filter>Դ�ļ�</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\DllMain.cpp">
      <Filter>Դ�ļ�</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%DllProjectName%\%DllProjectName%%ManagerName%\Engine\%ManagerName%.cpp">
      <Filter>Engine Դ�ļ�</Filter>
    </ClCompile>
  </ItemGroup>
</Project>
*/