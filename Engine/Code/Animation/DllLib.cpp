// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.4.0.0 (2020/07/15 14:34)

// �����⣨Animation��λ������ĵ���㣬
// ֻ������������е�CoreTools��Mathematics��Rendering�⣬��ʹ��boost���߿⡣

// �������������ģ�飺
// 1.  Helper��������
// 2.  Sprite�����鶯����
// 3.  Texture����������
// 4.  RigidBodyHierarchy�������νṹ������
// 5.  Skeleton������������
// 6.  PerVertex��ÿ���㶯����
// 7.  MorphTarget������Ŀ�궯����
// 8.  Gradient�����䶯����
// 9.  AnimationManager��������������

#include "Animation/AnimationExport.h"

#include "Animation/Animation.h"

#ifndef BUILDING_ANIMATION_STATIC

	#include "DllLib.h"

#else // BUILDING_ANIMATION_STATIC

	namespace Animation
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_ANIMATION_STATIC