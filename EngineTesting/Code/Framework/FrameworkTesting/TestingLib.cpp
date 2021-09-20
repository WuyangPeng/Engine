// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/24 12:08)

// ��ܿⵥԪ���԰�������ģ�飺
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

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Rendering/RenderingLib.h"
#include "Framework/FrameworkLib.h"
