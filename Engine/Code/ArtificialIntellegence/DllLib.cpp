// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 10:07)

// 人工智能库（ArtificialIntellegence）位于引擎的第五层，
// 只允许调用引擎中的CoreTools、Mathematics、Physics、Imagics库，
// 并使用boost和stlsoft工具库。

// 人工智能库包含以下模块：
// 1.  Macro（宏）
// 2.  Miscellaneous（杂项）
// 3.  PathSearch（寻路）
// 4.  FiniteStateMachine（有限状态机）
// 5.  FuzzyStateMachine（模糊状态机）
// 6.  GeneticAlgorithm（遗传算法）
// 7.  NeuralNetwork（神经网络）

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegence/ArtificialIntellegence.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Physics/PhysicsLib.h"
#include "Imagics/ImagicsLib.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

	#include "DllLib.h"

#else // BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

	namespace ArtificialIntellegence
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC