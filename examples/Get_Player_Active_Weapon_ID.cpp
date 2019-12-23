int ReadActiveWeaponId(){
	int wi1;
	g_pEsp->ReadBytes((LPCVOID*)(entityPoint + g_pEsp->m_hActiveWeapon),4, &wi1); 
	wi1 &= 0xFFFF;
	int wi2;
	g_pEsp->ReadBytes((LPCVOID*)(g_pCsgo->client_dll_base + g_pEsp->dwEntityList + (wi1 - 1) * 0x10), 4, &wi2);
	int ActiveWeaponId;
	g_pEsp->ReadBytes((LPCVOID*)(wi2 + 12202), 4, &ActiveWeaponId);
	return ActiveWeaponId;
}
