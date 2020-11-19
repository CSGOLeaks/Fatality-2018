#include "../include_cheat.h"

void __fastcall hooks::lock_cursor( void* ecx, void* )
{
	if ( c_menu::get().get_opened() )
	{
		g_pSurface->UnlockCursor();
		return;
	}
	
	orig_lock_cursor( ecx );
}