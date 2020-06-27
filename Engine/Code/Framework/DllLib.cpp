// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/20 0:01)

// ��ܿ⣨Framework��λ����������ϲ㣬��װ�������ϵͳ��صĻ�����ܣ�����Windows��Linux��Android��Macintosh��������ֱ�ӵ���ϵͳAPI��
// ����������Ϸ�м����л�����ƣ�ʵ�ָ���ϵͳ�ķ��롣
// ��ܿ�������������е����п⣬��ʹ��boost���߿⡣

// ��ܿ��������ģ�飺
// 1.  Helper��������
// 2.  MainFunctionHelper��������������
// 3.  WindowCreate�����ڴ�����
// 4.  WindowProcess�����ڽ��̣�
// 5.  WindowRegister������ע�ᣩ
// 6.  Application��Ӧ�ã�
// 7.  MiddleLayer���м�㣩
// 8.  WindowsAPIFrame��WindowsAPI��ܣ�
// 9.  OpenGLGlutFrame��GLUT��ܣ�
// 10. AndroidFrame��Android��ܣ�
// 11. LinuxFrame��Linux��ܣ�
// 12. MacintoshFrame��Macintosh��ܣ�
// 13. ConsoleFrame������̨��ܣ�

#include "Framework/FrameworkExport.h"

#include "Framework/Framework.h" 

#ifndef BUILDING_FRAMEWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_FRAMEWORK_STATIC
 
	namespace Framework
	{
		void StaticDllLib() noexcept
		{
			
		}
	}

#endif // !BUILDING_FRAMEWORK_STATIC