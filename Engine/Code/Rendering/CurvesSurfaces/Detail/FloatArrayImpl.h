// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:50)

#ifndef RENDERING_CURVES_SURFACES_FLOAT_ARRAY_IMPL_H
#define RENDERING_CURVES_SURFACES_FLOAT_ARRAY_IMPL_H
 
#include "Rendering/RenderingDll.h"

#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE FloatArrayImpl
	{
	public:
		using ClassType = FloatArrayImpl;
		using FloatVector = std::vector<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;

	public:
                FloatArrayImpl() noexcept;
		explicit FloatArrayImpl (const FloatVector& elements);	 

		CLASS_INVARIANT_DECLARE;
			
		void Load (BufferSource& source); 
		void Save (BufferTarget& target) const; 
		int GetStreamingSize () const;
				
		int GetNumElements () const;
                const float* GetData() const noexcept;
  
		const float& operator[] (int index) const;
		float& operator[] (int index);
		
	private:
		FloatVector m_Elements;
	};
}

#endif // RENDERING_CURVES_SURFACES_FLOAT_ARRAY_IMPL_H
