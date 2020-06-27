// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 10:21)

// 资源管理库（ResourceManager）封装了引擎的资源管理。
// 资源管理库位于引擎的第四层，只允许调用引擎中的CoreTools库、Mathematics库，
// 并使用boost、stlsoft工具库。包含三维模型资源、纹理资源、材质资源、字体资源、骨骼资源、碰撞资源、物理参数和游戏世界和地图

// 资源管理库包含以下模块：
// 1.	Macro（宏）
// 2.	ThreeDimensionalModel（三维模型资源）
// 3.	Texture（纹理资源）
// 4.	Material（材质资源）
// 5.	Font（字体资源）
// 6.	Skeleton（骨骼资源）
// 7.	Collision（碰撞资源）
// 8.	PhysicalParameters（物理参数）
// 9.	GameWorldMap（游戏世界和地图）
// 10.	Miscellaneous（杂项）

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

	// 游戏编程精粹7 第1章 1.1 有资源管理算法