// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 09:45)

// �����⣨Animation��λ������ĵ���㣬
// ֻ������������е�CoreTools��Mathematics��Rendering�⣬��ʹ��boost��stlsoft���߿⡣

// �������������ģ�飺
// 1.  Macro���꣩
// 2.  ConsoleGraph������̨ͼ�Σ�
// 3.  ElfAnimation�����鶯����
// 4.  TextureAnimation����������
// 5.  RigidBodyHierarchyAnimation�������νṹ������
// 6.  SkeletonAnimation������������
// 7.  PerVertexAnimation��ÿ���㶯����
// 8.  MorphTargetAnimation������Ŀ�궯����
// 9.  GradientAnimation�����䶯����
// 10. AnimationManager��������������

#include "Animation/AnimationExport.h"

#include "Animation/Animation.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Rendering/RenderingLib.h"

#ifndef BUILDING_ANIMATION_STATIC

	#include "DllLib.h"

#else // BUILDING_ANIMATION_STATIC

	namespace Animation
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ANIMATION_STATIC