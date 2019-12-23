int GetPlayerIsScoped(){ 
	int isScoped;
	g_pEsp->ReadInt((LPCVOID*)(entityPoint + g_pEsp->m_bIsScoped), &isScoped); 
	return isScoped;
}
