// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 10:48)

// �������߿⣨AssistTools��λ������ĵ����㣬
// ���������г���System��Framework�������⣬
// ��ʹ��boost��stlsoft���߿⡣

// �������߿��������ģ�飺
// 1.  Macro���꣩
// 2.  GenerateProjects��������Ŀ��
// 3.  FeaturesImporter���������룩
// 4.  BmpColorToGray����̬Bmp��ɫ��
// 5.  BmpToWmtf��Bmpת��Wmtf��
// 6.  WmfxCompiler��Wmfx��������

#include "AssistTools/AssistToolsExport.h"

#include "AssistTools/AssistTools.h"

#include "System/SystemLib.h"

#include "CoreTools/CoreToolsLib.h"

#include "Network/NetworkLib.h"
#include "Database/DatabaseLib.h"
#include "Script/ScriptLib.h"	
#include "Mathematics/MathematicsLib.h"	
#include "SoundEffect/SoundEffectLib.h"		
#include "InputOutput/InputOutputLib.h"		

#include "ResourceManager/ResourceManagerLib.h"		
#include "Rendering/RenderingLib.h"		
#include "Physics/PhysicsLib.h"		
#include "Imagics/ImagicsLib.h"		

#include "Animation/AnimationLib.h"		
#include "ArtificialIntellegence/ArtificialIntellegenceLib.h"		
#include "UserInterface/UserInterfaceLib.h"	

#ifndef BUILDING_ASSIST_TOOLS_STATIC

	#include "DllLib.h"

#else // BUILDING_ASSIST_TOOLS_STATIC

	namespace AssistTools
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_ASSIST_TOOLS_STATIC

