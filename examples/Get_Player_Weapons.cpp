// it will return weapons ids, not class id.
// silah id leri dönecektir. class id değil.
int* GetPlayerWeapons(){
	int playerWeaponIds[16];
	int wi1;
	int wi2;
	for(int i = 0; i < 16; i++){
		g_pEsp->ReadBytes((LPCVOID*)(entityPoint + g_pOffsets->m_hMyWeapons + (i * 0x4)), 4, &wi1);
		if(wi1 != 0xffffffff){
			wi1 &= 0xFFFF;
			g_pEsp->ReadBytes((LPCVOID*)(g_pCsgo->client_dll_base + g_pOffsets->dwEntityList + (wi1 - 1) * 0x10), 4, &wi2);
			g_pEsp->PlayersWeaponsPoints[g_pEsp->PlayersWeaponsPointsIndex++] = wi2;
			g_pEsp->ReadBytes((LPCVOID*)(wi2 + 12202), 4, &playerWeaponIds[i]);
		} else{
			playerWeaponIds[i] = 0;
		}

	}
}
