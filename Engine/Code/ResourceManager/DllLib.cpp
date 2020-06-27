// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/17 10:21)

// ��Դ����⣨ResourceManager����װ���������Դ����
// ��Դ�����λ������ĵ��Ĳ㣬ֻ������������е�CoreTools�⡢Mathematics�⣬
// ��ʹ��boost��stlsoft���߿⡣������άģ����Դ��������Դ��������Դ��������Դ��������Դ����ײ��Դ�������������Ϸ����͵�ͼ

// ��Դ������������ģ�飺
// 1.	Macro���꣩
// 2.	ThreeDimensionalModel����άģ����Դ��
// 3.	Texture��������Դ��
// 4.	Material��������Դ��
// 5.	Font��������Դ��
// 6.	Skeleton��������Դ��
// 7.	Collision����ײ��Դ��
// 8.	PhysicalParameters�����������
// 9.	GameWorldMap����Ϸ����͵�ͼ��
// 10.	Miscellaneous�����

#include "ResourceManager/ResourceManagerExport.h"

#include "ResourceManager/ResourceManager.h"

#include "Mathematics/MathematicsLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

	#include "DllLib.h"

#else // BUILDING_RESOURCE_MANAGER_STATIC

	namespace ResourceManager
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_RESOURCE_MANAGER_STATIC

	// ��Ϸ��̾���7 ��1�� 1.1 ����Դ�����㷨