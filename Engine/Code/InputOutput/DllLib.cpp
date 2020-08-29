// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 14:38)

// ��������⣨InputOutput��λ������ĵ����㣬��װ�����������������
// ֻ������������е�CoreTools�⡢System�⣬��ʹ��boost��stlsoft���߿⡣

// ����������������ģ�飺
// 1.   Macro���꣩
// 2.	Configuration �����ã�
// 3.	InputInterface������ӿڣ�
// 4.	OutputInterface������ӿڣ�

#include "InputOutput/InputOutputExport.h"

#include "InputOutput/InputOutput.h"

#include "CoreTools/CoreToolsLib.h"
#include "System/SystemLib.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

	#include "DllLib.h"

#else // BUILDING_INPUT_OUTPUT_STATIC

	namespace InputOutput
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_INPUT_OUTPUT_STATIC