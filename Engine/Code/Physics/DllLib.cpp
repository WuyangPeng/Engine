// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 14:44)

// 物理库（Physics）封装了引擎的物理模块。
// 网络库位于引擎的第四层，只允许调用引擎中的CoreTools和Mathematics库，并使用boost、stlsoft工具库。

// 物理库包含以下模块：
// 1.	Macro（宏）
// 2.	CollisionDetection（碰撞检测）
// 3.	Fluid（流体）
// 4.	Intersection（相交）
// 5.	LCPSolver（LCP求解）
// 6.	ParticleSystem（粒子系统）
// 7.	RigidBody（刚体）
// 8.	Miscellaneous（杂项）

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