#include "../include_cheat.h"

long __stdcall hooks::present( IDirect3DDevice9* device, RECT* pSourceRect, RECT* pDestRect, HWND hDestWindowOverride, RGNDATA* pDirtyRegion )
{
	if ( g_unload )
		return orig_present( device, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion );

	IDirect3DStateBlock9* state = NULL;
	IDirect3DVertexDeclaration9* vertDec;
	IDirect3DVertexShader9* vertShader;
	device->CreateStateBlock( D3DSBT_PIXELSTATE, &state );
	device->GetVertexDeclaration( &vertDec );
	device->GetVertexShader( &vertShader );

	render::get().init( device );
	render::get().setup_render_state();

	visuals::get().render();
	c_menu::get().toggle();
	c_menu::get().render();

	state->Apply();
	state->Release();
	device->SetVertexDeclaration( vertDec );
	device->SetVertexShader( vertShader );

	return orig_present( device, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion );
}

