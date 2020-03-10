// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:29)

// �û�����⣨UserInterface��λ������ĵ���㣬ֻ������������е�System��CoreTools��Mathematics��Rendering�⣬
// ��ʹ��boost��stlsoft������������صĹ��߿⡣
 
// �û�������������ģ�飺
// 1.	Macro���꣩
// 2.   Configuration �����ã�
// 3.	Interface���ӿڣ�
// 4.	wxWidgets��wxWidgets��
// 5.	FLTK��FLTK��
// 6.	Trixul��Trixul��
// 7.	XFree86��XFree86�� 

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterface.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Rendering/RenderingLib.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

	#include "DllLib.h"

#else // BUILDING_USER_INTERFACE_STATIC

	namespace Animation
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_USER_INTERFACE_STATIC
