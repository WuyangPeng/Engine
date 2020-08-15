// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 14:44)

// ����⣨Physics����װ�����������ģ�顣
// �����λ������ĵ��Ĳ㣬ֻ������������е�CoreTools��Mathematics�⣬��ʹ��boost��stlsoft���߿⡣

// ������������ģ�飺
// 1.	Macro���꣩
// 2.	CollisionDetection����ײ��⣩
// 3.	Fluid�����壩
// 4.	Intersection���ཻ��
// 5.	LCPSolver��LCP��⣩
// 6.	ParticleSystem������ϵͳ��
// 7.	RigidBody�����壩
// 8.	Miscellaneous�����

#include "Physics/PhysicsExport.h"

#include "Physics/Physics.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"

#ifndef BUILDING_PHYSICS_STATIC

	#include "DllLib.h"

#else // BUILDING_PHYSICS_STATIC

	namespace Physics
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_PHYSICS_STATIC