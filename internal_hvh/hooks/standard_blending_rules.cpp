#include "../include_cheat.h"

void __fastcall hooks::standard_blending_rules( void* ecx, void* edx, CStudioHdr* hdr, Vector* pos, Quaternion *q, float curTime, int boneMask )
{
	auto player = static_cast< C_CSPlayer* >(ecx);

	player->get_effects() |= EF_NOINTERP;

	orig_standard_blending_rules(ecx, hdr, pos, q, curTime, boneMask);

	player->get_effects() &= ~EF_NOINTERP;
}