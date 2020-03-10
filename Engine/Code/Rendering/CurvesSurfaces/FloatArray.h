// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:55)

#ifndef RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H
#define RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(FloatArrayImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE FloatArray : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(FloatArray);
		using ParentType = Object;
		using FloatVector = std::vector<float>;

	public:
		explicit FloatArray(const FloatVector& data);
		virtual ~FloatArray();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(FloatArray); 

		int GetNumElements () const;
		const float* GetData () const;

		const float& operator[] (int index) const;
		float& operator[] (int index);

	private:
		IMPL_TYPE_DECLARE(FloatArray);
	};

	CORE_TOOLS_STREAM_REGISTER(FloatArray);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third,FloatArray);
}

#endif // RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H
