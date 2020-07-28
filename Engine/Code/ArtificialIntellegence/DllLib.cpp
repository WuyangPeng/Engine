// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:07)

// �˹����ܿ⣨ArtificialIntellegence��λ������ĵ���㣬
// ֻ������������е�CoreTools��Mathematics��Physics��Imagics�⣬
// ��ʹ��boost��stlsoft���߿⡣

// �˹����ܿ��������ģ�飺
// 1.  Macro���꣩
// 2.  Miscellaneous�����
// 3.  PathSearch��Ѱ·��
// 4.  FiniteStateMachine������״̬����
// 5.  FuzzyStateMachine��ģ��״̬����
// 6.  GeneticAlgorithm���Ŵ��㷨��
// 7.  NeuralNetwork�������磩

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