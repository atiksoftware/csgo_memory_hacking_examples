int GetClassID(){
	DWORD dwClientNetworkable;
	g_pEsp->ReadDword((LPCVOID*)(entityPoint + 0x8), &dwClientNetworkable);
	DWORD dwGetClientClassFn;
	g_pEsp->ReadDword((LPCVOID*)(dwClientNetworkable + 2 * 0x4), &dwGetClientClassFn);
	DWORD dwEntityClientClass;
	g_pEsp->ReadDword((LPCVOID*)(dwGetClientClassFn + 1), &dwEntityClientClass);
	int EntityClassId;
	g_pEsp->ReadInt((LPCVOID*)(dwEntityClientClass + 20), &EntityClassId);
	return EntityClassId;
}
