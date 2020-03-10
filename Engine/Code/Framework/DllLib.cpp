// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 17:38)

// ��ܿ⣨Framework��λ����������ϲ㣬
// ��װ�������ϵͳ��ص��ض����󣨰���Windows��Linux��Android��Macintosh��
// ������������е����п⣬��ʹ��boost��stlsoft���߿⡣

// ��ܿ��������ģ�飺
// 1.  Macro���꣩
// 2.  MainFunctionHelper��������������
// 3.  WindowCreate�����ڴ�����
// 4.  WindowProcess�����ڽ��̣�
// 5.  WindowRegister������ע�ᣩ
// 6.  Application��Ӧ�ã�
// 7.  MiddleLayer���м�㣩
// 8.  WindowsAPIFrame��WindowsAPI��ܣ�
// 9.  OpenGLGlutFrame��Glut��ܣ�
// 10. AndroidFrame��Android��ܣ�
// 11. LinuxFrame��Linux��ܣ�
// 12. MacintoshFrame��Macintosh��ܣ�

#include "Framework/FrameworkExport.h"

#include "Framework/Framework.h" 

#include "System/SystemLib.h"

#include "CoreTools/CoreToolsLib.h"

#include "Network/NetworkLib.h"
#include "Database/DatabaseLib.h"
#include "Script/ScriptLib.h"	
#include "Mathematics/MathematicsLib.h"	
#include "SoundEffect/SoundEffectLib.h"		
#include "InputOutput/InputOutputLib.h"		

#include "ResourceManager/ResourceManagerLib.h"		
#include "Rendering/RenderingLib.h"		
#include "Physics/PhysicsLib.h"		
#include "Imagics/ImagicsLib.h"		

#include "Animation/AnimationLib.h"		
#include "ArtificialIntellegence/ArtificialIntellegenceLib.h"		
#include "UserInterface/UserInterfaceLib.h"	

#include "AssistTools/AssistToolsLib.h"	

#ifndef BUILDING_FRAMEWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_FRAMEWORK_STATIC

	namespace Framework
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FRAMEWORK_STATIC