// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:38)

#ifndef FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// ��Ƶ������Ч������̣������򵥵���Ƶ�ط��Լ��ռ䶨λ���ܣ���
	class FRAMEWORK_DEFAULT_DECLARE AudioManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using AudioManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(AudioManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		AudioManagerInterface();
		virtual ~AudioManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource);

	private:
		IMPL_TYPE_DECLARE(AudioManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, AudioManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H

