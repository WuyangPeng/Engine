// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2019/12/31 14:51)

// ϵͳ�⣨System����װ�˲���ϵͳ��ص��������󣨰���Window��Linux��Macintosh��Android����
// ϵͳ��λ���������ײ㣬��������������е������⣬���߿�ֻ�������freeglut���߿⣬�������������߿⡣
// ʹ�ú�������ľ�̬��Ա��������װ���Ҿ��󲿷ֺ����������noexcept���������ͨ���������ء�
// ����ƽ̨ʹ�õĺ������ϴ�ʱ�����ܻ���ȥ����ֵ�򲿷ֲ���ǿ��ʹ��Ĭ��ֵ������ƽ̨����û����ȷ��ʵ�֡�

// ϵͳ���������ģ�飺
// 1.	Helper��������
// 2.   EnumOperator��ö���������
// 3.	SystemOutput��ϵͳ�����
// 4.	DynamicLink����̬���ӣ�
// 5.	CharacterString���ַ�����
// 6.	Console������̨��
// 7.	MemoryTools���ڴ湤�ߣ�
// 8.	Threading���̣߳�
// 9.	Time��ʱ�䣩
// 10.	FileManager���ļ�����
// 11.	Security����ȫ�ԣ�
// 12.	Network�����磩
// 13.	Window��Window��
// 14.	UserInterface�����棩
// 15.	Com��Com��
// 16.	OpenGL��OpenGL��
// 17.	DirectX��DirectX��
// 18.	Linux��Linux��
// 19.	Macintosh��Macintosh��
// 20.	Android��Android��

#include "System/SystemExport.h"

#include "System/System.h"

#ifndef BUILDING_SYSTEM_STATIC

	#include "DllLib.h"

#else // BUILDING_SYSTEM_STATIC

	namespace System
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_SYSTEM_STATIC 