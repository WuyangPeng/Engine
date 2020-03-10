// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:37)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h"

const System::String AssistTools::GenerateTemplateVcxprojFiltersImpl
	::sm_Extension(SYSTEM_TEXT(".vcxproj.filters"));
 
AssistTools::GenerateTemplateVcxprojFiltersImpl
	::GenerateTemplateVcxprojFiltersImpl(const System::String& templateFileName, const System::String& projectName)
	:ParentType(templateFileName,sm_Extension), m_ProjectName(projectName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

AssistTools::GenerateTemplateVcxprojFiltersImpl
	::~GenerateTemplateVcxprojFiltersImpl()
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateVcxprojFiltersImpl)

void AssistTools::GenerateTemplateVcxprojFiltersImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable;
	newVariable.insert(make_pair(m_ProjectName, solutionName));

	return ParentType::GenerateTo(resourceDirectory, solutionName, newVariable);
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
    <Filter Include="����">
      <UniqueIdentifier>{20621c5d-3c14-4e4e-80d1-8381d6b954a6}</UniqueIdentifier>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Helper.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Message.h">
      <Filter>ͷ�ļ�</Filter>
    </ClInclude>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Helper.cpp">
      <Filter>Դ�ļ�</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Lib.cpp">
      <Filter>Դ�ļ�</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Main.cpp">
      <Filter>Դ�ļ�</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%ExeProjectName%\%ExeProjectName%\%ExeProjectName%Message.cpp">
      <Filter>Դ�ļ�</Filter>
    </ClCompile>
  </ItemGroup>
  <ItemGroup>
    <None Include="Configuration\EnvironmentVariable.json">
      <Filter>����</Filter>
    </None>
    <None Include="Configuration\Log.json">
      <Filter>����</Filter>
    </None>
    <None Include="Resource\Update.txt">
      <Filter>��Դ�ļ�</Filter>
    </None>
  </ItemGroup>
</Project>
*/