// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 17:54)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBaseImpl.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MainFunctionHelperBaseImpl
	::MainFunctionHelperBaseImpl(const EnvironmentDirectory& environmentDirectory)	
	:m_EnvironmentDirectory{ environmentDirectory }
{
	GenerateEnvironment();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,MainFunctionHelperBaseImpl);

System::String Framework::MainFunctionHelperBaseImpl
	::GetEngineInstallationDirectory() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	// Ӧ�ò�������Ŀ¼�ṹ�����Ŀ⡣
	// ����Ҫ����EnvironmentDirectory�����õĻ�������������Ӧ�ó�����Ҹ��������ļ���
	// EnvironmentDirectory���õ�ֵ���Դ������ж�ȡ����ֱ��ʹ��Ĭ��ֵ��
	return m_EnvironmentDirectory.GetEngineDirectory();
}

// private
void Framework::MainFunctionHelperBaseImpl
	::GenerateEnvironment()
{
	// TODO������·���漰�ļ���
	// BigEndian/LittleEndian��DirectX/OpenGL��
	// �����ֽ�˳����ļ������ƿ�����
	// SYSTEM_BIG_ENDIAN/SYSTEM_LITTLE_ENDIAN���á�
	// ������Ⱦ�����͵��ļ�������������Ⱦ�������ṩ��̬�ַ�����

	// ��Դ�ļ��ĸ�Ŀ¼·��
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetResourcePath());

	// ��ɫ���ļ���·����
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetShaderPath());

	// ���������·����
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetScenePath());

	// ����ͼ���ļ���·����
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetTexturePath());

	// ����/������������·��
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetVertexPath());

	// ͼ���ļ���·����
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetImagePath());

	// �����ļ���·����
	ENVIRONMENT_SINGLETON.InsertDirectory(m_EnvironmentDirectory.GetConfigurationPath());
	ENVIRONMENT_SINGLETON.SetConfigurationPath(m_EnvironmentDirectory.GetConfigurationPath());
}

