// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:36)

#ifndef RENDERING_DX9_RENDERER_DX9_RENDERER_DATA_H
#define RENDERING_DX9_RENDERER_DX9_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "Dx9RendererInput.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/WireState.h" 
#include "Rendering/Renderers/RendererData.h"

#include <Windows.h>
 
#include <d3d9.h>

namespace Rendering
{

	class Dx9RendererData
	{
	public:
		// Construction and destruction.
		Dx9RendererData(RendererInput& input, int width, int height,TextureFormat colorFormat, TextureFormat depthStencilFormat,int numMultisamples);

		~Dx9RendererData();

		// Support for construction, destruction, and device resetting.
		void CreateUniqueFont ();
		void DestroyUniqueFont ();
		void SetDefaultStates (const AlphaState* astate, const CullState* cstate,const DepthState* dstate, const OffsetState* ostate,const StencilState* sstate, const WireState* wstate);

		// Maintain current render states to avoid redundant state changes.
		class RenderState
		{
		public:
			RenderState ();

			void Initialize (IDirect3DDevice9* device, const AlphaState* astate,const CullState* cstate, const DepthState* dstate,
							 const OffsetState* ostate, const StencilState* sstate,const WireState* wstate);

			// AlphaState
			DWORD mAlphaBlendEnable;
			DWORD mAlphaSrcBlend;
			DWORD mAlphaDstBlend;
			DWORD mAlphaTestEnable;
			DWORD mAlphaFunc;
			DWORD mAlphaRef;
			D3DCOLOR mBlendFactor;

			// CullState
			DWORD mCullMode;

			// DepthState
			DWORD mZEnable;
			DWORD mZFunc;
			DWORD mZWriteEnable;

			// OffsetState
			DWORD mSlopeScaleDepthBias;
			DWORD mDepthBias;

			// StencilState
			DWORD mStencilEnable;
			DWORD mStencilFunc;
			DWORD mStencilRef;
			DWORD mStencilMask;
			DWORD mStencilWriteMask;
			DWORD mStencilFail;
			DWORD mStencilZFail;
			DWORD mStencilPass;

			// WireState
			DWORD mFillMode;
		};

		// Maintain current sampler states to avoid redundant state changes.
		enum
		{
			MAX_NUM_VSAMPLERS = 4,  // VSModel 3 has 4, VSModel 2 has 0.
			MAX_NUM_PSAMPLERS = 16  // PSModel 2 and PSModel 3 have 16.
		};

		class SamplerState
		{
		public:
			SamplerState ();

			float mAnisotropy;
			float mLodBias;
			DWORD mMagFilter;
			DWORD mMinFilter;
			DWORD mMipFilter;
			D3DCOLOR mBorderColor;
			DWORD mWrap[3];
		};

		// Platform-dependent data.
		IDirect3DDevice9* mDevice;
		HWND mWindowHandle;
		D3DPRESENT_PARAMETERS mPresent;
		//LPD3DXFONT mFont;
		bool mDeviceLost;

		// State data.
		RenderState mCurrentRS;
		SamplerState mCurrentVSState[MAX_NUM_VSAMPLERS];
		SamplerState mCurrentPSState[MAX_NUM_PSAMPLERS];

		// Capabilities (queried at run time).
		int mMaxVShaderImages;
		int mMaxPShaderImages;
		int mMaxTCoords;
	};

}

#endif // RENDERING_DX9_RENDERER_DX9_RENDERER_DATA_H
