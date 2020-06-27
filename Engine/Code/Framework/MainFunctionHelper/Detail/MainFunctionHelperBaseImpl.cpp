// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/20 11:52)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBaseImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

Framework::MainFunctionHelperBaseImpl
	::MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory) noexcept
	:m_EnvironmentDirectory{ environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, MainFunctionHelperBaseImpl);

System::String Framework::MainFunctionHelperBaseImpl
	::GetEngineInstallationDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	// Ӧ�ò�������Ŀ¼�ṹ�����Ŀ⡣
	// ����Ҫ����EnvironmentDirectory�����õĻ�������������Ӧ�ó�����Ҹ��������ļ���
	// EnvironmentDirectory���õ�ֵ���Դ������ж�ȡ����ֱ��ʹ��Ĭ��ֵ��
	return m_EnvironmentDirectory.GetEngineDirectory();
}

Framework::EnvironmentDirectory Framework::MainFunctionHelperBaseImpl
	::GetEnvironmentDirectory() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_EnvironmentDirectory;
} 