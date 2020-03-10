// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 13:23)

// �ű��⣨Script��λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬
// ��ʹ��boost��stlsoft�������ű���صĹ��߿⡣
// ��Ҫ�Խű��ĵ��ýӿڽ��з�װ��

// �ű����������ģ�飺
// 1.	Macro���꣩
// 2.   Configuration �����ã�
// 3.	Interface���ӿڣ�
// 4.	Java��Java��
// 5.	Lua��lua��
// 6.	Perl��Perl��
// 7.	Python��Python��
// 8.	TCREScript��TCREScript�� 

#include "Script/ScriptExport.h"

#include "Script/Script.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_SCRIPT_STATIC

	#include "DllLib.h"

#else // BUILDING_SCRIPT_STATIC

	namespace Script
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SCRIPT_STATIC