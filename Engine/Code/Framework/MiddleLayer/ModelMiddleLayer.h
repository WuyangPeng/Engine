// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:50)

// 模型层类的声明
#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(ModelMiddleLayerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ModelMiddleLayer : public ModelViewControllerMiddleLayer
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ModelMiddleLayer);
		using ParentType = ModelViewControllerMiddleLayer;

	public:
		ModelMiddleLayer();
		virtual ~ModelMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);	 		

		void ResetTime();
		std::string GetFrameRateMessage() const;
		void MeasureTime ();
		void UpdateFrameCount ();
		double GetFrameRate() const;
		
	private:
		IMPL_TYPE_DECLARE(ModelMiddleLayer);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ModelMiddleLayer);
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_H

